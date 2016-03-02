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
    vector<vector<ll> > metri;


    struct place {
        bool vert;
        int x, y;
        int metri;

        friend bool operator<(place p1, place p2) {
            if (p1.metri == p2.metri)
            if (p1.x == p2.x)
            if (p1.y == p2.y)
                return p1.vert < p2.vert;
            else
                return p1.y < p2.y;
            else
                return p1.x < p1.x;
            else
                return p1.metri < p2.metri;
        }



        friend bool operator==(place p1, place p2) {
            return  p1.metri == p2.metri && p1.vert == p2.vert && p1.x == p2.x && p1.y == p2.y;
        }


    };

    int getMetr(place p1) {
        if (p1.vert) {
            return metri[p1.x][p1.y] + metri[p1.x + 1][p1.y] - 2;
        } else {
            return metri[p1.x][p1.y] + metri[p1.x][p1.y + 1] - 2;
        }
    }

    void run() {
        ll N, M;
        cin >> N >> M;
        metri.resize(N + 2, vector<ll>(M + 2));
        vector<vector<char> > field(N + 2, vector<char>(M + 2));
        vector<pair<ll, ll> > dirs(4);
        dirs[0] = make_pair(0, 1);
        dirs[1] = make_pair(0, -1);
        dirs[2] = make_pair(1, 0);
        dirs[3] = make_pair(-1, 0);

        for (int l = 0; l < M + 2; ++l) {
            field[0][l] = '*';
            field[N + 1][l] = '*';
        }
        for (int i = 1; i <= N; ++i) {
            field[i][0] = field[i][M + 1] = '*';
            for (int j = 1; j <= M; ++j) {
                cin >> field[i][j];
            }

        }
        for (int j = 1; j <= N; ++j) {
            for (int i = 1; i <= M; ++i) {
                for (int k = 0; k < 4; ++k) {
                    //ll a = j + dirs[k].first, b = ;

                    if (field[j + dirs[k].first][i + dirs[k].second] == '.')
                        metri[j][i]++;
                }
            }
        }
        //Werti
        set<place> places;
        for (int i = 1; i <= N - 1; ++i) {
            for (int j = 1; j <= M; ++j) {
                if (field[i][j] == '.' && field[i + 1][j] == '.') {
                    place p;
                    p.vert = true;
                    p.x = i;
                    p.y = j;
                    p.metri = getMetr(p);
                    places.insert(p);
                }
            }
        }
        //Horis
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M - 1; ++j) {
                if (field[i][j] == '.' && field[i][j + 1] == '.') {
                    place p;
                    p.vert = false;
                    p.x = i;
                    p.y = j;
                    p.metri = getMetr(p);
                    places.insert(p);
                }
            }
        }
        while (!places.empty()) {
            place last, cur = *places.begin();

            do {
                last = cur;
                places.erase(cur);
                bool bad = false;
                if (last.vert) {
                    if (!(field[last.x][last.y] == '.' &&
                          field[last.x + 1][last.y] == '.')) {
                        bad = true;
                    }
                } else {
                    if (!(field[last.x][last.y] == '.' &&
                          field[last.x][last.y + 1] == '.')) {
                        bad = true;
                    }
                }
                last.metri = getMetr(last);
                if (!bad)
                    places.insert(last);
                if (places.size() > 0)
                    cur = *places.begin();
            } while (places.size() > 0 &&
                     !(last == cur));
            if (places.size() == 0)
                break;
            places.erase(cur);
            if (cur.vert) {
                field[cur.x][cur.y] = 'M';
                field[cur.x + 1][cur.y] = 'W';
                for (int i = 0; i < 4; ++i) {
                    if (field[cur.x + dirs[i].first][cur.y + dirs[i].second] == '.') {
                        field[cur.x + dirs[i].first][cur.y + dirs[i].second] = '%';
                    };
                    if (field[cur.x + dirs[i].first + 1][cur.y + dirs[i].second] == '.') {
                        field[cur.x + dirs[i].first + 1][cur.y + dirs[i].second] = '%';
                    };
                }
            } else {
                field[cur.x][cur.y] = '[';
                field[cur.x][cur.y + 1] = ']';
                for (int i = 0; i < 4; ++i) {
                    if (field[cur.x + dirs[i].first][cur.y + dirs[i].second] == '.') {
                        field[cur.x + dirs[i].first][cur.y + dirs[i].second] = '%';
                    };
                    if (field[cur.x + dirs[i].first][cur.y + dirs[i].second + 1] == '.') {
                        field[cur.x + dirs[i].first][cur.y + dirs[i].second + 1] = '%';
                    };
                }
            }
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                if (field[i][j] == '%')
                    cout << '.';
                else
                    cout << field[i][j];
            }
            cout << endl;
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
    if (filename.compare("")) {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
    prog p;
    p.run();
#endif
    return 0;
}
