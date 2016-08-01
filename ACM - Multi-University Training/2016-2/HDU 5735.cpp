//
//  Created by TaoSama on 2016-07-25
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
const int N = (1 << 16) + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int S = 1 << 8;

typedef unsigned int UINT;
int n, w[N];
vector<int> G[N];
UINT f[N], backup[N][S], ds[S][S]; //w_fa prefix8, w_u suffix8 -> max suffix

char op[10];
UINT opt(UINT a, UINT b) {
    if(*op == 'A') return a & b;
    else if(*op == 'O') return a | b;
    return a ^ b;
}

void getMax(UINT& x, UINT y) {
    if(x == -1 || x < y) x = y;
}

void dfs(int u) {
    UINT a = w[u] >> 8, b = w[u] & 255;

    UINT tmp = 0;
    for(int i = 0; i < S; ++i)
        if(ds[i][b] != -1)
            getMax(tmp, ds[i][b] + (opt(i, a) << 8));

    f[u] = w[u] + tmp;
    memcpy(backup[u], ds[a], S << 2);
    for(int i = 0; i < S; ++i)
        getMax(ds[a][i], tmp + opt(i, b));

    for(int v : G[u]) dfs(v);
    memcpy(ds[a], backup[u], S << 2);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%s", &n, op);
        for(int i = 1; i <= n; ++i) scanf("%d", w + i);
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 2; i <= n; ++i) {
            int fa; scanf("%d", &fa);
            G[fa].push_back(i);
        }

        memset(ds, -1, sizeof ds);
        dfs(1);

        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            ans += 1LL * i * f[i] % MOD;
            if(ans >= MOD) ans -= MOD;
        }
        printf("%d\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
