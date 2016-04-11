//
//  Created by TaoSama on 2015-10-11
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
const int N = 1 << 20, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

int n, m, a[45];
LL dp[45][N];

LL dfs(int i, int w) {
    LL& ret = dp[i][w];
    if(ret >= 0) return ret;
    if(i == n + 1) return w >= m;
    ret = 0;
    ret += dfs(i + 1, w ^ a[i]);
    ret += dfs(i + 1, w);
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
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        memset(dp, -1, sizeof dp);
        printf("Case #%d: %I64d\n", ++kase, dfs(1, 0));
    }
    return 0;
}
