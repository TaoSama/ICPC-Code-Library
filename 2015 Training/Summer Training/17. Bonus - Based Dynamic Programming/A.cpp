//
//  Created by TaoSama on 2015-08-08
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

int n, dp[5][35000];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for(int i = 1; i <= 3; ++i) {
            for(int j = 0; j <= n; ++j)
                if(j >= i) dp[i][j] += dp[i - 1][j] + dp[i][j - i];
                else  dp[i][j] += dp[i - 1][j];
        }
        cout << dp[3][n] << '\n';
    }
    return 0;
}
