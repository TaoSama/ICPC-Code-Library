//
//  Created by TaoSama on 2015-08-03
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

int n, m, k;
int pnt[N << 1], nxt[N << 1], head[N], cnt;
int col[N], vis[N], deg[N];

void add_edge(int u, int v) {
    pnt[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

void dfs(int u) {
    for(int i = head[u]; ~i; i = nxt[i]) {
        int v = pnt[i];
        vis[col[v]] = u;
    }

    for(int i = 1; i <= k; ++i) {
        if(vis[i] != u) {
            col[u] = i;
            break;
        }
    }
    for(int i = head[u]; ~i; i = nxt[i]) {
        int v = pnt[i];
        if(col[v]) continue;
        dfs(v);
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d%d", &n, &m) == 2) {
        cnt = 0;
        memset(head, -1, sizeof head);
        memset(col, 0, sizeof col);
        memset(deg, 0, sizeof deg);

        k = 0;
        for(int i = 1; i <= m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            add_edge(u, v);
            add_edge(v, u);
            k = max(k, max(++deg[u], ++deg[v]));
        }

        if(!(k & 1)) k++;
        dfs(1);
        if(kase++) printf("\n");
        printf("%d\n", k);
        for(int i = 1; i <= n; ++i) printf("%d\n", col[i]);
    }
    return 0;
}
