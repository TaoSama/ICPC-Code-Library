//
//  Created by TaoSama on 2016-02-05
//  Copyright (c) 2016 TaoSama. All rights reserved.
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
const int N = 5e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int g[N][N], col[N];
char ans[N];
vector<int> G[N];

bool dfs(int u, int c) {
    col[u] = c;
    for(int v : G[u]) {
        if(col[v] == col[u]) return false;
        if(!col[v] && !dfs(v, -c)) return false;
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        memset(g, 0, sizeof g);
        for(int i = 1; i <= m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            g[u][v] = g[v][u] = 1;
        }
        for(int i = 1; i <= n; ++i) {
            G[i].clear();
            for(int j = 1; j <= n; ++j)
                if(i != j && !g[i][j]) G[i].push_back(j);
        }

        bool yes = true;
        memset(col, 0, sizeof col);
        for(int i = 1; i <= n; ++i) {
            if(!col[i] && G[i].size() && !dfs(i, 1)) {
                yes = false;
                break;
            }
        }
//        for(int i = 1; i <= n; ++i) printf("col[%d]=%d\n", i, col[i]);
//        printf("col : %d\n", yes);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(i == j) continue;
                if(g[i][j] && col[i] * col[j] < 0) yes = false;
                if(!g[i][j] && col[i] * col[j] >= 0) yes = false;
            }
        }

        if(!yes) {puts("No"); continue;}
        puts("Yes");
        for(int i = 1; i <= n; ++i) putchar("abc"[col[i] + 1]);
        puts("");
    }
    return 0;
}
