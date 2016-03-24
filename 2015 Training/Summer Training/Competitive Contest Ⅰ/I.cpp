//
//  Created by TaoSama on 2015-08-21
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

int n, m;
long long dp[35][35][105];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d%d", &n, &m);

        if((n & 1) || m == 0) {
            printf("Case %d: 0\n", ++kase);
            continue;
        }

        memset(dp, 0, sizeof dp);
        n >>= 1;
        dp[0][1][1 % m] = 1;
        for(int i = 0; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                for(int k = 0; k < m; ++k) {
                    if(i + 1 <= n) dp[i + 1][j][(k << 1) % m] += dp[i][j][k];
                    if(j + 1 <= n) dp[i][j + 1][(k << 1 | 1) % m] += dp[i][j][k];
                }
            }
        }
        printf("Case %d: %lld\n", ++kase, dp[n][n][0]);
    }
    return 0;
}
