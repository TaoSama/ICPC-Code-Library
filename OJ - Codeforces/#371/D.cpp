//
//  Created by TaoSama on 2016-09-14
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct SparseTable {
    static const int LOG = 10;
    int n, m;
    int LOG2[N], f[LOG][LOG][N][N];
    void init(int _n, int _m, int (*a)[N]) {
        n = _n, m = _m;
        LOG2[1] = 0;
        for(int i = 2; i < N; ++i) LOG2[i] = LOG2[i >> 1] + 1;
        for(int x = 0; x < LOG; ++x) {
            for(int y = 0; y < LOG; ++y) {
                for(int i = 1; i + (1 << x) - 1 <= n; ++i) {
                    for(int j = 1; j + (1 << y) - 1 <= m; ++j) {
                        if(x + y == 0) f[x][y][i][j] = a[i][j];
                        else if(x == 0)
                            f[x][y][i][j] = max(f[x][y - 1][i][j], f[x][y - 1][i][j + (1 << y -  1)]);
                        else if(y == 0)
                            f[x][y][i][j] = max(f[x - 1][y][i][j], f[x - 1][y][i + (1 << x - 1)][j]);
                        else
                            f[x][y][i][j] = max({f[x - 1][y - 1][i + (1 << x - 1)][j], f[x - 1][y - 1][i][j + (1 << y - 1)],
                                                 f[x - 1][y - 1][i][j], f[x - 1][y - 1][i + (1 << x - 1)][j + (1 << y - 1)]
                                                });
                    }
                }
            }
        }
    }
    int RMQ(int x1, int y1, int x2, int y2) {
        int k1 = LOG2[x2 - x1 + 1], k2 = LOG2[y2 - y1 + 1];
        return max({f[k1][k2][x1][y1], f[k1][k2][x2 - (1 << k1) + 1][y2 - (1 << k2) + 1],
                    f[k1][k2][x1][y2 - (1 << k2) + 1], f[k1][k2][x2 - (1 << k1) + 1][y1]
                   });
    }
} st;

int n, m, q;
int a[N][N];
int sum[N][N], maxv[N][N];

int getRectSum(int x1, int y1, int x2, int y2) {
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            scanf("%d", a[i] + j);

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + a[i][j];

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            int l = 0, r = min(n - i + 1, m - j + 1), side = -1;
            while(l <= r) {
                int m = l + r >> 1;
                if(getRectSum(i, j, i + m - 1, j + m - 1) == m * m)
                    side = m, l = m + 1;
                else r = m - 1;
            }
            maxv[i][j] = side;
        }
    }

    st.init(n, m, maxv);

    scanf("%d", &q);
    while(q--) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        int l = 0, r = min(x2 - x1 + 1, y2 - y1 + 1), ans = -1;
        while(l <= r) {
            int m = l + r >> 1;
            if(st.RMQ(x1, y1, x2 - m + 1, y2 - m + 1) >= m) ans = m, l = m + 1;
            else r = m - 1;
        }
        printf("%d\n", ans);
    }

    return 0;
}
