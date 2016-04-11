//
//  Created by TaoSama on 2016-02-29
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

int n, c, val[N], trap[N];
vector<int> G[N];

LL f[N][5][2],
ans; //u为根子树, 起点有无陷阱, 且经过j个陷阱的最大值

void getMax(LL& x, LL y) {
    if(y > x) x = y;
}

void dfs(int u, int fa) {
    f[u][trap[u]][trap[u]] = val[u];
//  getMax(ans, val[u]);   n >= 2 no need to concern single node
    for(int v : G[u]) {
        if(v == fa) continue;
        dfs(v, u);
        for(int i = 0; i <= c; ++i) {
            for(int j = 0; i + j <= c; ++j) {
                getMax(ans, f[u][i][1] + f[v][j][1]);
                if(i < c) getMax(ans, f[u][i][0] + f[v][j][1]);
                if(j < c) getMax(ans, f[u][i][1] + f[v][j][0]);
                if(i + j < c) getMax(ans, f[u][i][0] + f[v][j][0]);
            }
        }
        for(int i = 0; i <= c; ++i) {
            if(i < c) getMax(f[u][i + trap[u]][0], f[v][i][0] + val[u]);
            getMax(f[u][i + trap[u]][1], f[v][i][1] + val[u]);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &c);
        for(int i = 1; i <= n; ++i) {
            G[i].clear();
            scanf("%d%d", val + i, trap + i);
        }
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[++u].push_back(++v);
            G[v].push_back(u);
        }

        ans = 0;
        memset(f, 0xc0, sizeof f);
        dfs(1, -1);
        printf("%I64d\n", ans);
    }
    return 0;
}
