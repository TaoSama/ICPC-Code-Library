//
//  Created by TaoSama on 2016-08-15
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
struct Edge {
    int u, v, p, c1, c2;
} edges[15];

int f[1 << 10][10][15][2];

inline void getMin(int& x, int y) {
    if(x > y) x = y;
}

int dfs(int s, int u, int x, int prev) {
    if(u == n - 1) return 0;
    int& ret = f[s][u][x][prev];
    if(~ret) return ret;
    ret = INF;
    for(int y = 1; y <= m; ++y) {
        Edge& e = edges[y];
        if(e.u != u) continue;
        int v = e.v, p = e.p, c1 = e.c1, c2 = e.c2;
        for(int j = 0; j < 2; ++j) {
            int ns = s | 1 << v;
            getMin(ret, dfs(ns, v, y, 0) + c2);
            if(!(ns >> p & 1)) c1 = INF;
            getMin(ret, dfs(ns, v, y, 1) + c1);
        }
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= m; ++i) {
            int u, v, p, c1, c2;
            scanf("%d%d%d%d%d", &u, &v, &p, &c1, &c2);
            --u; --v; --p;
            edges[i] = (Edge) {u, v, p, c1, c2};
        }

        memset(f, -1, sizeof f);
        int ans = dfs(1 << 0, 0, 0, 0);

        if(ans == INF) puts("impossible");
        else printf("%d\n", ans);
    }

    return 0;
}
