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

    struct node {
        vector<int> next;
        int leaf;
        int prev;

        node() {
            next.resize(32, -1);
            leaf = -1;
            prev = -1;
        }
    };

    vector<node> bor;
    ll ans = 0;
    ll last = -1;

    void dfs(ll cur, ll ans2) {
        if (bor[cur].leaf!=-1)
            ans2++;
        if (ans2 > ans) {
            ans = ans2;
            last = cur;
        }
        for (int i = 0; i < 32; ++i) {
            if (bor[cur].next[i] != -1)
                dfs(bor[cur].next[i], ans2);
        }
    }

    void run() {
        ll N;
        cin >> N;
        node n;
        bor.push_back(n);
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            ll cur = 0;
            for (char c : s) {
                c-='a';
                if (bor[cur].next[c] == -1) {
                    node n2;
                    n2.prev = cur;
                    bor.push_back(n2);
                    bor[cur].next[c] = bor.size() - 1;
                }
                cur = bor[cur].next[c];
            }
            bor[cur].leaf = i+1;
        }
        dfs(0, 0);
        vector<int> super_ans;
        while (last != 0) {
            if (bor[last].leaf != -1)
                super_ans.push_back(bor[last].leaf);
            last = bor[last].prev;
        }
        reverse(super_ans.begin(), super_ans.end());
        cout << super_ans.size() << endl;
        for(ll a : super_ans)
            cout << a << " ";


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
