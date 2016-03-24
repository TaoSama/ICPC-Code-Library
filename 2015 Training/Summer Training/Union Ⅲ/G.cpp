//
//  Created by TaoSama on 2015-08-26
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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

int n, x[2005], y[2005];
bool vis[2005];
vector<int> G[2005];

int p[2005];
int find(int x) {
    return p[x] = p[x] == x ? x : find(p[x]);
}
bool unite(int x, int y) {
    x = find(x); y = find(y);
    if(x == y) return false;
    p[x] = y;
    return true;
}

void dfs(int u, int f) {
    vis[u] = true;
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
//      printf("%d->%d\n", u, v);
        if(vis[v]) continue;
        dfs(v, u);
    }
    if(~f) {
        printf("(%d, %d) ", x[u], y[u]);
        if(x[u] == x[f]) {
            if(y[u] < y[f]) puts("UP");
            else puts("DOWN");
        } else {
            if(x[u] < x[f]) puts("RIGHT");
            else puts("LEFT");
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) {
            p[i] = i;
            vis[i] = false;
            G[i].clear();
        }
        int ans = n;
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d", x + i, y + i);
            for(int j = 1; j < i; ++j) {
                if(x[i] == x[j] || y[i] == y[j]) {
                    G[i].push_back(j);
                    G[j].push_back(i);
                    ans -= unite(i, j);
                }
            }
        }
        printf("%d\n", ans);
        for(int i = 1; i <= n; ++i)
            if(p[i] == i) dfs(i, -1);
    }
    return 0;
}
