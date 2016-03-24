//
//  Created by TaoSama on 2015-08-23
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

int n;
int dp[10005][10005][2];
int wh[10005], tim[10005];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d%d", wh + i, tim + i);

        //0->left 1->right
        for(int i = n; i >= 1; --i) {
            for(int j = i; j <= n; ++j) {
                dp[i][j][0] = dp[i][j][1] = INF;
                if(i + 1 <= n) dp[i][j][0] = min(dp[i][j][0],
                                                     dp[i + 1][j][0] + wh[i + 1] - wh[i]);
                if(i + 1 <= n) dp[i][j][0] = min(dp[i][j][0], dp[i + 1][j][1] + wh[j] - wh[i]);
                if(dp[i][j][0] >= tim[i]) dp[i][j][0] = INF;
                if(j - 1 >= 1) dp[i][j][1] = min(dp[i][j][1],
                                                     dp[i][j - 1][1] + wh[j] - wh[j - 1]);
                if(j - 1 >= 1) dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][0] + wh[j] - wh[i]);
                if(dp[i][j][1] >= tim[j]) dp[i][j][1] = INF;
            }
        }
        int ans = min(dp[1][n][0], dp[1][n][1]);
        if(ans == INF) puts("No solution");
        else printf("%d\n", ans);
    }
    return 0;
}
