//
//  Created by TaoSama on 2015-11-02
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

int n, a[105];
double dp[105];

double dfs(int p) {
    double& ret = dp[p];
    if(ret >= 0) return ret;
    if(p == n) return a[n];
    ret = 0;
    int to = min(6, n - p);
    for(int i = 1; i <= to; ++i)
        ret += dfs(p + i);
    ret = ret / to + a[p];
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
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        for(int i = 1; i <= n; ++i) dp[i] = -1;
        printf("Case %d: %.12f\n", ++kase, dfs(1));
    }
    return 0;
}
