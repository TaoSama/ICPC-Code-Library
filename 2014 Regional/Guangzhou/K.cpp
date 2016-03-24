//
//  Created by TaoSama on 2015-10-23
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
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;

int n, m;
long long dp[35][35];
int u[1005], v[1005], c[1005];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2 && (n || m)) {
        for(int i = 1; i <= m; ++i) scanf("%d%d%d", u + i, v + i, c + i);
        long long ans = 0;
        for(int i = 2; i < n; ++i) {
            memset(dp, 0x3f, sizeof dp);
            for(int j = 1; j <= n; ++j) dp[j][j] = 0;
            for(int j = 1; j <= m; ++j) {
                if(u[j] == i || v[j] == i) continue;
                dp[u[j]][v[j]] = dp[v[j]][u[j]] = c[j];
            }
            for(int k = 1; k <= n; ++k)
                for(int a = 1; a <= n; ++a)
                    for(int b = 1; b <= n; ++b)
                        dp[a][b] = min(dp[a][b], dp[a][k] + dp[k][b]);
            ans = max(ans, dp[1][n]);
            if(ans == INF) break;
        }
        if(ans == INFLL) puts("Inf");
        else printf("%I64d\n", ans);
    }
    return 0;
}
