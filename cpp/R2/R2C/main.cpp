#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll LINF = 1e18;
const int INF = 1e9;
const ld EPS = 1e-3;
const ll MOD = 1e9 + 7;

const string filename = "sweets";


struct gen {
    void run() {
        for (int i = 0; i < 1e5; ++i) {
            cout << rand() % 1000 << endl;
            cout << rand() % 100 << " " << rand() % 100 << " " << rand() % 100 << endl;
            cout << "=" << endl;
        }
    };
};


struct prog {

    ll a, b, c, N;


    ll getmaxk3(ll k1, ll k2) {
        return (N - k2 * b - k1 * a) / c;
    }

    ll getmaxk2(ll k1) {
        return (N - k1 * a) / b;
    }


    ll check(ll k1, ll k2) {
        ll k3 = getmaxk3(k1, k2);
        return k1 * k2 * k3;
    }

    ll threesearch2(ll k1, ll min, ll max) {

        while (max - min >= 3) {
            ll step = (max - min) / 3;
            ll val1 = min + step, val2 = max - step;
            ll c1 = check(k1, val1), c2 = check(k1, val2);
            if (c1 < c2) {
                min = val1;
            } else {
                max = val2;
            }
        }
        set<pair<ll, ll>> s;
        while (min != max + 1) {
            s.insert(make_pair(check(k1, min), min));
            min++;
        }
        return s.begin()->second;
    }

    ll perebor(ll k1, ld min, ld max) {
        ll ret = min, maxval = 0;
        for (int i = min; i <= max; ++i) {
            if (maxval < check(k1, i)) {
                ret = i;
                maxval = check(k1, i);
            }
        }
        return ret;
    }

    void run() {
        cin >> N >> a >> b >> c;

        ll curmax = 0;
        ll ans[3];
        for (int i = 0; i <= N / a; ++i) {
            ll k2 = threesearch2(i, 1, getmaxk2(i));
            //ll k2 = perebor(i, 1, getmaxk2(i));
           // if (k2 != k22 && curmax != 0) {
         //       cout << "DANGER!!";
           //     cout << "Per" << check(i, k2) << " Three" << check(i, k22) << endl;
            //}
            if (check(i, k2) > curmax) {
                curmax = check(i, k2);
                ans[0] = i * a;
                ans[1] = k2 * b;
                ans[2] = getmaxk3(i, k2) * c;
            }
        }

        for (int j = 0; j < 3; ++j) {
            if (curmax == 0)
                cout << 0 << " ";
            else
                cout << ans[j] << " ";
        }

    }

};


int main() {
    cin.sync_with_stdio(false);
    cout << fixed << setprecision(10);

#ifdef DEBUG

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    do {
        int cl = clock();
        prog p;
        p.run();
        fprintf(stderr, "Execution time: %Lf \n", (long double) (clock() - cl) / CLOCKS_PER_SEC * 1000);
        cout << endl;
        string s;
        cout.flush();
        do {
            cin >> s;
        } while (!cin.eof() && s != "=");
    } while (!cin.eof());

    freopen("test1.txt", "w", stdout);
    gen g;
    g.run();

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