//
//  Created by TaoSama on 2015-11-13
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

int n, a[105], sum[105];
int f[105][105], g[105][105], dp[105][105];
//f[i][j]:= min{dp[i][j],dp[i+1][j],dp[i+2][j],...,dp[j][j]};
//g[i][j]:= min{dp[i][j],dp[i][j-1],dp[i][j-2],...,dp[i][i]};

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            sum[i] = sum[i - 1] + a[i];
            dp[i][i] = f[i][i] = g[i][i] = a[i];
        }

        for(int l = 1; l < n; ++l) {
            for(int i = 1; i + l <= n; ++i) {
                int j = i + l;
                dp[i][j] = sum[j] - sum[i - 1];
                dp[i][j] -= min(0, min(f[i + 1][j], g[i][j - 1]));
                f[i][j] = min(f[i + 1][j], dp[i][j]);
                g[i][j] = min(g[i][j - 1], dp[i][j]);
            }
        }
        printf("Case %d: %d\n", ++kase, 2 * dp[1][n] - sum[n]);
    }
    return 0;
}
