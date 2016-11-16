//
//  Created by TaoSama on 2016-11-16
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, c1[N], c2[N];
vector<int> G[N], T[N];
int id[N];

void dfs(int u, int k, int c) {
    id[u] = k; c2[k] = c;
    for(int v : G[u]) {
        if(id[v] || c1[v] != c) continue;
        dfs(v, k, c);
    }
}

int f[N][2];

void dfs2(int u, int f, int d, pair<int, int>& diameter) {
    diameter = max(diameter, {d, u});
    for(int v : T[u]) {
        if(v == f) continue;
        dfs2(v, u, d + 1, diameter);
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", c1 + i);
        for(int i = 1; i <= n; ++i) G[i].clear(), T[i].clear();

        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        int k = 0;
        memset(id, 0, sizeof id);
        for(int i = 1; i <= n; ++i) {
            if(id[i]) continue;
            dfs(i, ++k, c1[i]);
        }
        for(int i = 1; i <= n; ++i) {
            int u = id[i];
            for(int j : G[i]) {
                int v = id[j];
                if(u == v) continue;
                T[u].push_back(v);
            }
        }

        pair<int, int> diameter = { -INF, -INF};
        dfs2(1, 0, 0, diameter);
        dfs2(diameter.second, 0, 0, diameter);

        int ans = diameter.first + 1 >> 1;
        printf("%d\n", ans);
    }

    return 0;
}
