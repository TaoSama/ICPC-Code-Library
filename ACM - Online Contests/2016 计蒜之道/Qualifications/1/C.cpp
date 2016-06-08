//
//  Created by TaoSama on 2016-06-05
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
#include <bitset>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int gcd[505][505];
int n, a[N];
int ancestor[N], vis[N], dep[N], ans;

int find(int x) {
    return ancestor[x] = ancestor[x] == x ? x : find(ancestor[x]);
}

bitset<N> checked[N];
vector<int> G[N];

void tarjan(int u) {
    vis[u] = true;
    ancestor[u] = u;
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(vis[v]) continue;
        dep[v] = dep[u] + 1;
        tarjan(v);
        ancestor[v] = u;
    }
    for(int v = 1; v <= n; ++v) {
        if(vis[v] && gcd[a[u]][a[v]] == 1 && !checked[v][u]) {
            int lca = find(v);
            checked[u][v] = 1;
            ans += dep[u] + dep[v] - 2 * dep[lca];
        }
    }
}


int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", a + i);
    for(int i = 1; i <= 500; ++i)
        for(int j = 1; j <= 500; ++j)
            gcd[i][j] = __gcd(i, j);

    for(int i = 1; i < n; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ans = 0;
    tarjan(1);
    printf("%d\n", ans);


#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
