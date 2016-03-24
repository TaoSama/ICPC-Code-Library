//
//  Created by TaoSama on 2015-08-10
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

int n, x[20], y[20], ps[20][20];
int dp[1 << 16];

bool check(int i, int j, int k) {
    return (x[i] - x[j]) * (y[i] - y[k]) == (x[i] - x[k]) * (y[i] - y[j]);
}

void gao() {
    memset(ps, 0, sizeof ps);
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            for(int k = 0; k < n; ++k) {
                if(check(i, j, k)) ps[i][j] |= 1 << k;
            }
        }
    }
}

int dfs(int s) {
    int &ret = dp[s];
    if(ret != INF) return ret;
    int cnt = __builtin_popcount(s);
    if(cnt == 0) return 0;
    if(cnt <= 2) return 1;

    int i = __builtin_ctz(s);
    for(int j = i + 1; j < n; ++j)
        if(s >> j & 1) ret = min(ret, dfs(s ^ (s & ps[i][j])) + 1);

    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) scanf("%d%d", x + i, y + i);
        gao();

        memset(dp, 0x3f, sizeof dp);
        printf("Case %d: %d\n", ++kase, dfs((1 << n) - 1));
    }
    return 0;
}
