//
//  Created by TaoSama on 2015-08-08
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int m, n, a[N];
long long dp[N], g[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &m, &n) == 2) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);

        memset(dp, 0, sizeof dp);
        memset(g, 0, sizeof g);
        for(int i = 1; i <= m; ++i) {
            long long pre = -1LL << 60;
            for(int j = i; j <= n; ++j) {
                dp[j] = max(dp[j - 1], g[j - 1]) + a[j];
                g[j - 1] = pre; //this for next's before
                pre = max(pre, dp[j]); //same as it
            }
        }

        long long ans = -1LL << 60;
        for(int i = m; i <= n; ++i)
            ans = max(ans, dp[i]);
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
for(int i = 1; i <= m; ++i) {
    for(int j = i; j <= n; ++j) {
        dp[i][j] = dp[i][j - 1] + a[j];
        for(int k = i - 1; k <= j - 1; ++k)
            dp[i][j] = max(dp[i][j], dp[i - 1][k] + a[j]);
    }
}
*/
