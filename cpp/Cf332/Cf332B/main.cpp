#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll LINF = 1e18;
const int INF = 1e9;
const ld EPS = 1e-6;
const ll MOD = 1e9 + 7;

const string filname = "";


struct prog {

    void run() {

    }

};


int main() {


#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while (!cin.eof()) {
        int cl = clock();
        prog p;
        p.run();
        fprintf(stderr, "Execution time: %Lf \n", (long double) (clock() - cl) / CLOCKS_PER_SEC * 1000);
        cout << endl;
    }
#else
    if(filename!=""){
        freopen(filename + ".in", "r", stdin);
        freopen(filename + ".out", "w", stdout);
    }
    prog p;
    p.run();
#endif
    return 0;
}
