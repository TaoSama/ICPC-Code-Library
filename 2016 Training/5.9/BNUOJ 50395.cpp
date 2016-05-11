//
//  Created by TaoSama on 2016-05-09
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
bitset<500> g[30];

void dfs(int u, int& ans, bitset<500> vs) {
    int cnt = vs.count();
    if(cnt >= ans) return;
    if(u == min(n, 30)) {ans = cnt; return;}
    if(vs[u]) dfs(u + 1, ans, vs);
    else {
        vs[u] = 1;
        dfs(u + 1, ans, vs); //涂
        vs[u] = 0;
        dfs(u + 1, ans, vs | g[u]); //不涂它，连的点就得涂
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 0; i < 30; ++i) g[i].reset();
        for(int i = 1; i <= m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            --u; --v;
            if(u > v) swap(u, v);
            g[u][v] = 1;
            if(v < u) g[v][u] = 1;
        }

        int ans = INF;
        dfs(0, ans, 0);
        printf("%d\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
