//
//  Created by TaoSama on 2015-07-25
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <algorithm>
#include <cassert>
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

int n, m, t, cnt;
bool vis[1005], have[1005];
vector<int> G[1005];

void dfs(int u) {
    vis[u] = true;
    cnt += G[u].size() & 1; //count the vertex of odd degree to form a Euler path
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(vis[v]) continue;
        dfs(v);
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d%d%d", &n, &m, &t) == 3 && (n || m || t)) {
        memset(vis, false, sizeof vis);
        memset(have, false, sizeof have);
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
            have[u] = have[v] = true;
        }

        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            if(have[i] && !vis[i]) {
                cnt = 0;
                dfs(i);
                ans += max(cnt, 2); //if Euler cycle, add start and end vertex
            }
        }
        ans = max((ans - 2) / 2, 0) + m; //if no edges originally, ans = 0 forms negative
        //delete the start and end vertex, then we can use half edges to form Euler path
        cout << "Case " << ++kase << ": " << ans * t << '\n';
    }
    return 0;
}
