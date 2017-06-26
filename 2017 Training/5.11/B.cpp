//
//  Created by TaoSama on 2017-05-11
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct Trie {
    static const int M = 1e5 + 10, S = 26;
    int nxt[M][S], cnt[M];
    int sz, root;
    multiset<pair<int, int> > suffix;
    int newNode() {
        cnt[sz] = 0;
        memset(nxt[sz], 0, sizeof nxt[sz]);
        return sz++;
    }
    void init() {
        sz = 0;
        root = newNode();
        suffix.clear();
        suffix.insert({INF, INF});
    }
    void add(const char* s, int delta) {
        int l = strlen(s);
        int u = root;
        for(int i = 0; i < l; ++i) {
            int c = s[l - i - 1] - 'a';
            int& v = nxt[u][c];
            if(!v) v = newNode();
            u = v;
            auto iter = suffix.find({i + 1, cnt[u]});
            if(iter != suffix.end()) suffix.erase(iter);
            cnt[u] += delta;
            suffix.insert({i + 1, cnt[u]});
        }
    }
    bool query(int k, int l) {
        return suffix.lower_bound({l, k})->first == l;
    }
} trie;

char s[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int q; scanf("%d", &q);
    vector<string> qs(q);
    vector<bool> del(q, 0);
    trie.init();
    for(int i = 0; i < q; ++i) {
        int op; scanf("%d", &op);
        if(op == 1) {
            scanf("%s", s);
            trie.add(s, 1);
            qs[i] = s;
        } else if(op == 2) {
            int k, l; scanf("%d%d", &k, &l);
            puts(trie.query(k, l) ? "YES" : "NO");
        } else {
            int x; scanf("%d", &x);
            if(!del[x]) {
                del[x] = true;
                trie.add(qs[x - 1].c_str(), -1);
            }
        }
    }

    return 0;
}