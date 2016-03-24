//
//  Created by TaoSama on 2015-09-01
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

int n, a[205], b[205];
int dp[205][205];

int dfs(int l, int r) {
    int &ret = dp[l][r];
    if(ret >= 0) return ret;
    if(l > r) return 0;

    ret = 0;
    int minv = INF;
    for(int i = l; i <= r; ++i)
        minv = min(minv, dfs(l, i - 1) + dfs(i + 1, r) + a[i] + b[l - 1] + b[r + 1]);
    ret += minv;
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
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        for(int i = 1; i <= n; ++i) scanf("%d", b + i);
        b[n + 1] = 0;
        memset(dp, -1, sizeof dp);
        printf("Case #%d: %d\n", ++kase, dfs(1, n));
    }
    return 0;
}
