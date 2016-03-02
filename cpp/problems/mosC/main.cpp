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

struct node {
    int parent;
    int link;
    int lvl;
    int last;
    vector<pair<int, int>> children;

    node() {
        link = 0;
        parent = 0;
        last = -1;
    }
};


struct prog {
    vector<node> tree;
    set<string> left;

    /*void build(int last, int lvl){
        node n;
        tree.push_back(n);
        n.lvl = lvl;
        n.last = last;
        if(lvl==0)
            return;
        for (int i = 0; i < 3; ++i) {
            n.children.push_back(make_pair(i, tree.size()));
            build(i, lvl-1);
        }
    }
    int link(int v){
        if(tree[v].link!=-1)
            return tree[v].link;
        int ans;
        if(v==0)
            ans = 0;
        else if(tree[v].parent==0)
            ans= 0;
        else {
            ans = link(tree[v].parent)
        }
    }*/
    void run() {
        srand(time(0));
        // build(-1, 11);
        int cur = 0;
        string seq;

        ll len = 4;
        ll lim = 10;



        ll times = 1;
        string minseq;
        ll minans = 1e8;
        for (int k = 0; k < times; ++k) {
            seq = "";
            left.erase(left.begin(), left.end());
            for (int i = 0; i < lim; ++i) {
                left.insert(to_string(i));
            }
            for (int j = 1; j < len; ++j) {
                set<string> nxt;
                for (string s : left) {
                    for (int i = 0; i < lim; ++i) {
                        string s2 = s;
                        s2 += to_string(i);
                        nxt.insert(s2);
                    }
                }
                left = nxt;
            }
            string last = "1";
            while (!left.empty()) {
                set<string>::iterator it;
                do {
                    last = last.substr(1);
                    it = left.lower_bound(last);

                } while (it == left.end() || (*it).find(last) != 0);

                vector<set<string>::iterator> fits;

                while (it != left.end() && (*it).find(last) == 0) {
                    fits.push_back(it);
                    ++it;
                }
                ll n = min(9, (int) fits.size()-1);//rand() % fits.size();
                auto cur = fits[n];
                for (int i = last.size(); i < len; ++i) {
                    seq.push_back((*cur)[i]);
                }
                if(seq.length()>=minans)
                    break;
                last = (*cur);
                left.erase(cur);
                //cout << *cur << endl;
            }
            if(seq.length()<minans){
                minseq = seq;
                minans = seq.length();
            }
        }

        cout << "HURRAY " << minseq.size() << " " << minseq;
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
        while (s != "=\n" && !cin.eof());
    }
    cin.clear();
    cout.clear();
}


int main() {
    cin.sync_with_stdio(false);
    cout << fixed << setprecision(10);
    srand(time(0));
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
