//
//  Created by TaoSama on 2015-12-19
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int N = 1e4 + 10, INF = 0x3f3f3f3f, MOD = 21092013;

int n, l[N], r[N];
int dp[N][55], ans[55], gcd[55][55];
vector<int> G[N];

inline void add(int &x, int y) {
    if((x += y) >= MOD) x -= MOD;
}

inline int mul(int x, int y) {
    return 1LL * x * y % MOD;
}

void dfs(int u, int f) {
    for(int i = l[u]; i <= r[u]; ++i) {
        dp[u][i] = 1;
        add(ans[i], 1);
    }

    for(int v : G[u]) {
        if(v == f) continue;
        dfs(v, u);
        for(int j = 1; j <= 50; ++j)
            for(int k = 1; k <= 50; ++k)
                add(ans[gcd[j][k]], mul(dp[u][j], dp[v][k]));
        for(int j = l[u]; j <= r[u]; ++j)
            for(int k = 1; k <= 50; ++k)
                add(dp[u][gcd[j][k]], dp[v][k]);
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    for(int i = 1; i <= 50; ++i)
        for(int j = 1; j <= 50; ++j)
            gcd[i][j] = __gcd(i, j);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i = 1; i <= n; ++i) scanf("%d", l + i);
        for(int i = 1; i <= n; ++i) scanf("%d", r + i);

        memset(dp, 0, sizeof dp);
        memset(ans, 0, sizeof ans);
        dfs(1, -1);
        static int kase = 0;
        printf("Case %d:\n", ++kase);
        for(int i = 1; i <= 50; ++i)
            printf("%d: %d\n", i, ans[i]);
    }
    return 0;
}
