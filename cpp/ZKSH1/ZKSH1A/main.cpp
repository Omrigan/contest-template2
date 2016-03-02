#include <bits/stdc++.h>

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

struct prog {
    vector<vector<ll> > dp;

    ll get(ll a, ll b){
        if(a<0 || b<0)
            return 0;
        else
            return dp[a][b];
    }

    void run() {
        ll u, d, m;
        cin >> u >> d >> m;
        string s;
        cin >> s;
        set<char> set1;
        dp.resize(u, vector<ll> (d));
        for (char c : s) {
            set1.insert(c);
        }
        vector<vector<ll> > vec(u);
        for (int i = 0; i < u; ++i) {
            string s2;
            cin >> s2;

            for (char c: s2) {
                if (set1.find(c) == set1.end())
                    vec[i].push_back(0);
                else
                    vec[i].push_back(1);
            }
        }
        /*for (int k = 1; k < u; ++k) {
            dp[k][0] = dp[k-1][0] + vec[k][0];
        }*/
        if(vec[0][0]==1)
            dp[0][0] = 1;
        for (int k = 1; k < d; ++k) {
            dp[0][k] = dp[0][k - 1] + vec[0][k];
        }
        for (int j = 1; j < u; ++j) {
            for (int i = 0; i < d; ++i) {
                dp[j][i] = dp[j - 1][i];
                for (int k = 0; k <= i; k++)
                    dp[j][i] += vec[j][k];
            }
        }
        ld ans = 0;
        ll top = 0, bot = 0;

        for (int i = 0; i < u; ++i) {
            for (int j = 0; j < d; ++j) {
                for (int k = i + m-1; k < u; ++k) {
                    for (int l = j + m-1; l < d; ++l) {
                        ld cur = get(k, l) - get(k, j-1) - get(i-1, l) + get(i-1, j-1);
                        ld cur2 = (l - j+1) * (k - i+1);
                        ld cur3 = cur/cur2;
                        if(cur3>ans || (cur3==ans && cur2>bot)){
                            ans = cur3;
                            top = cur;
                            bot = cur2;
                        }

                    }
                }
            }
        }
        cout << top << "/" << bot;


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
