//
//  Created by TaoSama on 2015-05-14
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e6 + 10;

int n, m, l, r;
double dp[2][205];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d%d", &n, &m, &l, &r) == 4 && (n + m + l + r)) {

        for(int i = 0; i < n; ++i) dp[0][i] = 0;
        dp[0][0] = 1;
        for(int i = 1; i <= m; ++i) {
            int x; scanf("%d", &x);
            memset(dp[i & 1], 0, n * sizeof(double));
            for(int j = 0; j < n; ++j) {
                while(x >= n) x -= n;
                int t = j + x;
                while(t >= n) t -= n;
                dp[i & 1][t] += dp[(i - 1) & 1][j] * 0.5;
                t = j + n - x;
                while(t >= n) t -= n;
                dp[i & 1][t] += dp[(i - 1) & 1][j] * 0.5;
                //dp[(i - 1) & 1][j] = 0;
            }
        }
        double ans = 0;
        for(int i = l - 1; i < r; ++i)
            ans += dp[m & 1][i];
        printf("%.4f\n", ans);
    }
    return 0;
}
