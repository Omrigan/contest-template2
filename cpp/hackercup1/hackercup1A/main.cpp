#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll LINF = 1e18;
const int INF = 1e9;
const ld EPS = 1e-6;
const ll MOD = 1e9 + 7;

const string filename = "";


struct prog {

    void run() {
        ll T;
        cin >> T;
        for (int i = 0; i < T; ++i) {
            ll N;
            cin >> N;
            ll prev;
            ll commits = 0;
            cin >> prev;
            ll curstep = 1;
            for (int j = 1; j < N; ++j) {
                ll cur;
                cin >> cur;

                while (curstep != 0 && (prev >= cur || cur - prev > 10)) {
                    ll nxt = prev + 10;
                    if (nxt > 100)
                        nxt = prev + 1;
                    prev = nxt;
                    curstep = (curstep + 1) % 4;
                    commits++;
                }
                prev = cur;
                curstep = (curstep + 1) % 4;
            }
            while (curstep != 0) {
                commits++;
                curstep = (curstep + 1) % 4;
            }


            cout << "Case #" << i + 1 << ": " << commits << endl;
        }

    }

};


int main() {


#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while (!cin.eof()) {
        int cl = clock();
        prog p;
        p.run();
        fprintf(stderr, "Execution time: %Lf \n", (long double) (clock() - cl) / CLOCKS_PER_SEC * 1000);
        cout << endl;
    }
#else
    prog p;
    p.run();
#endif
    return 0;
}
