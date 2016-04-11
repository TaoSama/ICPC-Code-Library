//
//  Created by TaoSama on 2015-12-14
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
const int N = 2e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, k;
vector<int> G[N];

bool vis[N];
int deg[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &k, &m);
        for(int i = 1; i <= n; ++i) G[i].clear();
        memset(deg, 0, sizeof deg);
        memset(vis, false, sizeof vis);
        while(m--) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
            ++deg[u], ++deg[v];
        }

        int ans = n;
        queue<int> q;
        for(int i = 1; i <= n; ++i)
            if(deg[i] < k) q.push(i), vis[i] = true, --ans;
        while(q.size()) {
            int u = q.front(); q.pop();
            for(int v : G[u]) {
                if(--deg[v] < k && !vis[v]) {
                    --ans;
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
