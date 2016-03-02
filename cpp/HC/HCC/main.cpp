#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll LINF = 1e18;
const int INF = 1e9;
const ld EPS = 1e-6;
const ll MOD = 1e9 + 7;

const string filename = "";
const bool testgen = true;
const bool testrun = true;


struct prog {


    ll add(ll a, ll b) {
        return (a + b) % MOD;
    }

    ll mult(ll a, ll b) {
        return (a * b) % MOD;
    }

    ll subs(ll a, ll b) {
        return ((a - b) % MOD + MOD) % MOD;
    }

    void run() {
        ll T;
        cin >> T;
        for (int i = 0; i < T; ++i) {
            ll N;
            cin >> N;
            map<ll, set<ll>> m;
            set<ll> badXs;
            for (int j = 0; j < N; ++j) {
                ll X, H;
                cin >> X >> H;
                //if (m.find(H) == m.end())
                m[H].insert(X);
            }
            ll ans = 0;
            for (auto it = m.rbegin(); it != m.rend(); ++it) {
                auto p = *it;
                set<ll> s = p.second;
                ll prev = *s.begin();
                vector<ll> a;
                badXs.insert(prev);
                for (ll si : s) {
                    if (si != prev) {
                        badXs.insert(si);
                        if (*badXs.upper_bound(prev) == si)
                            a.push_back(si - prev);

                    }
                    prev = si;
                }
                /*for (int j = 0; j < a.size(); ++j) {
                    for (int k = j; k < a.size(); ++k) {
                        ll coef = mult((j + 1), (a.size() - k)), prod = mult(a[j], a[k]);
                        if (j != k)
                            coef = mult(coef, 2);
                        ans = add(ans, mult(coef, prod));
                    }
                }*/
                vector<ll> Ds(a.size() + 1);
                Ds[a.size()] = 0;
                for (int j = a.size() - 1; j >= 0; --j) {//Добавляем j в наш подсчет
                    Ds[j] = Ds[j + 1] + a[j] * (a.size() - j);
                }
                for (int k = 0; k < a.size(); ++k) {
                    ll kth = mult((k + 1), a[k]), prod = subs(mult(2, Ds[k]), mult(a.size() - k, a[k]));
                    ans = add(ans, mult(kth, prod));
                }

            }
            cout << "Case #" << i + 1 << ": " << ans << endl;
        }


    }
};


struct gen {
    void run() {
        cout << 1 << endl;
        for (int i = 0; i < 1; ++i) {
            ll N = 200 * 100;
            cout << N << endl;
            for (int j = 0; j < N; ++j) {
                cout << rand() % MOD << " " << MOD / 2 << endl;
            }
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
