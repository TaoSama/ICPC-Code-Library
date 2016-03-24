//
//  Created by TaoSama on 2015-08-12
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

int n, m, p[35];
int f[35][105], g[35][105];
//dp[i][j]:= i people look after j storages max safe, min wage

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &m, &n) == 2 && (n || m)) {
        for(int i = 1; i <= n; ++i) scanf("%d", p + i);

        memset(f, 0, sizeof f);
        f[0][0] = INF; //initialization is so difficult!
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j <= m; ++j) {
                f[i][j] = f[i - 1][j]; //zero exception
                for(int k = 1; k <= p[i] && k <= j; ++k)
                    f[i][j] = max(f[i][j], min(f[i - 1][j - k], p[i] / k));
            }
        }
        int L = f[n][m];
        if(!L) {printf("0 0\n"); continue;}

        memset(g, 0x3f, sizeof g);
        g[0][0] = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j <= m; ++j) {
                g[i][j] = g[i - 1][j];
                for(int k = 1; k <= p[i] && k <= j; ++k) {
                    int s = p[i] / k;  //at least
                    if(s >= f[n][m]) g[i][j] = min(g[i][j], g[i - 1][j - k] + p[i]);
                }
            }
        }
        int Y = g[n][m];
        printf("%d %d\n", L, Y);
    }
    return 0;
}
