//
//  Created by TaoSama on 2015-05-23
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
const int N = 1e5 + 10;

int n, m, k, a[105][105], dp[105][105][105];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m >> k) {
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                cin >> a[i][j];
        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                for(int c = 0; c <= k; ++c) {
                    if(c >= a[i][j]) {
                        dp[i][j][c] = max(dp[i][j][c], max(dp[i - 1][j][c],
                                                           dp[i - 1][j][c - a[i][j]] + a[i][j]));
                        dp[i][j][c] = max(dp[i][j][c], max(dp[i][j - 1][c],
                                                           dp[i][j - 1][c - a[i][j]] + a[i][j]));
                    } else {
                        dp[i][j][c] = dp[i - 1][j][c];
                        dp[i][j][c] = dp[i][j - 1][c];
                    }
                }
            }
        }
        cout << *max_element(&dp[n][m][1], &dp[n][m][k + 1]) << '\n';
    }
    return 0;
}
