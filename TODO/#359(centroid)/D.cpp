//
//  Created by TaoSama on 2016-06-24
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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
const int N = 3e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q;

struct Edge {
    int v, nxt;
} edge[N << 1];
int head[N], cnt;

void addEdge(int u, int v) {
    edge[cnt] = (Edge) {v, head[u]};
    head[u] = cnt++;
}

bool vis[N];
int sz[N], ans[N];
pair<int, int> mx[N], mi[N];

void getCentroid(int u, int f) {
    sz[u] = 1; mx[u] = {0, u}, mi[u] = {INF, u};
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(v == f) continue;
        getCentroid(v, u);
        sz[u] += sz[v];
        mx[u] = max(mx[u], {sz[v], v});
        mx[u] = max(mx[u], mx[u]);
        mi[u] = min(mi[u], {sz[v], v});
        mi[u] = min(mi[u], mi[v]);
    }
    mx[u] = max(mx[u], {sz[u] - mi[u].first, mi[u].second});
    ans[u] = mx[u].second;
}


int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%d", &n, &q) == 2) {
        cnt = 0; memset(head, -1, sizeof head);
        for(int i = 2; i <= n; ++i) {
            int p; scanf("%d", &p);
            addEdge(p, i);
            addEdge(i, p);
        }
        getCentroid(1, - 1);
        for(int i = 1; i <= q; ++i) {
            int x; scanf("%d", &x);
            printf("%d\n", ans[x]);
        }
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
