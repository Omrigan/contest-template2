#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll LINF = 1e18;
const int INF = 1e9;
const ld EPS = 1e-6;
const ll MOD = 1e9 + 7;

const string filename = "";
const int testgen = 100;
const bool testrun = false;

struct pt {
    ll x;
    ll y;


};

pt p1, p2;

constexpr ll sqr(ll a) {
    return a * a;
}

constexpr ll sqdist(pt p1, pt p2) {
    return sqr(p1.x - p2.x) + sqr(p1.y - p2.y);
}


bool cmp(pt pl1, pt pl2) {
    return sqdist(p1, pl1) < sqdist(p1, pl2);
}

struct prog {

    void run() {
        pt p1, p2, p3;
        cin >> p1.x >> p1.y;
        cin >> p2.x >> p2.y;
        cin >> p3.x >> p3.y;
        if ((p1.x == p2.x) && (p2.x == p3.x) || (p1.y == p2.y) && (p2.y == p3.y)) {
            cout << 1;
            return;
        }
        if ((p1.x == p2.x && (p3.y <= min(p1.y, p2.y) || p3.y >= max(p1.y, p2.y))) ||
            (p1.x == p3.x && (p2.y <= min(p1.y, p3.y) || p2.y >= max(p1.y, p3.y))) ||
            (p2.x == p3.x && (p1.y <= min(p3.y, p2.y) || p1.y >= max(p3.y, p2.y)))) {
            cout << 2;
            return;
        }
        ll tmp = p1.x;
        p1.x = p1.y;
        p1.y = tmp;

        tmp = p2.x;
        p2.x = p2.y;
        p2.y = tmp;

        tmp = p3.x;
        p3.x = p3.y;
        p3.y = tmp;
        if ((p1.x == p2.x && (p3.y <= min(p1.y, p2.y) || p3.y >= max(p1.y, p2.y))) ||
            (p1.x == p3.x && (p2.y <= min(p1.y, p3.y) || p2.y >= max(p1.y, p3.y))) ||
            (p2.x == p3.x && (p1.y <= min(p3.y, p2.y) || p1.y >= max(p3.y, p2.y)))) {
            cout << 2;
            return;
        }
        cout << 3;
        return;
    }


};

struct gen {
    void run() {
        for (int i = 0; i < 100; ++i) {
            cout << endl;
            cout << rand() << " " << rand() << endl;
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
