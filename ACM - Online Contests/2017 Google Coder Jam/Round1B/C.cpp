//
//  Created by TaoSama on 2017-04-22
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

int n, q;
LL d[N][N];
int e[N], s[N];

bool in[N];
double f[N];

int main() {
#ifdef LOCAL
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; ++i) scanf("%d%d", e + i, s + i);

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                scanf("%lld", d[i] + j);
                if(d[i][j] == -1) d[i][j] = ~0ull >> 2;
            }
        }

        for(int k = 1; k <= n; ++k) {
            for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= n; ++j) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }

        static int kase = 0;
        printf("Case #%d:", ++kase);
        while(q--) {
            int src, des; scanf("%d%d", &src, &des);
            for(int i = 1; i <= n; ++i) f[i] = 1e18, in[i] = 0;
            queue<int> q; q.push(src);
            f[src] = 0; in[src] = 1;
            while(q.size()) {
                int u = q.front(); q.pop();
                in[u] = false;
                for(int v = 1; v <= n; ++v) {
                    if(d[u][v] > e[u]) continue;
                    double cost = 1.0 * d[u][v] / s[u];
                    if(f[v] > f[u] + cost) {
                        f[v] = f[u] + cost;
                        if(!in[v]) {
                            in[v] = true;
                            q.push(v);
                        }
                    }
                }
            }
            printf(" %.12f", f[des]);
        }
        puts("");

    }

    return 0;
}
