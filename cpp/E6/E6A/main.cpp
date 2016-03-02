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
const bool testrun = true;


struct gen {
    void run() {
        for (int i = 0; i < 100; ++i) {
            cout << rand() << " " << rand() << " = " << endl;

        }
    }
};


struct prog {


    void run() {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        ll m;
        cin >> m;
        vector<ll> b(n);
        for (int j = 0; j < m; ++j) {
            cin >> b[j];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if()
    }

};

void run_file(const char *in, const char *out) {
    freopen(in, "r", stdin);
    freopen(out, "w", stdout);
    do {
        int cl = clock();
        prog p;
        p.run();
        fprintf(stderr, "Execution time: %Lf \n", (long double) (clock() - cl) / CLOCKS_PER_SEC * 1000);
        cout << endl;
        string s;
        cout.flush();
        do cin >> s;
        while (s != "=" && !cin.eof());
    } while (!cin.eof());
    fclose(stdout);
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
        fclose(stdout);
    }
//    if (testrun)
//        run_file("in-test.txt", "out-test.txt");


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
