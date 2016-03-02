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
        ll t;
        cin >> t;
        for (int i = 0; i < t; ++i) {
            map<ll, set<ll> > graph;
            ll N;
            cin >> N;
            const set<ll> clr;
            set<ll> all;


            for (int j = 0; j < N; ++j) {
                ll l;
                cin >> l;
                ll prev;
                cin >> prev;
                all.insert(prev);
                for (int k = 1; k < l; ++k) {
                    ll cur;
                    cin >> cur;
                    all.insert(cur);
                    if (graph.find(prev) == graph.end())
                        graph[prev] = clr;
                    //istocks.erase(cur);

                    graph[prev].insert(cur);
                    prev = cur;
                }
            }

            ll cnt = 0;
            queue<ll> istocks_q;
            map<ll, ll> left_in;
            for (auto p : graph) {
                for (ll e : p.second) {
                    if (left_in.find(e) == left_in.end())
                        left_in[e] = 0;
                    left_in[e]++;
                }
            }
            for (auto a : all) {
                if (left_in.find(a)==left_in.end()){
                    istocks_q.push(a);
                    cnt++;
                }

            }
            while (istocks_q.size() > 0) {

                ll cur = istocks_q.front();
                istocks_q.pop();
                for (ll nxt : graph[cur]) {
                    left_in[nxt]--;
                    if (left_in[nxt] == 0) {
                        istocks_q.push(nxt);
                        cnt++;
                    }

                }
            }
            if (cnt == all.size())
                cout << "Yes" << endl;
            else
                cout << "No" << endl;



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
