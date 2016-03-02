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
    int next[27];
    int go[27];
    int prev;
    int link = -1;
    char pred_c;
    bool leaf = false;
    bool leaf_a = false;
    bool leaf_as = false;
};
Node bor[1000*1000];
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

Node initstruct() {
    Node n;
    for (int i = 0; i < 27; ++i) {
        n.next[i] = n.go[i] = -1;
    }
    return n;
}

string to_lower_oleg (string s){
    string s2;
    for(char c : s){
        if('A' <= c && c <='Z')
        {
            c = c-'A'+'a';
        }
        s2.push_back(c);
    }
    return s2;

}

int run() {
    int a;
    cin >> a;
    string sup_str;
    cin >> sup_str;
    string string1;
    for(char c: sup_str){
        string1.push_back(c-'a');
    }
    sup_str = string1;

    int n;
    cin >> n;
    Node root = initstruct();
    root.link = 0;
    root.prev = 0;
    bor[0] = root;

    int curb = 1;
    map<string, string> sst;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        string s2 = to_lower_oleg(s);


        string1 = "";
        for(char c: s){
            string1.push_back(c-'a');
        }
        s = string1;
        string1 = "";
        for(char c: s2){
            string1.push_back(c-'a');
        }
        s2 = string1;
        sst[s2] = s;
        s = s2;
        reverse(s.begin(), s.end());
        //cout << n << " " << i <<" " << s  << endl;
        int cur = 0;
        for (auto it = s.begin(); it != s.end(); ++it) {
            if (bor[cur].next[*it] == -1) {
                Node n = initstruct();
                n.prev = cur;
                n.pred_c = *it;
                bor[cur].next[*it] = curb;
                bor[curb] = n;
                curb++;

            }
            cur = bor[cur].next[*it];
        }
        bor[cur].leaf = true;
    }
    for (int j = 0; j < curb; j++) {
        for (int i = 0; i < 27; ++i) {
            go(j, i);
        }
        //link(j);
        leaf_a(j);

    }
    ll cur = 0;
    vector<int> hist;
    for (char c : sup_str) {
        cur = bor[cur].go[c];
        hist.push_back(cur);
    }
    //reverse(hist.begin(), hist.end());
    auto it = sup_str.begin();
    string word;
    for (int a : hist) {

        word.push_back(*it);
        ++it;
        if(bor[a].leaf){
            reverse(word.begin(), word.end());
            string1 = "";
            for(char c :sst[word] )
                cout << (char)(c + 'a');
            cout <<  " ";
            word = "";
        }

    }


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

