//
//  Created by TaoSama on 2015-07-24
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

vector<int> G[105], ans;
int n, m, c[105];

bool dfs(int u) {
    c[u] = -1;
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(c[v] < 0) return false;
        if(!c[v] && !dfs(v)) return false;
    }
    c[u] = 1;
    ans.push_back(u);
    return true;
}

bool topo() {
    memset(c, 0, sizeof c);
    for(int i = 1; i <= n; ++i) {
        if(!c[i] && !dfs(i)) return false;
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m && (n || m)) {
        ans.clear();
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= m; ++i) {
            int u, v; cin >> u >> v;
            G[u].push_back(v);
        }
        topo();
        for(int i = ans.size() - 1; i >= 0; --i)
            cout << ans[i] << (i == 0 ? '\n' : ' ');
    }
    return 0;
}
