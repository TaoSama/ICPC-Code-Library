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

int dp[105][105];

bool read() {
    memset(dp, 0x3f, sizeof dp);
    int have = false, u, v;
    while(scanf("%d%d", &u, &v) == 2 && (u || v)) {
        have = true;
        dp[u][v] = 1;
    }
    return have;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(read()) {
        for(int k = 1; k <= 100; ++k)
            for(int i = 1; i <= 100; ++i)
                for(int j = 1; j <= 100; ++j)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

//        for(int i = 1; i <= 4; ++i) {
//            for(int j = 1; j <= 4; ++j) {
//                printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
//            }
//        }

        int cnt = 0, sum = 0;
        for(int i = 1; i <= 100; ++i) {
            for(int j = 1; j <= 100; ++j) {
                if(i == j || dp[i][j] == INF) continue;
                ++cnt; sum += dp[i][j];
            }
        }
        printf("Case %d: average length between pages = %.3f clicks\n", ++kase,
               1.0 * sum / cnt);
    }
    return 0;
}
