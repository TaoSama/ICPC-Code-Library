//
//  Created by TaoSama on 2016-06-05
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
const int N = 500 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];
int g[N][N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", a + i);
    memset(g, 0x3f, sizeof g);
    for(int i = 1; i <= n; ++i) g[i][i] = 0;
    for(int i = 1; i < n; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        g[u][v] = g[v][u] = 1;
    }
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

    int ans = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = i + 1; j <= n; ++j)
            if(__gcd(a[i], a[j]) == 1) ans += g[i][j];
    printf("%d\n", ans);

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
