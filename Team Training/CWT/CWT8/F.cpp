//
//  Created by TaoSama on 2016-02-02
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int N = 5e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int f[N][N][2], g[2][N][2], leaves[N]; //leaf to 1
vector<int> G[N];

void getMin(int &x, int y) {
    if(x > y) x = y;
}

void see(int u) {
    printf("%d:\n", u);
    for(int i = 0; i <= leaves[u]; ++i)
        for(int j = 0; j < 2; ++j)
            printf("f[%d][%d]=%d\n", i, j, f[u][i][j]);
    puts("");
}

void dfs(int u, int fa) {
    leaves[u] = 0;
    if(G[u].size() == 1) {
        leaves[u] = 1;
        f[u][0][0] = f[u][1][1] = 0;
        f[u][0][1] = f[u][1][0] = INF;
//      see(u);
        return;
    }
    for(int v : G[u]) {
        if(v == fa) continue;
        dfs(v, u);
    }

    int p = 0;
    g[p][0][0] = g[p][0][1] = 0;
    for(int v : G[u]) {
        if(v == fa) continue;
        memset(g[!p], 0x3f, sizeof g[!p]);
        for(int i = 0; i <= leaves[u]; ++i)
            for(int j = 0; j <= leaves[v]; ++j)
                for(int a = 0; a < 2; ++a)
                    for(int b = 0; b < 2; ++b)
                        getMin(g[!p][i + j][a], g[p][i][a] + f[v][j][b] + (a != b));
        p = !p;
        leaves[u] += leaves[v];
    }
    memcpy(f[u], g[p], sizeof g[p]);
//  see(u);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        if(n == 2) {puts("1"); continue;}
        for(int i = 1; i <= n; ++i) {
            if(G[i].size() > 1) {
//              printf("root:%d\n", i);
                dfs(i, -1);
                int cnt = leaves[i] >> 1;
                int ans = min(f[i][cnt][0], f[i][cnt][1]);
                printf("%d\n", ans);
                break;
            }
        }
    }
    return 0;
}
