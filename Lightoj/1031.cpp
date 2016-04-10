//
//  Created by TaoSama on 2015-11-13
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

int n, a[105], sum[105], dp[105][105];

int dfs(int l, int r) {
    int &ret = dp[l][r];
    if(ret != INF) return ret;
    int left = 0;
    for(int i = l; i < r; ++i) left = min(left, dfs(l, i));
    for(int i = l + 1; i <= r; ++i) left = min(left, dfs(i, r));
    ret = sum[r] - sum[l - 1] - left;
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
        for(int i = 1; i <= n; ++i) scanf("%d", a + i), sum[i] = sum[i - 1] + a[i];
        memset(dp, 0x3f, sizeof dp);
        printf("Case %d: %d\n", ++kase, 2 * dfs(1, n) - sum[n]);
    }
    return 0;
}
