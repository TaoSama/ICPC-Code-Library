//
//  Created by TaoSama on 2016-08-12
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct Trie {
    static const int M = N * 32, S = 2;
    int sz, root, nxt[M][S];
    int val[M];
    int newNode() {
        val[sz] = 0;
        memset(nxt[sz], 0, sizeof nxt[sz]);
        return sz++;
    }
    void init() {
        sz = 0; newNode();
        root = newNode();
    }
    void insert(int x, int d) {
        int u = root;
        for(int i = 31; ~i; --i) {
            int c = x >> i & 1;
            int& v = nxt[u][c];
            if(!v) v = newNode();
//            prln(v);
            val[v] += d;
            u = v;
        }
    }
    int query(int x) {
        int u = root, ret = 0;
        for(int i = 31; ~i; --i) {
            int c = x >> i & 1;
            int v = nxt[u][c ^ 1];
            if(val[v]) u = v, ret |= 1 << i;
            else u = nxt[u][c];
        }
        return ret;
    }
} trie;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    trie.init();
    trie.insert(0, 1);
    int q; scanf("%d", &q);
    while(q--) {
        char op[2];
        int x; scanf("%s%d", op, &x);
        if(*op == '+') trie.insert(x, 1);
        else if(*op == '-') trie.insert(x, -1);
        else printf("%d\n", trie.query(x));
    }

    return 0;
}
