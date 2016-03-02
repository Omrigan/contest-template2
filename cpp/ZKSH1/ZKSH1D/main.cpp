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
        set<ll> super_ans;
        ll N;
        cin >> N;
        ll lim = sqrt(N)+1;
        for (int i = 1; i < lim; ++i) {
            ll b = N/i - 1;
            if(N%i==0 && i<b)
                super_ans.insert(b);
        }
        lim = sqrt(N) + 1;
        for (int j = 2; j < lim; ++j) {
            vector<ll> num;
            ll cur_s = 1;
            while(cur_s<=N)
                cur_s*=j;
            cur_s/=j;
            ll N2= N;
            while(cur_s>=1){
                ll cur = N2/cur_s;
                num.push_back(cur);
                N2-=cur_s*cur;
                cur_s/=j;
            }
            bool pal = true;
            for (int i = 0; i < num.size()/2; ++i) {
                pal &= num[i]==num[num.size()-i-1];
            }
            if(pal && num.size()>1){
                super_ans.insert(j);
                /*cout << j << " ";
                for(ll a: num)
                    cout <<  '(' << a << ')';
                cout << endl;*/
            }

        }
        //sort(super_ans.begin(),super_ans.end());
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
