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

    ll cnt = 0;
    int get(){
        int N;
        //scanf("%d", &N);
        cin >> N;
       /* cnt++;
        if(cnt<1e6)
            return 1+(cnt%65535);
        else
            return 0;*/

        return N;
    }


    void run() {
        ll N;
        ll ans = 0;
        ll cur_len = 0;
        vector<ll> last(65535 + 100, -1);
        queue<ll> seq;
        queue<ll> lon_seq;
        ll cur = 0;
        N = get();
        while (N != 0) {
            if (last[N] != -1)
            if (cur_len > ans) {
                ans = cur_len;
                lon_seq = seq;
            }
            cur++;
            cur_len++;
            seq.push(N);
            if (last[N] != -1) {

                cur_len = min(cur - last[N], cur_len);

            }
            last[N] = cur;
            while (seq.size() > cur_len)
                seq.pop();

            N = get();
        }
        if (cur_len > ans) {
            ans = cur_len;
            lon_seq = seq;
        }
        // cout << ans << endl;
        while (lon_seq.size() > 0) {
            cout << lon_seq.front() << endl;
            lon_seq.pop();
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
    ios_base::sync_with_stdio(false);
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
