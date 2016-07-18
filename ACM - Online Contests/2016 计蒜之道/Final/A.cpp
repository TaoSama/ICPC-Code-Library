//
//  Created by TaoSama on 2016-07-03
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
const int N = 300 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int f[10][N][N];

#define rep(i, l, r) for(int i = l; i <= r; ++i)
typedef long long LL;

void floyd(int d, int l, int r) {
    rep(k, l, r) rep(i, 1, n) rep(j, 1, n)
    f[d][i][j] = min(f[d][i][j], f[d][i][k] + f[d][k][j]);
}

void dfs(int d, int l, int r, LL& ans) {
    if(l == r) {
//      prln(l);
//      rep(i, 1, n) rep(j, 1, n) printf("f[%d][%d] = %d\n", i, j, f[d][i][j]);
        rep(i, 1, n) rep(j, 1, n)
        if(i != l && j != l) {
            ans += f[d][i][j] == INF ? -1 : f[d][i][j];
//            printf("f[%d][%d] = %d\n", i, j, f[d][i][j]);
        }
        return;
    }
    int m = l + r >> 1;

    rep(i, 1, n) rep(j, 1, n) f[d + 1][i][j] = f[d][i][j];
    floyd(d + 1, l, m);
    dfs(d + 1, m + 1, r, ans);

    rep(i, 1, n) rep(j, 1, n) f[d + 1][i][j] = f[d][i][j];
    floyd(d + 1, m + 1, r);
    dfs(d + 1, l, m, ans);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d", &n) == 1) {
        rep(i, 1, n) rep(j, 1, n) {
            scanf("%d", f[0][i] + j);
            if(f[0][i][j] == -1) f[0][i][j] = INF;
        }

        LL ans = 0;
        dfs(0, 1, n, ans);
        printf("%lld\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
