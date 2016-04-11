//
//
//
//  Created by TaoSama on 2015-04-16
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

int dp[15][15];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    dp[0][0] = 1;
    for(int i = 1; i <= 10; ++i) {
        for(int j = 0; j <= 10; ++j) {
            if(j - i >= 0)
                dp[i][j] = dp[i - 1][j] + dp[i][j - i];
            else
                dp[i][j] = dp[i - 1][j];
            //printf("dp[%d][%d]: %d\n",i,j,dp[i][j]);
        }
    }

    int t; cin >> t;
    while(t--) {
        int m, n; cin >> m >> n;
        cout << dp[n][m] << endl;
    }
    return 0;
}
