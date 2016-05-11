//
//  Created by TaoSama on 2016-05-08
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
#include <bitset>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
struct Edge {
    int u, v;
} edge[N];

bitset<2000> sta[1000];

void dfs(int dep, int& ans, bitset<2000> b) {
    if(dep >= ans || dep > 10) return;
    if(b.count() == m) {ans = dep; return;}
    for(int i = 0; i < m; ++i) {
        if(b[i] == 1) continue;
        int u = edge[i].u, v = edge[i].v;
        dfs(dep + 1, ans, b | sta[u]);
        dfs(dep + 1, ans, b | sta[v]);
        break;
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            edge[i] = (Edge) {u, v};
        }
        for(int i = 0; i < n; ++i) {
            sta[i].reset();
            for(int j = 0; j < m; ++j)
                if(edge[j].u == i || edge[j].v == i)
                    sta[i][j] = 1;
        }
        int ans = INF;
        dfs(0, ans, 0);
        if(ans == INF) puts("GG");
        else printf("%d\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
