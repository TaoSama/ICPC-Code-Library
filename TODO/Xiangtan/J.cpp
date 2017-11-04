//
//  Created by TaoSama on 2017-05-14
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 500 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int a[N], b[N];

inline void addMod(int& x, int y) {if((x += y) >= MOD) x -= MOD;}

struct BIT {
    int b[N][N];
    void init() {
        memset(b, 0, sizeof b);
    }
    void add(int x, int y, int v) {
        for(int i = x; i <= m; i += i & -i) addMod(b[i][y], v);
    }
    int sum(int x, int y) {
        int ret = 0;
        for(int i = x; i; i -= i & -i) addMod(ret, b[i][y]);
        return ret;
    }
    int sum(int l, int r, int y) {
        int ret = 0;
        addMod(ret, sum(r, y));
        addMod(ret, MOD - sum(l - 1, y));
        return ret;
    }
} bit[2][21];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = n; i; --i) scanf("%d", a + i);
        for(int j = m; j; --j) scanf("%d", b + j);

        //0: min max 1: max min
        for(int i = 1; i <= n; ++i) bit[0][i].init(), bit[1][i].init();
        bit[0][1].add(b[1], b[1], 1);
        bit[1][1].add(b[1], b[1], 1);
        for(int i = 2; i <= m; ++i) {
            for(int j = n; j >= 2; --j) {
                if(a[j] == 0) {
                    for(int k = 1; k <= m; ++k) {
                        int sum = bit[0][j - 1].sum(b[i], m, k);
                        bit[0][j].add(b[i], k, sum);
                        bit[1][j].add(k, b[i], sum);
                    }
                } else {
                    for(int k = 1; k <= m; ++k) {
                        int sum = bit[1][j - 1].sum(1, b[i], k);
                        bit[1][j].add(b[i], k, sum);
                        bit[0][j].add(k, b[i], sum);
                    }
                }
            }
            bit[0][1].add(b[i], b[i], 1);
            bit[1][1].add(b[i], b[i], 1);
//            for(int j = 1; j <= n; ++j) {
//                for(int k = 1; k <= m; ++k) {
//                    for(int l = 1; l <= m; ++l)
//                        if(bit[0][j].sum(k, k, l))
//                            printf("f[%d][%d][%d][%d] = %d\n",
//                                   i, j, k, l,
//                                   bit[0][j].sum(k, k, l));
//                }
//            }
        }
        int ans = 0;
        for(int i = 1; i <= m; ++i) addMod(ans, bit[0][n].sum(1, m, i));
        printf("%d\n", ans);
    }

    return 0;
}
