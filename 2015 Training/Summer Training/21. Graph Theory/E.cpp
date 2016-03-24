//
//  Created by TaoSama on 2015-08-16
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, q;
int dp[105][105];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d%d%d", &n, &m, &q) == 3 && (n || m || q)) {
        memset(dp, 0x3f, sizeof dp);
        for(int i = 1; i <= n; ++i) dp[i][i] = 0;
        for(int i = 1; i <= m; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            dp[u][v] = dp[v][u] = c;
        }

        for(int k = 1; k <= n; ++k)
            for(int i = 1; i <= n; ++i)
                for(int j = 1; j <= n; ++j)
                    dp[i][j] = min(dp[i][j], max(dp[i][k], dp[k][j]));

        if(kase) puts("");
        printf("Case #%d\n", ++kase);
        while(q--) {
            int u, v; scanf("%d%d", &u, &v);
            if(dp[u][v] == INF) puts("no path");
            else printf("%d\n", dp[u][v]);
        }
    }
    return 0;
}
