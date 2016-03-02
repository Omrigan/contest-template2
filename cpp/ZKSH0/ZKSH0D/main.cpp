#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll LINF = 1e18;
const int INF = 1e9;
const ld EPS = 1e-3;
const ll MOD = 1e9 + 7;

const string filename = "";
const bool testgen = false;
const bool testrun = false;

template<class T>
T sqr(T x) { return x * x; }

struct prog {

    ll best = 1e18;

    void perebor(vector<ld> nums) {
        if (
            nums.size() == 1 &&
            (abs(nums[0] - 21) < abs(best - 21)
             || (abs(nums[0] - 21) == abs(best - 21) && nums[0] < best))
                                                   && abs(floor(nums[0]) - nums[0]) < EPS)
        {
            best = (ll) floor(nums[0]);
        }

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i != j) {


                    auto numsnxt = nums;
                    numsnxt[i] = (nums[i] + nums[j]);
                    numsnxt.erase(numsnxt.begin() + j);
                    perebor(numsnxt);

                    numsnxt = nums;
                    numsnxt[i] = (nums[i] * nums[j]);
                    numsnxt.erase(numsnxt.begin() + j);
                    perebor(numsnxt);

                    numsnxt = nums;
                    numsnxt[i] = (nums[i] / nums[j]);
                    numsnxt.erase(numsnxt.begin() + j);
                    perebor(numsnxt);

                    numsnxt = nums;
                    numsnxt[i] = (nums[i] - nums[j]);
                    numsnxt.erase(numsnxt.begin() + j);
                    perebor(numsnxt);
                }
            }

        }
    }

    void run() {
        vector<ld> nums;
        for (int i = 0; i < 4; ++i) {
            ll a;
            cin >> a;
            nums.push_back(a);
        }
        perebor(nums);
        cout << best;


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
    if (filename.compare("")) {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
    prog p;
    p.run();
#endif
    return 0;
}
