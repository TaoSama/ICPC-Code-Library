//
//  Created by TaoSama on 2015-11-26
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

int n, m, a[105][105];
int dp[105][105][205];

void getMax(int &x, int y) {
    x = max(x, y);
}

int get(int i, int j, int k) {
    if(i == j) return a[i][k - i];
    return a[i][k - i] + a[j][k - j];
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
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                scanf("%d", &a[i][j]);

        memset(dp, 0, sizeof dp);
        dp[1][1][2] = a[1][1];
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(i == j && i != 1) continue;
                for(int k = max(i, j); k <= n + m; ++k) {
                    if(!dp[i][j][k]) continue;
//                  printf("dp[%d][%d][%d] = %d\n", i, j, k, dp[i][j][k]);
                    getMax(dp[i][j][k + 1], dp[i][j][k] + get(i, j, k + 1));
                    getMax(dp[i + 1][j + 1][k + 1], dp[i][j][k] + get(i + 1, j + 1, k + 1));
                    getMax(dp[i + 1][j][k + 1], dp[i][j][k] + get(i + 1, j, k + 1));
                    getMax(dp[i][j + 1][k + 1], dp[i][j][k] + get(i, j + 1, k + 1));
                }
            }
        }
        printf("Case %d: %d\n", ++kase, dp[n][n][n + m]);
    }
    return 0;
}
