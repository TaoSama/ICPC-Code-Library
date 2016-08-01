//
//  Created by TaoSama on 2016-07-24
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
const int N = 100 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int a[N][N], c[N], win[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        int l, r, t; scanf("%d%d%d%d", &l, &r, &t, c + i);
        for(int j = 1; j <= n; ++j) a[i][j] = INF;
        for(int j = l; j <= r; ++j) a[i][j] = t;
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        int id[N];
        for(int j = 1; j <= m; ++j) id[j] = j;
        sort(id + 1, id + 1 + m, [&](int x, int y) {
            return make_pair(a[x][i], x) < make_pair(a[y][i], y);
        });
//      pr(i); prln(id[1]);
        if(a[id[1]][i] != INF) ans += c[id[1]];
    }

    printf("%d\n", ans);


#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
