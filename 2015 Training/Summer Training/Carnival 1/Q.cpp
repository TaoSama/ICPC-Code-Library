//
//  Created by TaoSama on 2015-07-27
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
vector<int> G[105];
int deg[105];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m) {
        for(int i = 1; i <= n; ++i) G[i].clear();
        memset(deg, 0, sizeof deg);
        for(int i = 1; i <= m; ++i) {
            int u, v; cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
            deg[u]++, deg[v]++;
        }
        int ans = 0;
//        for(int i = 1; i <= n; ++i) {
//            prln(deg[i]);
//        }
        for(; ; ++ans) {
            bool out = false;
            vector<int> p;
            for(int u = 1; u <= n; ++u) {
                if(deg[u] == 1) {
                    --deg[u];
                    out = true;
                    p.push_back(u);
                }
            }
            if(!out) break;
            for(auto &u : p) for(auto &v : G[u]) --deg[v];
        }
        cout << ans << '\n';
    }
    return 0;
}
