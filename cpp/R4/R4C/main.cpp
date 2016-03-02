#include "iostream"
#include "cstring"
#include "map"
#include "set"
#include "algorithm"
#include "vector"
#include "iomanip"
#include "math.h"


#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll LINF = 1e18;
const int INF = 1e9;
const ld EPS = 1e-6;
const ll MOD = 1e9 + 7;

const string filename = "";
const bool testgen = false;
const bool testrun = false;

template<class T>
T sqr(T x) { return x * x; }

const int MAX_N = 700;
constexpr int sz = (int) log(MAX_N) + 1;

struct prog {
    ll n, k;
    vector<ll> vec;
    ll sparse[MAX_N][sz];


    void build_sparse() {
        for (int i = 0; i < n; ++i) {
            sparse[i][0] = vec[i];

        }
        ll prevstep = 1;
        for (int j = 1; j < sz; ++j) {
            for (int i = 0; i < n; ++i) {
                sparse[i][j] = min(sparse[i][j - 1], sparse[i + prevstep][j - 1]);
            }
            prevstep *= 2;
        }

    }


    ll mymin(ll l, ll r) {
        ll step = 1;
        ll mylog = 0;
        ll lim = (r - l) / 2;
        if((r-l)%2==0)
            lim++;
        while (step < lim) {
            step *= 2;
            mylog++;
        }
        ll ret =  min(sparse[l][mylog], sparse[r - step+1][mylog]);
        return ret;
    }

    void run() {
        cin >> n >> k;
        k--;
        pair<ll, ll> dp[MAX_N][MAX_N];

        for (int i = 0; i < n; ++i) {
            ll a;
            cin >> a;
            vec.push_back(a);
        }
        build_sparse();
        dp[0][0] = mp(0, -1);
        for (int l = 1; l < n; ++l) {
            dp[0][l] = mp(0, -1);
        }
        for (int m = 1; m <= n; ++m) {
            dp[m][0] = mp(mymin(0, m-1), -1);
            for (int i = 1; i <= k; ++i) {
                dp[m][i] = mp(-INF, -1);
                for (int j = 0; j < (m); ++j) {
                    ll cur = dp[j][i - 1].first + mymin(j, m-1  );
                    if (cur >= dp[m][i].first) {
                        dp[m][i].first = cur;
                        dp[m][i].second = j;
                    }
                }
            }
        }

        vector<ll> anses;
        ll cur = dp[n][k].second;
        for (int i1 = 0; i1 < k; ++i1) {
            anses.pb(cur);
            cur = dp[cur][k - i1 - 1].second;
        }

        reverse(anses.begin(), anses.end());

        cout << dp[n][k].first << endl;
        for (ll r : anses) {
            cout << r << " ";
        }
    }
};


struct gen {
    void run() {
        for (int i = 0; i < 100; ++i) {

            cout << "=" << endl;
        }
    }
};

void run_file(const char *in, const char *out) {
    freopen(in, "r", stdin);
    freopen(out, "w", stdout);
    while (!cin.eof()) {
        ll cl = clock();
        prog p;
        p.run();
        fprintf(stderr, "Execution time: %Lf \n", (long double) (clock() - cl) / CLOCKS_PER_SEC * 1000);
        cout << endl << "=" << endl;

        cout.flush();
        string s;
        do getline(cin, s);
        while (s != "=" && !cin.eof());
    }
    cin.clear();
    cout.clear();
}


int main() {
    cin.sync_with_stdio(false);
    cout << fixed << setprecision(10);
#ifdef DEBUG
    run_file("input.txt", "output.txt");
    if (testgen) {
        freopen("in-test.txt", "w", stdout);
        gen gen1;
        gen1.run();
        cout.flush();
    }
    if (testrun)
        run_file("in-test.txt", "out-test.txt");


#else
    if(filename.compare("")){
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
    prog p;
    p.run();
#endif
    return 0;
}
