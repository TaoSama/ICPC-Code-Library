//
//  Created by TaoSama on 2015-07-29
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

int n, cnt, g[20][20];
bool vis[20];

bool isLine(int s) { //one chain can't link more than 2 chains
    for(int i = 0; i < n; ++i) {
        if(s >> i & 1) continue;
        int cnt = 0;
        for(int j = 0; j < n; ++j) {
            if(s >> j & 1) continue;
            if(g[i][j]) cnt++;
            if(cnt > 2) return false;
        }
    }
    return true;
}

bool dfs(int s, int u, int f) {
    vis[u] = true;
    for(int v = 0; v < n; ++v) {
        if(s >> v & 1 || !g[u][v] || v == f) continue;
        if(vis[v]) return true;
        if(dfs(s, v, u)) return true;
    }
    return false;
}

bool isCycle(int s) {
    memset(vis, false, sizeof vis);
    for(int i = 0; i < n; ++i) {
        if(s >> i & 1 || vis[i]) continue;
        ++cnt; // the number of connected components
        if(dfs(s, i, -1)) return true;
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d", &n) == 1 && n) {
        memset(g, false, sizeof g);
        int u, v;
        while(scanf("%d%d", &u, &v) && ~u) {
            g[u - 1][v - 1] = g[v - 1][u - 1] = true;
        }
        int ans = INF;
        for(int i = 0; i < 1 << n; ++i) {
            cnt = 0;
            if(!isLine(i) || isCycle(i)) continue;
            int cur = __builtin_popcount(i);
            if(cur >= cnt - 1) ans = min(ans, cur);
        }
        printf("Set %d: Minimum links to open is %d\n", ++kase, ans);
    }
    return 0;
}
