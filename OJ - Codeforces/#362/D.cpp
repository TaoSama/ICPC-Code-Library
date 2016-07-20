//
//  Created by TaoSama on 2016-07-15
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, sz[N];
vector<int> G[N];
double f[N];

void dfs1(int u) {
    sz[u] = 1;
    for(int v : G[u]) {
        dfs1(v);
        sz[u] += sz[v];
    }
}

void dfs2(int u) {
    for(int v : G[u]) {
        f[v] = f[u] + 1 + (sz[u] - sz[v] - 1) * 0.5;
        dfs2(v);
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 2; i <= n; ++i) {
            int f; scanf("%d", &f);
            G[f].push_back(i);
        }
        dfs1(1);
        f[1] = 1;
        dfs2(1);
        for(int i = 1; i <= n; ++i)
            printf("%.1f%c", f[i], " \n"[i == n]);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
