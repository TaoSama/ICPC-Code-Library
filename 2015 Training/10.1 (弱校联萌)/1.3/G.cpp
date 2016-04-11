//
//  Created by TaoSama on 2015-10-04
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
#include <stack>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q;
struct Query{
    int v, id;
};
vector<Query> Q[N];

struct DSU{
    int par[N], rnk[N];
    void init(int n){
        for(int i = 1; i <= n; ++i)
            par[i] = i, rnk[i] = 0;
    }
    void find(int x){
        return par[x] = par[x] == x ? x : find(par[x]);
    }
    void unite(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return;
        if(rnk[x] < rnk[y]) par[x] = y;
        else{
            par[y] = x;
            if(rnk[x] == rnk[y]) ++rnk[x];
        }
    }
} dsu;

vector<int> G[N];

int ans[10], ancestor[N];
bool vis[N];

void tarjan(int u){
    vis[u] = true;
    for(int i = 0; i < G[u].size(); ++i){
        int v = G[u][i];
        if(vis[v]) continue;
        tarjan(v);
        dsu.unite(u, v);
    }
    for(int i = 0; i < Q[u].size(); ++i){
        Query& q = Q[u][i];
        if(vis[q.v])
            ans[q.id] = dsu.find(q.v);
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back((Edge) {v, 1});
            G[v].push_back((Edge) {u, 0});
        }
        scanf("%d", &q);
        gao();
        while(q--) {
            int u, v; scanf("%d%d", &u, &v);
            int _lca = lca(u, v);
            int depu = dep[u] - dep[_lca];
            int depv = dep[v] - dep[_lca];
            int disu = dp[u] - dp[_lca];
            int disv = dp[v] - dp[_lca];
            if(depu == -disu && depv == disv) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
