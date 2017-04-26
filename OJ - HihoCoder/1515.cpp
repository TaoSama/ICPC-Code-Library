//
//  Created by TaoSama on 2017-04-26
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, q;
int fa[N], dis[N];

int find(int x) {
    if(fa[x] == x) return x;
    int f = find(fa[x]);
    dis[x] += dis[fa[x]];
    return fa[x] = f;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1; i <= n; ++i) fa[i] = i;
    for(int i = 1; i <= m; ++i) {
        int u, v, c; scanf("%d%d%d", &u, &v, &c);
        int fu = find(u), fv = find(v);
        if(fu != fv) {
            fa[fv] = fu;
            dis[fv] = dis[u] + c - dis[v];
        }
    }
    for(int i = 1; i <= q; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        printf("%d\n", find(u) == find(v) ? dis[v] - dis[u] : -1);
    }

    return 0;
}
