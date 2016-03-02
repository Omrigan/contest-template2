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

struct pt;

struct pt;

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
        ll n;
        cin >> n;
        cin >> p1.x >> p1.y;
        cin >> p2.x >> p2.y;
        vector<pt> pts;
        for (int i = 0; i < n; ++i) {
            pt p;
            cin >> p.x;
            cin >> p.y;
            pts.push_back(p);
        }
        sort(pts.begin(), pts.end(), cmp);
        ll ans = LINF;
        for (pt p : pts) {
            ll r1 = sqdist(p1, p);
            ll r2 = 0;
            for (pt ps : pts) {
                if (sqdist(p1, ps) > r1)
                    r2 = max(r2, sqdist(p2, ps));
            }
            ans = min(ans, r1 + r2);
        }

        cout << ans;

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
