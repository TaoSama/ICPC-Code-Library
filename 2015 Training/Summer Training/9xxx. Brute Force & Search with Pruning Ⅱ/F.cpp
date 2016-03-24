//
//  Created by TaoSama on 2015-07-28
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

int g, cnt, pre[25];
bool vis[25];
vector<int> G[25];

void dfs(int u) {
    if(u == g) {
        ++cnt;
        vector<int> path;
        while(true) {
            path.push_back(u);
            if(u == 1) break;
            u = pre[u];
        }
        reverse(path.begin(), path.end());
        for(int i = 0; i < path.size(); ++i) {
            cout << path[i] << (i == path.size() - 1 ? '\n' : ' ');
        }
        return;
    }
    vis[u] = true;
    for(auto &v : G[u]) {
        if(vis[v]) continue;
        pre[v] = u;
        dfs(v);
        vis[v] = false;
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(cin >> g) {
        int u, v;
        for(int i = 1; i <= 20; ++i) G[i].clear();
        memset(vis, false, sizeof vis);
        while(cin >> u >> v && (u || v)) {
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i = 1; i <= 20; ++i)
            sort(G[i].begin(), G[i].end());

        cout << "CASE " << ++kase << ":\n";
        cnt = 0;
        if(G[g].size()) dfs(1);
        cout << "There are " << cnt << " routes from the firestation to streetcorner ";
        cout << g << ".\n";
    }
    return 0;
}
