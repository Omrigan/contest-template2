#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll LINF = 1e18;
const ll INF = 1e9;
const ld EPS = 1e-6;
const ll MOD = 1e9 + 7;

const string filename = "volunteers";


struct prog {
    struct event {
        ll cor;
        bool open;
        bool sci;
        ll id;

        friend bool operator<(event e1, event e2) {
            return e1.cor < e2.cor || (e1.cor == e2.cor && e1.open);
        }
    };


    void run() {
        ll n, m, k;
        cin >> n >> m >> k;
        vector<pair<ll, ll>> sci(m);
        vector<pair<ll, ll>> tech(k);
        for (ll j = 0; j < m; ++j) {
            sci[j] = make_pair(INF, -INF);
        }
        for (ll j = 0; j < k; ++j) {
            tech[j] = make_pair(INF, -INF);
        }
        for (ll i = 0; i < n; ++i) {
            ll a, b;
            cin >> a >> b;
            a--;
            b--;
            sci[a].first = min(sci[a].first, i);
            sci[a].second = max(sci[a].second, i);
            tech[b].first = min(tech[b].first, i);
            tech[b].second = max(tech[b].second, i);
        }
        for (ll j = 0; j < m - 1; ++j) {
            ll c;
            cin >> c;
            c--;
            sci[c].first = min(sci[j].first, sci[c].first);
            sci[c].second = max(sci[j].second, sci[c].second);
        }
        for (ll j = 0; j < k - 1; ++j) {
            ll c;
            cin >> c;
            c--;
            tech[c].first = min(tech[j].first, tech[c].first);
            tech[c].second = max(tech[j].second, tech[c].second);
        }
        vector<event> events;
        for (int l = 0; l < m; ++l) {
            if (sci[l].first != INF) {

                event e1;
                e1.cor = sci[l].first;
                e1.open = true;
                event e2;
                e2.cor = sci[l].second;
                e2.open = false;

                e2.id = e1.id = l;
                e2.sci = e1.sci = true;
                events.push_back(e1);
                events.push_back(e2);
            }
        }
        for (int i1 = 0; i1 < k; ++i1) {
            if (tech[i1].first!=INF) {

                event e1;
                e1.cor = tech[i1].first;
                e1.open = true;
                event e2;
                e2.cor = tech[i1].second;
                e2.open = false;

                e2.id = e1.id = i1;
                e2.sci = e1.sci = false;
                events.push_back(e1);
                events.push_back(e2);
            }
        }
        sort(events.begin(), events.end());
        vector<ll> scie_met(m);
        vector<ll> tech_met(k);
        ll sci_open = 0, tech_open = 0;
        ll sci_open_all = 0, tech_open_all = 0;
        ll ans = 0;
        for (event e : events) {
            if (e.open) {
                if (e.sci) {
                    ans += tech_open;
                    sci_open++;
                    sci_open_all++;
                    scie_met[e.id] = tech_open_all;
                } else {
                    ans += sci_open;
                    tech_open++;
                    tech_open_all++;
                    tech_met[e.id] = sci_open_all;
                }
            } else {
                if (e.sci) {
                    ans += tech_open_all - scie_met[e.id];
                    sci_open--;
                } else {
                    ans += sci_open_all - tech_met[e.id];
                    tech_open--;
                }
            }
        }
        cout << ans/2;

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
