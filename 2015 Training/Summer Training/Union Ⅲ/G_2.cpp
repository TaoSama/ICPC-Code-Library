//
//  Created by TaoSama on 2015-08-26
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

int n, x[2005], y[2005], ans[2005], dir[2005], sz;
bool vis[2005];
vector<int> G[2005];

const char word[][10] = {"UP", "DOWN", "RIGHT", "LEFT"};
void dfs(int u) {
    vis[u] = true;
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(vis[v]) continue;
        dfs(v);
        ans[++sz] = v;
        if(x[v] == x[u]) dir[v] = y[v] < y[u] ? 0 : 1;
        else dir[v] = x[v] < x[u] ? 2 : 3;
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
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d", x + i, y + i);
            for(int j = 1; j < i; ++j) {
                if(x[i] == x[j] || y[i] == y[j]) {
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }
        int cnt = 0; sz = 0;
        memset(vis, false, sizeof vis);
        for(int i = 1; i <= n; ++i)
            if(!vis[i]) ++cnt, dfs(i);
        printf("%d\n", cnt);
        for(int i = 1; i <= sz; ++i) {
            int u = ans[i];
            printf("(%d, %d) %s\n", x[u], y[u], word[dir[u]]);
        }
    }
    return 0;
}
