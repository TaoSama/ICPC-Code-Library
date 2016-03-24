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

int n, p[N], t[N];
int dp[10005][10005][2]; //[i,j][0] over by left, [1] for right

int dfs(int l, int r, bool rig) {
    int &ret = dp[l][r][rig];
    if(ret >= 0) return ret;
    if(l > r) return INF;
    if(l == r) return 0;

    ret = INF;
    if(rig) {
        int tim = min(dfs(l, r - 1, 0) + p[r] - p[l],
                      dfs(l, r - 1, 1) + p[r] - p[r - 1]);
        if(tim <= t[r]) ret = min(ret, tim);
    } else {
        int tim = min(dfs(l + 1, r, 0) + p[l + 1] - p[l],
                      dfs(l + 1, r, 1) + p[r] - p[l]);
        if(tim <= t[l]) ret = min(ret, tim);
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d%d", p + i, t + i);

        int cur, ans;
        for(int i = n; i >= 1; --i) {
            for(int j = i + 1; j <= n; ++j) {
                dp[i][j][0] = dp[i][j][1] = INF;
                cur = min(dp[i + 1][j][0] + p[i + 1] - p[i],
                          dp[i + 1][j][1] + p[j] - p[i]);
                if(cur < t[i]) dp[i][j][0] = min(dp[i][j][0], cur); //before!
                cur = min(dp[i][j - 1][0] + p[j] - p[i],
                          dp[i][j - 1][1] + p[j] - p[j - 1]);
                if(cur < t[j]) dp[i][j][1] = min(dp[i][j][1], cur);
            }
        }

        ans = min(dp[1][n][0], dp[1][n][1]);
        if(ans == INF) puts("No solution");
        else printf("%d\n", ans);
    }
    return 0;
}
