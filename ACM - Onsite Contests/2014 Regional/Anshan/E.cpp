//
//  Created by TaoSama on 2015-10-10
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

int n, m, a[55][55], b[105];
int dp[105][55];

void getMax(int &x, int y) {
    x = max(x, y);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= m; ++j)
                scanf("%d", &a[i][j]);
        for(int i = 1; i <= n; ++i) scanf("%d", b + i);
        memset(dp, 0, sizeof dp);
        for(int i = 1; i < n; ++i) {
            if(b[i] < 0) {
                for(int j = 1; j <= m; ++j) {
                    if(b[i + 1] < 0) {
                        for(int k = 1; k <= m; ++k)
                            getMax(dp[i + 1][k], dp[i][j] + a[j][k]);
                    } else getMax(dp[i + 1][b[i + 1]], dp[i][j] + a[j][b[i + 1]]);
                }
            } else {
                if(b[i + 1] < 0) {
                    for(int k = 1; k <= m; ++k)
                        getMax(dp[i + 1][k], dp[i][b[i]] + a[b[i]][k]);
                } else getMax(dp[i + 1][b[i + 1]], dp[i][b[i]] + a[b[i]][b[i + 1]]);
            }
        }
        int ans = 0;
        for(int i = 1; i <= m; ++i) getMax(ans, dp[n][i]);
        printf("%d\n", ans);
    }
    return 0;
}



