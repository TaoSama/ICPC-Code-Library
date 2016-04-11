//
//  Created by TaoSama on 2016-01-12
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
const int N = 3e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 1e5 + 10, S = 26;

int n, K;
int lcp[N][N], f[N][N];

struct Trie {
    int nxt[M][S];
    int root, sz;
    int newNode() {
        memset(nxt[sz], 0, sizeof nxt[sz]);
        return sz++;
    }
    void init() {
        sz = 0;
        root = newNode();
    }
    int insert(char *s) {
        int u = root;
        for(int i = 0; s[i]; ++i) {
            int &v = nxt[u][s[i] - 'a'];
            if(!v) v = newNode();
            u = v;
        }
        return u;
    }
} trie;

char s[M];
int ed[N], r[N], z[N];
int dfn[M], dep[M], p[17][M], dfsNum;

void dfs(int u, int f) {
    dfn[u] = ++dfsNum;
    p[0][u] = f;
    for(int i = 1; i < 17; ++i) p[i][u] = p[i - 1][p[i - 1][u]];
    for(int i = 0; i < S; ++i) {
        int v = trie.nxt[u][i];
        if(!v) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

bool cmp(int x, int y) {
    return dfn[ed[x]] < dfn[ed[y]];
}

int lca(int u, int v) {
    if(dep[u] > dep[v]) swap(u, v);
    for(int i = 0; i < 17; ++i)
        if(dep[v] - dep[u] >> i & 1) v = p[i][v];
    if(u == v) return u;
    for(int i = 16; ~i; --i)
        if(p[i][u] != p[i][v])
            u = p[i][u], v = p[i][v];
    return p[0][u];
}

int cost[N][N];

int getCost(int x, int y) {
    return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}

int main() {
    freopen("text_editor.txt", "r", stdin);
    freopen("text_editor_out.txt", "w", stdout);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &K);
        trie.init();
        for(int i = 1; i <= n; ++i) {
            scanf("%s", s);
            r[i] = i;
            ed[i] = trie.insert(s);
        }

        dfsNum = 0;
        dfs(0, 0);
        sort(r + 1, r + 1 + n, cmp);

        memset(f, 0x3f, sizeof f);
        for(int i = 1; i <= n; ++i) z[i] = ed[r[i]], f[1][i] = dep[z[i]];

        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                cost[i][j] = getCost(z[i], z[j]);

        for(int i = 2; i <= K; ++i)
            for(int j = 1; j <= n; ++j)
                for(int k = 1; k < j; ++k)
                    f[i][j] = min(f[i][j], f[i - 1][k] + cost[j][k]);

        int ans = INF;
        for(int i = 1; i <= n; ++i) ans = min(ans, f[K][i] + dep[z[i]]);

        static int kase = 0;
        printf("Case #%d: %d\n", ++kase, ans + K);
    }
    return 0;
}
