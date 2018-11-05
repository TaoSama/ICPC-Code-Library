
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
vector<int> g[N];

map<int, int> mp[N];
int delta[N];
pair<int, int> ans[N];

void go(int u, int v) {
    delta[v]++;
    if(mp[v].size() > mp[u].size()) {
        swap(mp[u], mp[v]);
        swap(delta[u], delta[v]);
    }
    ans[u] = max(ans[u], {ans[v].first, ans[v].second - 1});
    // cout << v << endl;
    for(const auto& p : mp[v]) {
        int d, c; tie(d, c) = p;
        int o = d + delta[v] - delta[u];
        mp[u][o] += c;
        // cout << d + delta[v] << ' ' << mp[u][o] << endl;
        ans[u] = max(ans[u], {mp[u][o], -(o + delta[u])});
    }
    map<int, int>().swap(mp[v]);
}

void dfs(int u, int fa) {
    mp[u][0] = 1;
    delta[u] = 0;
    ans[u] = {1, 0};
    for(int v : g[u]) {
        if(v == fa) continue;
        dfs(v, u);
        go(u, v);
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    scanf("%d", &n);
    for(int i = 1; i < n; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    for(int i = 1; i <= n; ++i) printf("%d\n", -ans[i].second);
    return 0;
}
