//
//  Created by TaoSama on 2017-04-29
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;


typedef long long LL;

int n, k;
const int K = 21;

struct Node {
    LL v[K];
    void read() {
        for(int i = 0; i <= k; ++i) scanf("%lld", v + i);
    }
    void clear() {
        for(int i = 0; i <= k; ++i) v[i] = 0;
    }
    inline LL& operator[](int k) {
        return v[k];
    }
    inline const LL& operator[](int k) const {
        return v[k];
    }
    Node operator+=(const Node& r) {
        for(int i = 0; i <= k; ++i) {
            v[i] += r[i];
            if(v[i] >= MOD) v[i] -= MOD;
        }
    }
};

int root;
vector<int> G[N];

Node coff1[N], coff2[N], sum[N];
int vs[N], L[N], R[N], dfsNum;
LL ans[N];

void dfs(int u, int dep) {
    L[u] = ++dfsNum;
    vs[dfsNum] = u;

    sum[u][0] = 1;
    for(int i = 1; i <= k; ++i) {
        sum[u][i] = sum[u][i - 1] * dep;
        sum[u][i] %= MOD;
    }
    for(int v : G[u]) {
        dfs(v, dep + 1);
        coff1[u] += coff1[v];
    }
    R[u] = dfsNum;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            if(!x) root = i;
            else G[x].push_back(i);
        }

        for(int i = 1; i <= n + 1; ++i) {
            ans[i] = 0;
            coff1[i].clear();
            coff2[i].clear();
        }

        dfsNum = 0;
        dfs(root, 1);

        int q; scanf("%d", &q);

        Node w;
        while(q--) {
            int o, v; scanf("%d%d", &o, &v);
            w.read();
            if(o == 2) coff1[v] += w;
            else {
                coff2[L[v]] += w;
                for(int i = 0; i <= k; ++i) w[i] = MOD - w[i];
                coff2[R[v] + 1] += w;
            }
        }

        dfsNum = 0;
        dfs(root, 1);
        for(int i = 1; i <= n; ++i) coff2[i] += coff2[i - 1];

        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j <= k; ++j) {
                ans[i] += coff1[i][j] * sum[i][j];
                ans[i] %= MOD;
                ans[vs[i]] += coff2[i][j] * sum[vs[i]][j];
                ans[vs[i]] %= MOD;
            }
        }
        for(int i = 1; i <= n; ++i)
            printf("%lld%c", ans[i], " \n"[i == n]);
    }

    return 0;
}
