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

    void run() {
        string S, S2;
        ll N;
        cin >> S >> N;
        S2 = S;
        reverse(S2.begin(), S2.end());
        //Light part
        set<string> prev;
        ll len = 0;
        if (N % 2 == 0)
            prev.insert("");
        else {
            if (S != "A")
                prev.insert("A");
            if (S != "B")
                prev.insert("B");
            len = 1;
        }
        if (len == N) {
            cout << prev.size();
            return;

        }
        for (int i = 0; i <= 7; ++i) {
            set<string> nxt;
            for (string str1 : prev) {
                string str = "A" + str1 + "A";
                if (str.find(S) == str.npos) {
                    nxt.insert(str);
                };
                str = "B" + str1 + "B";
                if (str.find(S) == str.npos) {
                    nxt.insert(str);
                };
            }
            prev = nxt;

            len += 2;
            if (len == N) {
                cout << nxt.size();
                return;
            }
        }
        map<string, ll> cur;
        for (string str1 : prev) {
            string str = str1.substr(str1.size() - 5, 5);
            if (cur.find(str) == cur.end())
                cur[str] = 0;
            cur[str] += 1;
        }

        while (len < N) {
            map<string, ll> nxt;
            for (auto p : cur) {
                string str = p.first.substr(1, 4) + "A";
                if (str.find(S) == str.npos && str.find(S2) == str.npos) {
                    if (nxt.find(str) == nxt.end())
                        nxt[str] = 0;
                    nxt[str] += p.second;
                }
                str = p.first.substr(1, 4) + "B";
                if (str.find(S) == str.npos && str.find(S2) == str.npos) {
                    if (nxt.find(str) == nxt.end())
                        nxt[str] = 0;
                    nxt[str] += p.second;
                }
            }
            len += 2;
            cur = nxt;
        }
        ld ans = 0;
        for (auto p : cur) {
            ans += p.second;
        }
        cout << ans;

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
    cout << fixed << setprecision(0);
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
