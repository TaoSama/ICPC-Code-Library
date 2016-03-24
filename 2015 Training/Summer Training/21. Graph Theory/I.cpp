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

int n, x[105], y[105], z[105], r[105];
double dp[105][105];

double getdis(int i, int j) {
    double ret = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])
                      + (z[i] - z[j]) * (z[i] - z[j]));
    ret -= r[i] + r[j];
    if(ret < 1e-10) ret = 0;
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d", &n) == 1 && ~n) {
        for(int i = 1; i <= n; ++i) scanf("%d%d%d%d", x + i, y + i, z + i, r + i);
        for(int i = n + 1; i <= n + 2; ++i) {
            scanf("%d%d%d", x + i, y + i, z + i);
            r[i] = 0;
        }

        for(int i = 1; i <= n + 2; ++i) {
            dp[i][i] = 0;
            for(int j = i + 1; j <= n + 2; ++j)
                dp[i][j] = dp[j][i] = 1e20;
        }

        for(int i = 1; i <= n + 2; ++i)
            for(int j = i + 1; j <= n + 2; ++j)
                dp[i][j] = dp[j][i] = getdis(i, j);

        for(int k = 1; k <= n + 2; ++k)
            for(int i = 1; i <= n + 2; ++i)
                for(int j = 1; j <= n + 2; ++j)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

        printf("Cheese %d: Travel time = %.0f sec\n", ++kase, dp[n + 1][n + 2] * 10);
    }
    return 0;
}
