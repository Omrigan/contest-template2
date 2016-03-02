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

    struct pt {
        ll x, y;
        ll id;

        friend bool operator<(pt p1, pt p2) {
            return sqr(p1.y) + sqr(p1.x) < sqr(p2.y) + sqr(p2.x);
        }
    };

    ll vec(pt p, pt p1, pt p2) {
        return (p1.x - p.x) * (p2.y - p.y) - (p2.x - p.x) * (p1.y - p.y);
    }


    void run() {
        multiset<pt> pts;
        ll n;
        cin >> n;
        pt p0;
        cin >> p0.x >> p0.y;
        p0.id = 0;
        for (int i = 1; i < n; ++i) {

            pt p;
            p.id = i;
            cin >> p.x >> p.y;
            p.x -= p0.x;
            p.y -= p0.y;
            pts.insert(p);

        }
        pt p1 = *pts.begin();
        pts.erase(pts.begin());
        p1.x += p0.x;
        p1.y += p0.y;
        set<pt> pts2;
        for (pt p : pts) {
            p.x = p.x + p0.x - p1.x;
            p.y = p.y + p0.y - p1.y;
            pts2.insert(p);
        }
        pt p2;
        p1.x -= p0.x;
        p1.y -= p0.y;

        p0.x = 0;
        p0.y = 0;
        for (pt p : pts2) {
            if (vec(p0, p1, p) != 0) {
                p2 = p;
                break;
            }
        }
        cout << p0.id + 1 << " " << p1.id + 1 << " " << p2.id + 1;

//
//        cout << p0.x << " " << p0.y << endl;
//        cout << p1.x + p0.x << " " << p1.y + p0.y << endl;
//        cout << p2.x + p1.x << " " << p2.y + p1.y << endl;


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
