//
//  Created by TaoSama on 2015-12-11
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
const int N = 1e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, a[N][N];
int maxv[N][N][N], minv[N][N][N];

inline void getMax(int &x, int y) {
    x = max(x, y);
}

inline void getMin(int &x, int y) {
    x = min(x, y);
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
                scanf("%d", &a[i][j]);

        memset(minv, 0x3f, sizeof minv);
        memset(maxv, 0, sizeof maxv);
        for(int i = 0; i <= n; ++i)
            maxv[i][0][0] = minv[i][0][0] = 0;
        for(int i = 0; i <= m; ++i)
            maxv[0][i][0] = minv[0][i][0] = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                for(int k = 1; k <= min(n, m); ++k) {
                    getMin(minv[i][j][k], min(minv[i - 1][j][k], minv[i][j - 1][k]));
                    getMin(minv[i][j][k], minv[i - 1][j - 1][k - 1] + a[i][j]);
                    getMax(maxv[i][j][k], max(maxv[i - 1][j][k], maxv[i][j - 1][k]));
                    getMax(maxv[i][j][k], maxv[i - 1][j - 1][k - 1] + a[i][j]);
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= min(n, m) >> 1; ++i)
            getMax(ans, maxv[n][m][i] - minv[n][m][i << 1]);
        printf("%d\n", ans);
    }
    return 0;
}
