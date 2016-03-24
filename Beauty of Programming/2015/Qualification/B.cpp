//
//
//
//  Created by TaoSama on 2015-04-17
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 100007;
const int N = 1e5 + 10;

int dp[1005][1005];
char a[1005];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif

    int kase = 0;
    int t; cin >> t;
    while(t--) {
        cin >> (a + 1);
        int n = strlen(a + 1);
        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= n; ++i)
            dp[i][i] = 1;
        for(int i = n; i >= 1; --i) {
            for(int j = i + 1; j <= n; ++j) {
                if(a[i] == a[j])
                    dp[i][j] = (0LL + dp[i + 1][j] +
                                dp[i][j - 1] + 1) % MOD;
                else
                    dp[i][j] = (0LL + dp[i + 1][j] + dp[i][j - 1] -
                                dp[i + 1][j - 1] + MOD) % MOD;
            }
        }
        cout << "Case #" << ++kase << ": " << dp[1][n] << endl;
    }
    return 0;
}
