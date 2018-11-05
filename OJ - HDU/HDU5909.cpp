
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 50, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
const LL invTwo = (MOD + 1) / 2; 
void fwtXor(LL* a, int len) {
    if(len == 1) return;
    int h = len >> 1;
    fwtXor(a, h);
    fwtXor(a + h, h);
    for(int i = 0; i < h; ++i) {
        LL x1 = a[i];
        LL x2 = a[i + h];
        a[i] = (x1 + x2) % MOD;
        a[i + h] = (x1 - x2 + MOD) % MOD;
    }
}
void ifwtXor(LL* a, int len) {
    if(len == 1) return;
    int h = len >> 1;
    for(int i = 0; i < h; ++i) {
        // y1=x1+x2
        // y2=x1-x2
        LL y1 = a[i];
        LL y2 = a[i + h];
        a[i] = (y1 + y2) * invTwo % MOD;
        a[i + h] = (y1 - y2 + MOD) * invTwo % MOD;
    }
    ifwtXor(a, h);
    ifwtXor(a + h, h);
}

vector<int> G[N];
int n, m, v[N];
LL f[N][N], g[N];

// f[u][i] += f[u][x] * f[v][y] | x ^ y == i
void dfs(int u, int fa) {
    fill(f[u], f[u] + m, 0);
    f[u][v[u]] = 1;
    for(int v : G[u]) {
        if(v == fa) continue;
        dfs(v, u);
        copy(f[u], f[u] + m, g); 
        fwtXor(g, m); fwtXor(f[v], m);
        for(int i = 0; i < m; ++i) g[i] = g[i] * f[v][i] % MOD;
        ifwtXor(g, m); ifwtXor(f[v], m);
        for(int i = 0; i < m; ++i) f[u][i] = (f[u][i] + g[i]) % MOD;
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= n; ++i) scanf("%d", v + i);
        for(int i = 1; i < n; ++i) {
            int x, y; scanf("%d%d", &x, &y);
            G[x].emplace_back(y);
            G[y].emplace_back(x);
        }
        dfs(1, 0);
        for(int j = 0; j < m; ++j) {
            LL ans = 0;
            for(int i = 1; i <= n; ++i) {
                ans = (ans + f[i][j]) % MOD;
            }
            printf("%lld%c", ans, " \n"[j + 1 == m]);
        }
    }
    return 0;
}
