#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll LINF = 1e18;
const int INF = 1e9;
const ld EPS = 1e-6;
const ll MOD = 1e9 + 7;

const string filename = "cond";


struct prog {

    void run() {
        ll n, m;
        cin >> n;
        vector<ll> clases;
        for (int i = 0; i < n; ++i) {
            ll a;
            cin >> a;
            clases.push_back(a);
        }
        cin >> m;
        vector<pair<ll, ll>> conders;
        for (int i = 0; i < m; ++i) {
            ll b, c;
            cin >> b >> c;
            conders.push_back(make_pair(b, c));
        }
        sort(clases.begin(), clases.end());
        sort(conders.begin(), conders.end());
        ll minp = LINF;
        for (auto it = conders.rbegin(); it != conders.rend(); ++it) {
            minp = min(minp, it->second);
            it->second = minp;
        }
        ll ans = 0;
        ll cur = 0;

        for (int j = 0; j < n; ++j) {
            while (conders[cur].first < clases[j])
                cur++;
            ans += conders[cur].second;
        }
        cout << ans;
    }

};


int main() {
    cin.sync_with_stdio(false);
    cout << fixed << setprecision(10);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int cl = clock();
    prog p;
    p.run();
    fprintf(stderr, "Execution time: %Lf \n", (long double) (clock() - cl) / CLOCKS_PER_SEC * 1000);
    cout << endl;


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
