//
//  Created by TaoSama on 2015-11-25
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

int n, m, g[405][405];

int in[405], dpv[405], dpb[405];

int bfs() {
    queue<int> q; q.push(1);
    memset(dpv, 0x3f, sizeof dpv);
    dpv[1] = 0;
    while(q.size()) {
        int u = q.front(); q.pop();
        for(int i = 1; i <= n; ++i) {
            if(!g[u][i]) continue;
            if(dpv[i] == INF) {
                dpv[i] = dpv[u] + 1;
                q.push(i);
            }
        }
    }
    return dpv[n];
}

int bfs2() {
    queue<int> q; q.push(1);
    memset(dpb, 0x3f, sizeof dpb);
    dpb[1] = 0;
    while(q.size()) {
        int u = q.front(); q.pop();
        in[u] = false;
        for(int i = 1; i <= n; ++i) {
            if(g[u][i] || dpb[u] + 1 == dpv[i]) continue;
            if(dpb[i] == INF) {
                dpb[i] = dpb[u] + 1;
                q.push(i);
            }
        }
    }
    return dpb[n];
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        memset(g, 0, sizeof g);
        while(m--) {
            int u, v; scanf("%d%d", &u, &v);
            g[u][v] = g[v][u] = 1;
        }
        int vehicle = bfs();
        if(vehicle == INF) puts("-1");
        else {
            int bus = bfs2();
            if(bus == INF) puts("-1");
            else printf("%d\n", max(vehicle, bus));
        }
    }
    return 0;
}
