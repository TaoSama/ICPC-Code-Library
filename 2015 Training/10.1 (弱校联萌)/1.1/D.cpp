//
//  Created by TaoSama on 2015-10-01
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

int n, m;
vector<int> G[505];

int match[505];
bool vis[505];
bool dfs(int u) {
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(vis[v]) continue;
        vis[v] = true;
        if(match[v] < 0 || dfs(match[v])) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}


int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        int ans = 0;
        memset(match, -1, sizeof match);
        for(int i = 1; i <= n; ++i) {
            if(~match[i]) continue;
            memset(vis, false, sizeof vis);
            ans += dfs(i);
        }
        printf("%d\n", ans);
    }
    return 0;
}
