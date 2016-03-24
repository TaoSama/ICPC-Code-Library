//
//  Created by TaoSama on 2015-08-13
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

long long n, x, y, z, t;
long long dp[1505][1505];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int T; scanf("%d", &T);
    int kase = 0;
    while(T--) {
        scanf("%I64d%I64d%I64d%I64d%I64d", &n, &x, &y, &z, &t);
        memset(dp, 0, sizeof dp);
        long long ans = n * t * x; //all red towers, special case
        for(long long i = 1; i <= n; ++i) {

            for(long long j = 0; j <= i; ++j) {
                if(j == 0) dp[i][0] = dp[i - 1][0] + (i - 1) * y * t; //green tower
                else {
                    //blue tower (after taking into effect
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + (i - j) * y * (t + z * (j - 1)));
                    //green tower (after taking into effect
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + max(0LL, i - 1 - j) * y * (t + z * j));
                }
                //the rest are red towers
                ans = max(ans, dp[i][j] + (x + (i - j) * y) * (n - i) * (t + z * j));
            }
        }
        printf("Case #%d: %I64d\n", ++kase, ans);
    }
    return 0;
}
