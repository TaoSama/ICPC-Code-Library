
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k;
vector<int> g[N];

int ans, sz[N];
void dfs(int u, int fa) {
    sz[u] = 1;
    for(int v : g[u]) {
        if(v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int stk[N], top;
void dfs2(int u, int fa) {
    // if(sz[u] >= k) {
        // int l = 1, r = top, p = r + 1;
        // while(l <= r) {
            // int m = (l + r) / 2;
            // if(stk[m] >= k) {
                // p = m;
                // r = m - 1;
            // }
            // else l = m + 1;
        // }
// //        if(u == 3) {
// //            for(int i = 1; i <= top ; ++i) printf("stk[%d] = %d,", i, stk[i]); puts("");
// //            printf("sz[1] = %d sz[2] = %d\n", sz[1], sz[2]);
// //            printf("sz[3] = %d, p = %d\n", sz[3], p);
// //        }
        // ans = max(ans, top - p + 1);
    // }
    for(int v : g[u]) if(v != fa) {
        // stk[++top] = sz[1] - sz[v];
        if(sz[v] >= k && sz[1] - sz[v] >= k) ++ans;
        dfs2(v, u);
        // --top;
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; ++i) g[i].clear();
        for(int i = 1; i < n; ++i) {
            int x, y; scanf("%d%d", &x, &y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        ans = 0;
        dfs(1, -1);
        dfs2(1, -1);
        printf("%d\n", ans);
    }
    
    return 0;
}
