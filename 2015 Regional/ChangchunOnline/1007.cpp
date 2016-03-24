//
//  Created by TaoSama on 2015-09-13
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q, dp[2][N][20];

int RMQ(int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);
    int Max = max(dp[1][l][k], dp[1][r - (1 << k) + 1][k]);
//    int Min = min(dp[0][l][k], dp[0][r - (1 << k) + 1][k]);
    return Max;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &dp[0][i][0]);
            dp[1][i][0] = dp[0][i][0];
        }
        for(int j = 1; (1 << j) <= n; ++j) {
            for(int i = 1; i + (1 << j) - 1 <= n; ++i) {
                dp[0][i][j] = min(dp[0][i][j - 1],
                                  dp[0][i + (1 << j - 1)][j - 1]);
                dp[1][i][j] = max(dp[1][i][j - 1],
                                  dp[1][i + (1 << j - 1)][j - 1]);
            }
        }
        scanf("%d", &q);
        while(q--) {
            int x, y; scanf("%d%d", &x, &y);
            printf("%d\n", RMQ(x, y));
        }
    }
    return 0;
}
