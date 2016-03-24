//
//  Created by TaoSama on 2015-09-12
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e8 + 7;

int dp[1005][2005][2]; //i列分j块 本列1连还是0分

void gao() {
    dp[1][1][1] = dp[1][2][0] = 1;
    for(int i = 2; i <= 1000; ++i) {
        for(int j = 1; j <= 2000; ++j) {
            //j=>j
            dp[i][j][1] = dp[i - 1][j][0] * 2 + dp[i - 1][j][1];
            dp[i][j][0] = dp[i - 1][j][0];
            //j-1=>j
            dp[i][j][1] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1];
            dp[i][j][0] += (dp[i - 1][j - 1][0]  + dp[i - 1][j - 1][1]) * 2;
            //j-2=>j
            dp[i][j][0] += dp[i - 1][j - 2][0] + dp[i - 1][j - 2][1];

            dp[i][j][0] %= MOD;
            dp[i][j][1] %= MOD;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    gao();
    int t; scanf("%d", &t);
    while(t--) {
        int n, k; scanf("%d%d", &n, &k);
        printf("%d\n", (dp[n][k][0] + dp[n][k][1]) % MOD);
    }
    return 0;
}
