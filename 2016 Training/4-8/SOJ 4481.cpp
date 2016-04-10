//
//  Created by TaoSama on 2016-04-09
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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

int n;
double a[1 << 7][1 << 7], f[7][1 << 7];

void dfs(int n, int l, int r) { // [l, r]
    if(l == r) {
        f[n][l] = 1;
        return;
    }
    int m = l + r >> 1;
    dfs(n - 1, l, m);
    dfs(n - 1, m + 1, r);
    for(int i = l; i <= r; ++i) f[n][i] = 0;
    for(int i = l; i <= m; ++i)
        for(int j = m + 1; j <= r; ++j)
            f[n][i] += f[n - 1][i] * f[n - 1][j] * a[i][j];
    for(int i = m + 1; i <= r; ++i)
        for(int j = l; j <= m; ++j)
            f[n][i] += f[n - 1][i] * f[n - 1][j] * a[i][j];
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 0; i < 1 << n; ++i)
            for(int j = 0; j < 1 << n; ++j)
                scanf("%lf", a[i] + j);

        dfs(n, 0, (1 << n) - 1);

        pair<double, int> ans = make_pair(-1, -INF);
        for(int i = 0; i < 1 << n; ++i)
            ans = max(ans, make_pair(f[n][i], -i));
        printf("%d\n", -ans.second + 1);
    }
    return 0;
}
