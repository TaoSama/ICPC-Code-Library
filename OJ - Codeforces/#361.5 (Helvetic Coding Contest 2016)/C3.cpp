//
//  Created by TaoSama on 2016-07-11
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

int n, fa[N];
vector<int> G[N];

const int LOG = 20;
int p[LOG][N], dep[N];

void dfs(int u, int f) {
    p[0][u] = f;
    for(int i = 1; i < LOG; ++i) p[i][u] = p[i - 1][p[i - 1][u]];
    for(int v : G[u]) {
        if(v == f) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if(dep[u] > dep[v]) swap(u, v);
    for(int i = 0; i < LOG; ++i)
        if(dep[v] - dep[u] >> i & 1) v = p[i][v];
    if(u == v) return u;
    for(int i = LOG - 1; ~i; --i)
        if(p[i][u] != p[i][v])
            u = p[i][u], v = p[i][v];
    return p[0][u];
}

int getDis(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    scanf("%d", &n);
    for(int i = 2; i <= n; ++i) {
        scanf("%d", fa + i);
        G[fa[i]].push_back(i);
        G[i].push_back(fa[i]);
    }
    dfs(1, 0);

    pair<int, pair<int, int> > far = {0, {1, 1}};
    for(int i = 2; i <= n; ++i) {
        int x, y; tie(x, y) = far.second;
        int d1 = getDis(i, x), d2 = getDis(i, y);
        far = max(far, {d1, {i, x}});
        far = max(far, {d2, {i, y}});
        printf("%d%c", far.first, " \n"[i == n]);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
