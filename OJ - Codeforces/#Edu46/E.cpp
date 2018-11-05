
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
vector<int> G[N], T[N];
int dfn[N], low[N], in[N], id[N], bcc, dfsNum;
int stk[N], top;
void tarjan(int u, int f) {
    dfn[u] = low[u] = ++dfsNum;
    stk[++top] = u;
    in[u] = true;
    for(int& v : G[u]) {
        if(v == f) continue;
        if(!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]) {
        ++bcc;
        while(true) {
            int v = stk[top--];
            in[v] = false;
            id[v] = bcc;
            if(v == u) break;
        }
    }
}
void init() {
    bcc = dfsNum = 0;
    memset(dfn, 0, sizeof dfn);
}

void dfs(int u, int fa, int d, pair<int, int>& ans) {
    ans = max(ans, {d, u});    
    for(int v : T[u]) {
        if(v == fa) continue;     
        dfs(v, u, d + 1, ans);
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    init();
    for(int i = 1; i <= n; ++i) if(!dfn[i]) tarjan(i, -1);

    for(int i = 1; i <= n; ++i) {
        int u = id[i];
        for(int& j : G[i]) {
            int v = id[j];
            if(u == v) continue;
            T[u].push_back(v);
        }
    }    

    pair<int, int> ans = {-1, -1};
    dfs(1, -1, 0, ans);
    dfs(ans.second, -1, 0, ans);
    cout << ans.first << endl;
    return 0;
}
