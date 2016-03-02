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

    map<ll, ll> map1;

    void insert(ll key, ll val) {
        if (map1.find(key) == map1.end())
            map1[key] = 0;
        map1[key] += val;
    }

    void run() {
        ll T;
        cin >> T;
        for (int j = 0; j < T; ++j) {
            map1.erase(map1.begin(), map1.end());
            ll a, b, n, s = 0;
            cin >> n >> a >> b;
            vector<ll> c;
            for (int i = 0; i < n; ++i) {
                ll tmp;
                cin >> tmp;
                s += tmp;
                c.push_back(tmp);
            }
            ll cur = a - a % s;

            for (int k = 0; k < n; ++k) {
                cur += c[k];
                if (a < cur && cur < b) {
                    if (cur - a < c[k])
                        insert(2 * c[k] - (cur - a), cur - a);
                    else
                        insert(c[k], c[k]);
                }
            }
            ll cnt = (b - cur) / s;
            for (int k = 0; k < n; ++k) {
                insert(c[k], cnt * c[k]);
            }
            cur += s * cnt;
            for (int k = 0; k < n; ++k) {
                if (cur < b) {
                    if (b - cur < c[k])
                        insert(b - cur, b - cur);
                    else
                        insert(c[k], c[k]);
                }
                cur += c[k];
            }
            ll allsum = 0;
            for (auto p : map1) {
                allsum += p.second;
            }
            ld ans = 0;
            for (auto p : map1) {
                ans += (ld) p.first * (ld) p.second / (ld) allsum;
            }
            cout << "Case #" << j + 1 << ": ";
            if (allsum == 0) {
                cout << ((ld) b + a) / 2 << endl;
            }
            else {
                cout << ans / 2 << endl;
            }


        }

    }

};


int main() {


#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin.sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int cl = clock();
    prog p;
    p.run();
    fprintf(stderr, "Execution time: %Lf \n", (long double) (clock() - cl) / CLOCKS_PER_SEC * 1000);
    cout << endl;

#else
    prog p;
    p.run();
#endif
    return 0;
}
