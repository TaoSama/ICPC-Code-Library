//
//  Created by TaoSama on 2016-03-28
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

double f[N][20];
bool vis[N][20];

double dfs(int n, int k) {
    double& ret = f[n][k];
    if(vis[n][k]) return ret;
    vis[n][k] = 1;
    if(n == 1) return ret = 0;
    if(k == 1) return ret = (1. * n * (n - 1) / 2 + n - 1) / n;
    ret = INF;
    for(int i = 1; i < n; ++i)
        ret = min(ret, dfs(i, k - 1) * i / n + dfs(n - i, k) * (n - i) / n + 1);
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int n, k; scanf("%d%d", &n, &k);
    printf("%.5f\n", dfs(n, k));
    return 0;
}
