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

int n, m, k;
bool cherry[25][25];
int c[25][25][25][25];

int check(int u, int d, int l, int r) {
    int cnt = 0;
    for(int i = u; i < d; ++i)
        for(int j = l; j < r; ++j)
            if(cherry[i][j]) ++cnt;
//  pr(u); pr(d); pr(l); pr(r); prln(cnt);
    return cnt;
}

void gao() {
    memset(c, 0, sizeof c);
    for(int u = 1; u <= n + 1; ++u)
        for(int d = u + 1; d <= n + 1; ++d)
            for(int l = 1; l <= m + 1; ++l)
                for(int r = l + 1; r <= m + 1; ++r)
                    c[u][d][l][r] = check(u, d, l, r);


}

int dp[25][25][25][25];

int dfs(int u, int d, int l, int r) {
    int &ret = dp[u][d][l][r];
    if(ret >= 0) return ret;

    int cherry = c[u][d][l][r];
    if(cherry == 1) return 0;
    if(cherry == 0) return INF;

    ret = INF;
    for(int i = u + 1; i < d; ++i) //slice horizontally
        ret = min(ret, dfs(u, i, l, r) + dfs(i, d, l, r) + r - l);
    for(int i = l + 1; i < r; ++i) //slice vertically
        ret = min(ret, dfs(u, d, l, i) + dfs(u, d, i, r) + d - u);
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d%d%d", &n, &m, &k) == 3) {
        memset(cherry, false, sizeof cherry);
        for(int i = 1; i <= k; ++i) {
            int x, y; scanf("%d%d", &x, &y);
            cherry[x][y] = true;
        }

        gao();
        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n", ++kase, dfs(1, n + 1, 1, m + 1));
    }
    return 0;
}
