//
//  Created by TaoSama on 2015-09-23
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

int n, m, k;
long long dp[1 << 18][20];
int a[20], c[20][20];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &m, &k) == 3) {
        for(int i = 0; i < n; ++i) scanf("%d", a + i);
        memset(c, 0, sizeof c);
        for(int i = 1; i <= k; ++i) {
            int u, v, w; scanf("%d%d%d", &u, &v, &w);
            --u; --v;
            c[u][v] = w;
        }
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < n; ++i) dp[1 << i][i] = a[i];
        long long ans = 0;
        for(int i = 1; i < 1 << n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(dp[i][j] == -1) continue;
                for(int k = 0; k < n; ++k) {
                    if(i >> k & 1) continue;
                    dp[i | (1 << k)][k] = max(dp[i | (1 << k)][k], dp[i][j] + c[j][k] + a[k]);
                }
                if(__builtin_popcount(i) == m) ans = max(ans, dp[i][j]);
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
