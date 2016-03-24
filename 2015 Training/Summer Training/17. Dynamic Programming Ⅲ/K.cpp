//
//  Created by TaoSama on 2015-08-12
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

int n, k, a[5005];
long long dp[5005][5005];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &k, &n); k += 8;
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        reverse(a + 1, a + 1 + n);

        memset(dp, 0x3f, sizeof dp);
        dp[0][0] = dp[1][0] = dp[2][0] = 0;
        for(int i = 3; i <= n; ++i) {
            for(int j = 0; j <= k; ++j) {
                if(i >= 3 * j)
                    dp[i][j] = min(dp[i - 1][j], dp[i - 2][j - 1] +
                                   1LL * (a[i] - a[i - 1]) * (a[i] - a[i - 1]));
            }
        }
        printf("%lld\n", dp[n][k]);
    }
    return 0;
}
