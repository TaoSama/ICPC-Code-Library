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

int n, m, a[505][505], b[505][505], dp[505][505];

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
        for(int i = 1; i <= n; ++i) { //U to west
            for(int j = 1; j <= m; ++j) {
                int x; scanf("%d", &x);
                a[i][j] = a[i][j - 1] + x;
            }
        }
        for(int i = 1; i <= n; ++i) { //R to north
            for(int j = 1; j <= m; ++j) {
                int x; scanf("%d", &x);
                b[i][j] = b[i - 1][j] + x;
            }
        }
        memset(dp, 0, sizeof dp);  //(1,1)~(i,j) rectangle
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                dp[i][j] = max(dp[i - 1][j] + a[i][j], dp[i][j - 1] + b[i][j]);
        printf("Case %d: %d\n", ++kase, dp[n][m]);
    }
    return 0;
}
