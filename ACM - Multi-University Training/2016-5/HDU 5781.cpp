//
//  Created by TaoSama on 2016-08-03
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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
const int N = 2e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int k, w;
double f[N][20];
bool vis[N][20];

double dfs(int k, int w) {
    double& ret = f[k][w];
    if(vis[k][w]) return ret;
    if(k == 0) ret = 0;
    else if(w == 1) ret = (1.0 * (1 + k) * k / 2 + k) / (k + 1); //1+..+k + k
    else {
        ret = INF;
        for(int i = 1; i <= k; ++i) {
            ret = min(ret, 1. * (k - i + 1) / (k + 1) * dfs(k - i, w)
                      + 1. * i / (k + 1) * dfs(i - 1, w - 1) + 1);
        }
    }
    vis[k][w] = true;
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    memset(vis, 0, sizeof vis);
    for(int i = 0; i <= 2000; ++i)
        for(int j = 1; j <= 15; ++j)
            dfs(i, j);
    while(scanf("%d%d", &k, &w) == 2) {
        w = min(w, 15);
        printf("%.6f\n", f[k][w]);
    }
    return 0;
}
