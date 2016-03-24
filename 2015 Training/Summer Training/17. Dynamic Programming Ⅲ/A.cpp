//
//  Created by TaoSama on 2015-08-11
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

string s;
int n, m, a[105][105];
int dp[105][105];
int d[][2] = { -1, 0, 0, -1, 0, 1, 1, 0};

int dfs(int x, int y) {
    int &ret = dp[x][y];
    if(ret >= 0) return ret;

    ret = 1;
    for(int i = 0; i < 4; ++i) {
        int nx = x + d[i][0], ny = y + d[i][1];
        if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if(a[nx][ny] < a[x][y]) ret = max(ret, dfs(nx, ny) + 1);
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> s >> n >> m;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                cin >> a[i][j];

        int ans = -INF;
        memset(dp, -1, sizeof dp);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                ans = max(ans, dfs(i, j));

        cout << s << ": " << ans << '\n';
    }
    return 0;
}
