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

    void run() {
        ll n;
        cin >> n;
        unordered_map<ll, ll> a;
        vector<ll> azaza;
        for (int i = 0; i < n; ++i) {
            ll kek;
            cin >> kek;
            a[kek]++;
            azaza.push_back(kek);
        }
        ll ans = 0;
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {

                if (i != j) {
                    if(azaza[i]==0 && azaza[j]==0){
                        ans = max(ans, a[0]);
                        continue;
                    }
                    unordered_map<ll, ll> var1;
                    var1[azaza[i]]++;
                    var1[azaza[j]]++;
                    long long xui = azaza[i];
                    long long chlen = azaza[j];
                    long long pisun;
                    long long popa = 2;
                    while (var1[xui + chlen] + 1 <= a[xui + chlen]) {
                        pisun = xui + chlen;
                        xui = chlen;
                        chlen = pisun;
                        var1[pisun]++;
                        popa++;
                    }
                    ans = max(ans, popa);

                }
            }
        }
        cout << ans;


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
