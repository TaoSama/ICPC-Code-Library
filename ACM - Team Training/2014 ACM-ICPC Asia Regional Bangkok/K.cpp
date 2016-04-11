//
//  Created by TaoSama on 2015-12-12
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

int n, m, p[105][55], c[105][105];
int dp[55][105];

inline void getMax(int &x, int y) {
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
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                scanf("%d", &p[i][j]);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                scanf("%d", &c[i][j]);

        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= n; ++i) dp[1][i] = p[i][1];
        for(int i = 2; i <= m; ++i)
            for(int j = 1; j <= n; ++j)
                for(int k = 1; k <= n; ++k)
                    getMax(dp[i][j], dp[i - 1][k] + p[j][i] - c[k][j]);

        int ans = *max_element(dp[m], dp[m] + n + 1);
        printf("%d\n", ans);

    }
    return 0;
}
