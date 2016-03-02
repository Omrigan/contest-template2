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


struct prog {

    vector<ll> cost;
    vector<vector<ll>> edges;
    vector<vector<ll>> revedges;
    vector<bool> used;

    vector<ll> tout;
    vector<ll> condens;
    vector<ll> comonents_cost;
    ll curc;

    bool dfs(ll v) {
        used[v] = true;
        for (auto v1 : edges[v]) {
            if (!used[v1]) {
                dfs(v1);
            }
        }
        tout.push_back(v);
    }

    bool dfs2(ll v) {
        used[v] = true;
        for (ll v1 : revedges[v]) {
            if (!used[v1]) {
                dfs2(v1);
            }
        }
        condens[v] = curc;
        comonents_cost[curc] += cost[v];
    }


    void run() {
        ll n, m;
        cin >> n >> m;
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            ll a;
            cin >> a;
            sum += a;
            cost.push_back(a);
        }
        edges.resize(n + 10);
        revedges.resize(n + 10);
        used.resize(n + 10);
        condens.resize(n + 10);
        comonents_cost.resize(n + 10);
        curc = 0;

        for (int j = 0; j < m; ++j) {
            ll w, l;
            cin >> w >> l;
            w -= 1;
            l -= 1;
            edges[l].push_back(w);
            revedges[w].push_back(l);
        }
        used.assign(n + 10, false);

        for (int k = 0; k < n; ++k) {
            if (!used[k])
                dfs(k);
        }
        used.assign(n + 10, false);
        for (auto it = tout.rbegin(); it != tout.rend(); ++it) {
            if (!used[*it]) {
                dfs2(*it);
                curc++;
            }
        }
        vector<bool> istocks(curc);
        istocks.assign(curc, true);
        for (ll v0 = 0; v0 < n; v0++) {
            for (ll v : edges[v0]) {
                if (condens[v] != condens[v0])
                    istocks[condens[v]] = false;
            }
        }
        ll ans = LINF;
        for (int i1 = 0; i1 < curc; ++i1) {
            if (istocks[i1])
                ans = min(ans, comonents_cost[i1]);
        }
        cout << sum - ans;
    }

};


struct gen {
    void run() {
        for (int i = 0; i < 100; ++i) {


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
