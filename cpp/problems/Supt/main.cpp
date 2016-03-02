#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


/*int run() {
    int n;
    cin >> n;
    vector<long> d(n), s0(n), s1(n), phi(n);
    ll df = 1;
    for (int i = 2; i <= n; i++) {
        if (d[i] == 0) {
            d[i] = i;
        }
        auto cur = 2 * i;
        while (cur <= n) {
            s0[cur]++;
            s1[cur]+=i;
            if (d[i] == 0 && d[cur] == 0) {
                d[cur] = i;
                df += d[cur];
            }
            cur += i;
        }


    }
    cout << df;
}*/

struct Node {
    int next[128];
    int go[128];
    int prev;
    int link = -1;
    char pred_c;
    int count = 0;
    bool leaf = false;
    bool leaf_a = false;
    bool leaf_as = false;
    bool counted = false;
    bool lened = false;

    int len = 0;
    int curlen = 0;
};
Node bor[80 * 1000 * 2];

int go(int v, char c);

int link(int v) {
    if (bor[v].link != -1) {
        return bor[v].link;
    }
    if (bor[v].prev == 0)
        bor[v].link = bor[v].prev;
    else
        bor[v].link = go(link(bor[v].prev), bor[v].pred_c);

    return bor[v].link;
}

int go(int v, char c) {
    if (bor[v].go[c] != -1)
        return bor[v].go[c];

    if (bor[v].next[c] != -1)
        bor[v].go[c] = bor[v].next[c];
    else if (v == 0)
        bor[v].go[c] = 0;
    else
        bor[v].go[c] = go(link(v), c);
    return bor[v].go[c];
}

bool leaf_a(int v) {
    if (bor[v].leaf_as) {
        return bor[v].leaf_a;
    }
    bor[v].leaf_as = true;

    if (link(v) == 0)
        bor[v].leaf_a = false;
    bor[v].leaf_a = leaf_a(link(v)) || bor[link(v)].leaf;

    return bor[v].leaf_a;
}


/*int count(int v) {
    if (bor[v].counted)
        return bor[v].count;
    bor[v].counted = true;
    if (v == 0)
        return 0;

}*/

int len(int v, int left) {
    if (bor[v].lened)
        return bor[v].len;
    bor[v].lened = true;
    if (v == 0)
        return 0;
    if (left == 0)
        bor[v].len = bor[v].curlen;
    else
        bor[v].len = len(link(v), left - bor[v].count);
    return bor[v].len;
}


Node initstruct() {
    Node n;
    for (int i = 0; i < 128; ++i) {
        n.next[i] = n.go[i] = -1;
    }
    return n;
}


int n;

int run() {
    cin >> n;
    Node root = initstruct();
    root.link = 0;
    root.prev = 0;
    bor[0] = root;
    string s;
    getline(cin, s);
    int curb = 1;
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        //cout << n << " " << i <<" " << s  << endl;
        int cur = 0;
        for (auto it = s.begin(); it != s.end(); ++it) {
            int curs = 1;
            if (bor[cur].next[*it] == -1) {
                Node n = initstruct();
                n.prev = cur;
                n.pred_c = *it;
                n.len = curs;
                bor[cur].next[*it] = curb;
                bor[curb] = n;
                curb++;

            }
            curs++;
            cur = bor[cur].next[*it];
        }
        bor[cur].leaf = true;
    }
    int maxlen = 0;
    for (int j = 0; j < curb; j++) {
        for (int i = 0; i < 128; ++i) {
            go(j, i);
        }
        link(j);
        leaf_a(j);
        maxlen = max(maxlen, len(j, n));
    }
    cout << maxlen;


}


int main() {
    cin.sync_with_stdio(false);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else

#endif
    //cout<< "Hello";
    run();
    return 0;
}