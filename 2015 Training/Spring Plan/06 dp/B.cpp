//
//  Created by TaoSama on 2015-08-05
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

int n, a[30], b[30], asum[30], bsum[30];
int dp[30][30][30][30];

int dfs(int l, int r, int u, int v) {
    if(dp[l][r][u][v] >= 0) return dp[l][r][u][v];
    int sum = 0, ret = 0;
    if(l <= r) sum += asum[r] - asum[l - 1];
    if(u <= v) sum += bsum[v] - bsum[u - 1];

    if(l <= r) ret = max(ret, sum - min(dfs(l + 1, r, u, v), dfs(l, r - 1, u, v)));
    if(u <= v) ret = max(ret, sum - min(dfs(l, r, u + 1, v), dfs(l, r, u, v - 1)));
    return dp[l][r][u][v] = ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            asum[i] = asum[i - 1] + a[i];
        }
        for(int i = 1; i <= n; ++i) {
            scanf("%d", b + i);
            bsum[i] = bsum[i - 1] + b[i];
        }

//        dp[n][n][1][n] = a[n]; dp[1][n][n][n] = b[n];
//        for(int i = n; i >= 1; --i) {
//            for(int j = i; j <= n; ++j) {
//                for(int u = n; u >= 1; --u) {
//                    for(int v = u; v <= n; ++v) {
//                        int sum = asum[j] - asum[i - 1] + bsum[v] - bsum[u - 1];
//                        int minv = min(dp[i + 1][j][u][v], dp[i][j - 1][u][v]);
//                        minv = min(minv, min(dp[i][j][u + 1][v], dp[i][j][u][v - 1]));
//                        dp[i][j][u][v] = sum - minv;
//                    }
//                }
//            }
//        }
        memset(dp, -1, sizeof dp);
        printf("%d\n", dfs(1, n, 1, n));
    }

    return 0;
}
