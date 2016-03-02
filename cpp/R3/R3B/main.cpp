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
    bool check(ll a) {
        auto s = to_string(a);
        bool nechet = false;
        for (char c : s) {
            if ((c - '0') % 2 != 0)
                nechet = !nechet;
        }
        return !nechet;
    }

    ll stress(ll a, ll b) {
        ll ans = 0;
        for (ll i = a; i <= b; ++i) {
            if (check(i))
                ans++;
        }
        return ans;
    }


    void run() {
        string a, b;
        ll a2[30], b2[30];
        cin >> a >> b;
        bool necheta = false, nechetb = false;
        for (int i = 0; i < 30; ++i) {
            if (i < a.size())
                a2[i] = a[a.size() - 1 - i] - '0';
            else
                a2[i] = 0;

            if (i < b.size())
                b2[i] = b[b.size() - 1 - i] - '0';
            else
                b2[i] = 0;
            if (i > 0) {
                if (a2[i] % 2 != 0)
                    necheta = !necheta;
                if (b2[i] % 2 != 0)
                    nechetb = !nechetb;
            }

        }
        vector<bool> sim(35);
        sim[30] = true;
        for (int j = 29; j >= 0; --j) {
            sim[j] = sim[j + 1] && a2[j] == b2[j];
        }

        ld ans = 0;
        if (sim[1]) {
            for (int i = a2[0]; i <= b2[0]; ++i) {
                if ((i % 2 == 0) ^ necheta) {
                    ans++;
                }
            }
        } else {
            for (int i = a2[0]; i <= 9; ++i) {
                if ((i % 2 == 0) ^ necheta) {
                    ans++;
                }
            }
            for (int i = 0; i <= b2[0]; ++i) {
                if ((i % 2 == 0) ^ nechetb) {
                    ans++;
                }
            }
        }
        for (int k = 1; k < 28; ++k) {
            if (sim[k + 1]) {

                for (int i = a2[k] + 1; i < b2[k]; ++i) {
                    ans += pow(10ll, k - 1) * 5;
                }
            } else {
                for (int i = a2[k] + 1; i <= 9; ++i) {
                    ans += pow(10ll, k - 1) * 5;
                }
                for (int i = 0; i < b2[k]; ++i) {
                    ans += pow(10ll, k - 1) * 5;
                }
            }
        }
        /* ll st = stress(atoi(a.c_str()), atoi(b.c_str()));
         if (st != ans)
             cout << "DANGER S" << st << endl;
 */
        cout << ans;

    }
};


struct gen {
    void run() {
        for (int i = 0; i < 100; ++i) {
            ll a = rand() % 10000;
            ll b = a + rand() % 10000;
            cout << a << " " << b << endl;
            cout << "=" << endl;
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
    cout << fixed << setprecision(0);
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
