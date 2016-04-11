//
//  Created by TaoSama on 2015-10-09
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
const int N = 2e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, f, c[105];
double dp[N];
bool vis[N];

double get(int x) {
    return floor((1.0 + sqrt(5)) / 2.0 * x * x);
}

double dfs(int f) {
    if(vis[f]) return dp[f];
    vis[f] = true;
    dp[f] = 0;
    for(int i = 1; i <= n; ++i) {
        if(f > c[i]) dp[f] += get(c[i]);
        else dp[f] += 1 + dfs(f + c[i]);
    }
    dp[f] /= n;
    return dp[f];
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &f) == 2) {
        for(int i = 1; i <= n; ++i) scanf("%d", c + i);
        memset(vis, false, sizeof vis);
        printf("%.3f\n", dfs(f));
    }
    return 0;
}
