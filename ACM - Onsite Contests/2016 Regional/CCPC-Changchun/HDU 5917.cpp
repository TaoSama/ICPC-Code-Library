//
//  Created by TaoSama on 2016-10-04
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
const int N = 50 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
typedef long long LL;

#define rep(i, a, b) for(int i = a; i <= b; ++i)

bool g[N][N];

int c[5];
inline bool check(int a, int d) {
    for(int i = 0; i < d; ++i) {
        int x = c[i];
        for(int j = i + 1; j < d; ++j) {
            int y = c[j];
            if(g[a][x] && g[a][y] && g[x][y]) return false;
            if(!g[a][x] && !g[a][y] && !g[x][y]) return false;
        }
    }
    return true;
}

LL stable;
void dfs(int d) {
    if(d >= 3) {
        ++stable;
        if(d == min(5, n)) return;
    }
    for(int i = d ? c[d - 1] + 1 : 1; i <= n; ++i) {
        c[d] = i;
        int ret = check(i, d);
//        printf("d = %d i = %d ret = %d\n", d, i, ret);
        if(ret) dfs(d + 1);
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        memset(g, 0, sizeof g);
        for(int i = 1; i <= m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            g[u][v] = g[v][u] = 1;
        }

        stable = 0;
        dfs(0);
        LL ans = (1LL << n) - 1 - n - n * (n - 1) / 2;
        ans = (ans - stable) % MOD;

        static int kase = 0;
        printf("Case #%d: %I64d\n", ++kase, ans);
    }

    return 0;
}
