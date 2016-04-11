//
//  Created by TaoSama on 2015-11-20
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

int n, m, dp[16][1 << 16];
int g, x[16], y[16];
char s[25][25];

int getdis(int i, int j) {
    return max(abs(x[i] - x[j]), abs(y[i] - y[j]));
}

int dfs(int p, int s) {
    int& ret = dp[p][s];
    if(~ret) return ret;
    if(p == 0 && s == (1 << g) - 1) return 0;
    ret = INF;
    for(int i = 0; i < g; ++i) {
        if(s >> i & 1) continue;
        ret = min(ret, dfs(i, s | 1 << i) + getdis(p, i));
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d%d", &n, &m);
        g = 1;
        for(int i = 1; i <= n; ++i) {
            scanf("%s", s[i] + 1);
            for(int j = 1; j <= m; ++j) {
                if(s[i][j] == 'x') x[0] = i, y[0] = j;
                if(s[i][j] == 'g') x[g] = i, y[g++] = j;
            }
        }
        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n", ++kase, dfs(0, 0));
    }
    return 0;
}
