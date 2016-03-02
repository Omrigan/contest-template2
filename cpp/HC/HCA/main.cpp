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


struct prog {

    void run() {
        ll T;
        cin >> T;
        for (int i = 0; i < T; ++i) {
            ll N;
            cin >> N;
            string A, B;
            cin >> A >> B;
            N = A.length();
            vector<ll> Dp(N + 1), Ds(N + 1);
            char lp = -1;
            ll curans = 0;
            for (int j = 0; j < N; ++j) {//Добавляем символ j в динамику
                if (B[j] != lp) {
                    lp = B[j];
                    curans++;
                }
                Dp[j + 1] = curans;
            }
            lp = -1;
            curans = 0;
            for (int k = N - 1; k >= 0; --k) {
                if (B[k] != lp) {
                    lp = B[k];
                    curans++;
                }
                Ds[N - k] = curans;
            }
            ll ans = LINF;
            ll curl = 0;
            for (int l = 0; l < N; ++l) {
                if (A[l] == B[l]) {
                    curl++;
                } else {
                    ans = min(ans, max(Dp[l - curl], Ds[N - l]));
                    curl = 0;
                }
            }
            ans = min(ans, max(Dp[N - curl], Ds[0]));
            cout << "Case #" << i + 1 << ": " << ans << endl;


        }


    }
};


struct gen {
    void run() {
        for (int i = 0; i < 100; ++i) {


            cout << "=";
        }
    }
};

void run_file(const char *in, const char *out) {
    freopen(in, "r", stdin);
    freopen(out, "w", stdout);
    while (!cin.eof()) {
        int cl = clock();
        prog p;
        p.run();
        fprintf(stderr, "Execution time: %Lf \n", (long double) (clock() - cl) / CLOCKS_PER_SEC * 1000);
        cout << endl << "=" << endl;

        cout.flush();
        string s;
        do cin >> s;
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
