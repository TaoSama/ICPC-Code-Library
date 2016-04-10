//
//  Created by TaoSama on 2015-10-27
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

int n, a[16][16], dp[16][1 << 16];

int dfs(int i, int s) {
    int& ret = dp[i][s];
    if(i == n) return 0;
    if(~ret) return ret;
    ret = 0;
    for(int k = 0; k < n; ++k) {
        if(s >> k & 1) continue;
        ret = max(ret, dfs(i + 1, s | 1 << k) + a[i][k]);
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
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                scanf("%d", &a[i][j]);
        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n", ++kase, dfs(0, 0));
    }
    return 0;
}
