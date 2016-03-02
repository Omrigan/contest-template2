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
        ll N;
        cin >> N;
        vector<pair<ll, ll>> anses;
        vector<ll> vec;
        for (int i = 0; i < N; ++i) {
            ll a;
            cin >> a;
            vec.push_back(a);
        }
        vector<ll> dirs = {-4, -3, 3, 4};
        bool changes = true;
        if (N <= 8) {
            random_shuffle(dirs.begin(), dirs.end());
            bool correct = true;
            ll num = 0;
            do {
                correct = true;
                for (int j = 0; j < N - 1; ++j) {
                    correct &= vec[j] >= vec[j + 1];
                }
                if (!correct) {
                    bool moved = false;
                    for (int i = 0; i < 4 && !moved; ++i) {
                        ll a = rand() % N, b = a + dirs[i], tmp;
                        if (b >= 0 && b < N) {
                            moved = true;
                            tmp = vec[a];
                            vec[a] = vec[b];
                            vec[b] = tmp;
                            anses.push_back(make_pair(a, b));
                        }
                    }

                };
                num++;
            } while (!correct && num < 22 * 1000);

        } else {
            while (changes) {
                changes = false;
                for (int i = 0; i < N - 1; ++i) {
                    if (vec[i] < vec[i + 1]) {
                        if (i > 2) {
                            ll tmp;
                            tmp = vec[i];
                            vec[i] = vec[i + 1];
                            vec[i + 1] = tmp;
                            anses.push_back(make_pair(i, i - 3));
                            anses.push_back(make_pair(i + 1, i - 3));
                            anses.push_back(make_pair(i, i - 3));
                            changes = true;
                        } else if (N - i >= 5) {
                            ll tmp;
                            tmp = vec[i];
                            vec[i] = vec[i + 1];
                            vec[i + 1] = tmp;
                            anses.push_back(make_pair(i, i + 4));
                            anses.push_back(make_pair(i + 1, i + 4));
                            anses.push_back(make_pair(i, i + 4));
                            changes = true;
                        }

                    }
                }
            }
        }
        bool correct = true;
        for (int j = 0; j < N - 1; ++j) {
            correct &= vec[j] >= vec[j + 1];
        }
        if (correct) {
            cout << "YES" << endl << anses.size() << endl;
            for (auto p : anses) {
                cout << p.first + 1 << " " << p.second + 1 << endl;
            }
        } else {
            cout << "NO" << endl;
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
