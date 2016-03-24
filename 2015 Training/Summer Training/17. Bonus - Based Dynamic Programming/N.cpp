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

int n, k, a[105][105];
int dp[105][105];
int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};

int dfs(int x, int y) {
    int &ret = dp[x][y];
    if(ret >= 0) return ret;

//  cout << x << ' ' << y << endl;

    int maxv = 0;
    for(int j = 1; j <= k; ++j) {
        for(int i = 0; i < 4; ++i) {
            int nx = x + j * d[i][0], ny = y + j * d[i][1];
            if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if(a[nx][ny] > a[x][y]) maxv = max(maxv, dfs(nx, ny));
        }
    }
    ret = a[x][y] + maxv;
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &k) == 2 && (~n || ~k)) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j)
                scanf("%d", &a[i][j]);
        }

        memset(dp, -1, sizeof dp);
        printf("%d\n", dfs(1, 1));
    }
    return 0;
}
