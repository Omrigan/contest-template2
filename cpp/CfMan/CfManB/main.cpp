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
        ll m, twos = 0, fivs = 0;
        cin >> m;
        ll minans = -1;
        ll cur = 1;
        while (min(twos, fivs) <= m) {

            ll cur2 = cur;

            while (cur2 % 2 == 0) {
                twos++;
                cur2 /= 2;

            }
            while (cur2 % 5 == 0) {
                fivs++;
                cur2 /= 5;
            }
            if (min(twos, fivs) == m && minans == -1)
                minans = cur;
            cur++;
        }
        if (minans == -1) {
            cout << 0;
            return;
        }
        cout << cur - 1 - minans << endl;
        for (int i = minans; i < cur - 1; ++i) {
            cout << i << " ";
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
