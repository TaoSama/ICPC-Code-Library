//
//  Created by TaoSama on 2015-08-21
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
#include <cassert>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, c[2005];
vector<int> G[2005];

bool vis[2005];
int dis[2005];
bool dfs(int u) {
    vis[u] = 1;
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(vis[v] && dis[u] == dis[v] + 2) return true; //v return to cycle begin
        if(vis[v]) continue;
        dis[v] = dis[u] + 1;
        if(dfs(v)) return true;
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            G[i].clear();
            char buf[2005]; scanf("%s", buf + 1);
            for(int j = 1; j <= n; ++j)
                if(buf[j] == '1') G[i].push_back(j);
        }

        bool have = false;
        memset(vis, false, sizeof vis);
        bool ok = false;
        for(int i = 1; i <= n; ++i){
            dis[i] = 0;
            if(dfs(i)){
                ok = true;
                break;
            }
        }
        printf("Case #%d: %s\n", ++kase, ok ? "Yes" : "No");
    }
    return 0;
}
