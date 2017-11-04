//
//  Created by TaoSama on 2017-05-17
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 1e6 + 10;

int n, m;
struct Edge {
    int u, v, c;
} e[M];

int realRoot, pre[N], in[N], id[N], vis[N];

int directedMST(int root, int n, int m) {
    int ret = 0;
    while(true) {
        memset(in, 0x3f, sizeof in);
        for(int i = 0; i < m; ++i) {
            int u = e[i].u, v = e[i].v;
            if(u != v && e[i].c < in[v]) {
                if(u == root) realRoot = i;
                pre[v] = u;
                in[v] = e[i].c;
            }
        }
        for(int i = 0; i < n; ++i) {
            if(i == root) continue;
            if(in[i] == INF) return -1;
        }

        int cnt = 0;
        memset(id, -1, sizeof id);
        memset(vis, -1, sizeof vis);
        in[root] = 0;
        for(int i = 0; i < n; ++i) {
            ret += in[i];
            int u = i;
            while(id[u] == -1 && vis[u] != i && u != root) {
                vis[u] = i;
                u = pre[u];
            }
            if(id[u] == -1 && u != root) {
                for(int v = pre[u]; v != u; v = pre[v]) {
                    id[v] = cnt;
                }
                id[u] = cnt++;
            }
        }
        if(cnt == 0) break;
        for(int i = 0; i < n; ++i)
            if(id[i] == -1) id[i] = cnt++;
        for(int i = 0; i < m; ++i) {
            int u = e[i].u, v = e[i].v;
            e[i].u = id[u];
            e[i].v = id[v];
            if(u != v) e[i].c -= in[v];
        }
        n = cnt;
        root = id[root];
    }
    return ret;
}

int x[N], y[N], z[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        int n, p; scanf("%d%d", &n, &p);
        for(int i = 0; i < n; ++i) scanf("%d%d%d", x + i, y + i, z + i);

        int m = 0, sum = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == j) continue;
                if(z[i] >= z[j]) {
                    int c = abs(x[i] - x[j]) + abs(y[i] - y[j]) + abs(z[i] - z[j]);
                    e[m++] = {i, j, c};
//                    printf("%d %d %d\n", i, j, c);
                    sum += c;
                }
            }
        }
        ++sum;

        for(int i = 0; i < n; ++i)
            e[m + i] = {n, i, sum};
        int ans = directedMST(n, n + 1, n + m) - sum;
//        printf("%d %d\n", ans, sum);

        static int kase = 0;
        printf("Case #%d:\n%lld\n", ++kase, 1LL * ans * p);
    }

    return 0;
}
