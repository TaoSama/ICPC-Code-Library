
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 3e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

/*
 * a[v] += x - (d[v] - d[u]) * k
 * a[v] += (x + d[u] * k) + (-d[v] * k) 
 */

void addMod(int& x, int y) {
    if((x += y) >= MOD) x -= MOD;
}
struct BIT {
    int n, b[N];
    void init(int _n){
        n = _n;
        memset(b, 0, sizeof b);
    }
    void add(int i, int v) {
        for(; i <= n; i += i & -i) addMod(b[i], v);
    }
    void add(int l, int r, int v) {
        add(l, v);
        add(r + 1, MOD - v);
    }
    int sum(int i) {
        int ret = 0;
        for(; i; i -= i & -i) addMod(ret, b[i]);
        return ret;
    }
} bit, kbit;

vector<int> G[N];
int d[N], L[N], R[N], dfsNum;

void dfs(int u, int fa){
    L[u] = ++dfsNum;
    d[u] = d[fa] + 1;
    for(size_t i = 0; i < G[u].size(); ++i) dfs(G[u][i], u);
    R[u] = dfsNum;
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 2; i <= n; ++i) {
            int p; scanf("%d", &p);
            G[p].push_back(i);
        }
        dfsNum = 0;
        dfs(1, 0);
        int q; scanf("%d", &q);
        bit.init(n);
        kbit.init(n);
        while(q--){
            int op; scanf("%d", &op);
            if(op == 1){
                int u, x, k; scanf("%d%d%d", &u, &x, &k);
                bit.add(L[u], R[u], (x + 1ll * d[u] * k) % MOD);
                kbit.add(L[u], R[u], MOD - k);
            }
            else{
                int u; scanf("%d", &u);
                int ans = bit.sum(L[u]);
                addMod(ans, 1ll * d[u] * kbit.sum(L[u]) % MOD);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
