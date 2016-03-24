//
//  Created by TaoSama on 2015-11-21
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

int n, m, a[1005][1005], dp[1005][1005];

void getMin(int &x, int y) {
    x = min(x, y);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                scanf("%d", &a[i][j]);
        memset(dp, 0x3f, sizeof dp);
        if(m > 1) dp[1][2] = a[1][1] * a[1][2];
        if(n > 1) dp[2][1] = a[1][1] * a[2][1];
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(dp[i][j] == INF) continue;
                if(j + 2 <= m)
                    getMin(dp[i][j + 2], dp[i][j] + a[i][j + 1] * a[i][j + 2]);
                if(i + 2 <= n)
                    getMin(dp[i + 2][j], dp[i][j] + a[i + 1][j] * a[i + 2][j]);
                if(i + 1 <= n && j + 1 <= m) {
                    getMin(dp[i + 1][j + 1], dp[i][j] + a[i][j + 1] * a[i + 1][j + 1]);
                    getMin(dp[i + 1][j + 1], dp[i][j] + a[i + 1][j] * a[i + 1][j + 1]);
                }
            }
        }
        printf("%d\n", dp[n][m]);
    }
    return 0;
}
