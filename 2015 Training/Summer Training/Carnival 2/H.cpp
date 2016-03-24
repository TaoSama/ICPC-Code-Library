//
//  Created by TaoSama on 2015-08-02
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

int n, m, g[105][105];
bool vis[105];

void dfs(int u) {
    vis[u] = true;
    for(int i = 1; i <= n; ++i) {
        if(g[u][i] && !vis[i]) {
            vis[i] = true;
            dfs(i);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m) {
        memset(g, false, sizeof g);
        memset(vis, false, sizeof vis);
        for(int i = 1; i <= m; ++i) {
            int u, v; cin >> u >> v;
            g[u][v] = g[v][u] = true;
        }

        int cnt = 0;
        for(int i = 1; i <= n; ++i) {
            if(!vis[i]) {
                cnt ++;
                dfs(i);
            }
        }
//        cout << cnt << endl;
        if(n == m && cnt == 1) cout << "FHTAGN!\n";
        else cout << "NO\n";
    }
    return 0;
}
