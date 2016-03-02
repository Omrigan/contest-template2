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
        ll h, w, n;
        cin >> h >> w >> n;
        char field[100][100];
        for (int k = 0; k < 100; ++k) {
            for (int i = 0; i < 100; ++i) {
                field[k][i] = '.';
            }
        }
        for (char i = 0; i < n; ++i) {
            ll r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            for (int j = r1; j <= r2; ++j) {
                field[j][c1] = field[j][c2] = 'a' + i;
            }
            for (int k = c1; k <= c2; ++k) {
                field[r1][k] = field[r2][k] = 'a' + i;
            }
        }
        for (int l = 0; l < h; ++l) {
            for (int i = 0; i < w; ++i) {
                cout << field[l+1][i+1];
            }
            cout << endl;
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
        while (s != "=\n" && !cin.eof());
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
