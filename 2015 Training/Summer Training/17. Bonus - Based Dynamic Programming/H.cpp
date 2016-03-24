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

int n, m, a[105][105], dp[105][105];

int dfs(int x, int y) {
    int &ret = dp[x][y];
    if(ret >= 0)  return ret;

    ret = 0;
    for(int i = 0; i <= a[x][y]; ++i) {
        for(int j = 0; j <= a[x][y] - i; ++j) {
            int nx = x + i, ny = y + j;
            if(nx < 1 || nx > n || ny < 1 || ny > m)
                continue;
            ret = (ret + dfs(nx, ny)) % 10000;
        }
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                scanf("%d", &a[i][j]);

        memset(dp, -1, sizeof dp);
        dp[n][m] = 1;
        printf("%d\n", dfs(1, 1));
    }
    return 0;
}
