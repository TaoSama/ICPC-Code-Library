//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct Node {
    int l, r;
    int sum, len;
};

struct SegTree {
    Node dat[N << 2];
    int addv[N << 2];

    void push_up(int rt) {
        dat[rt].sum = dat[rt << 1].sum + dat[rt << 1 | 1].sum;
    }
    void down(int rt){
        int& lazy = addv[rt];
        if(!lazy) return;
        int ls = rt << 1, rs = ls | 1;
        dat[ls].sum += dat[ls].len * lazy;
        dat[rs].sum += dat[rs].len * lazy;
        addv[ls] += lazy;
        addv[rs] += lazy;
        lazy = 0;
    }

    void build(int l, int r, int rt){
        dat[rt].l = l; dat[rt].r = r;
        dat[rt].sum = 0;
        dat[rt].len = (r - l + 1);
        addv[rt] = 0;
        if(l == r) return;
        int m = l + r >> 1;
        build(l, m, rt << 1);
        build(m + 1, r, rt << 1 | 1);
    } 
    void update(int l, int r, int v, int rt) {
        if(l <= dat[rt].l && dat[rt].r <= r) {
            addv[rt] += v;
            dat[rt].sum += (dat[rt].len) * v;
            return;
        }
        down(rt);
        int m = dat[rt].l + dat[rt].r >> 1;
        if(l <= m) update(l, r, v, rt << 1);
        if(r > m) update(l, r, v, rt << 1 | 1);
        push_up(rt);
    }
    int query(int l, int r, int rt) {
        if(l <= dat[rt].l && dat[rt].r <= r) return dat[rt].sum;
        int ret = 0, m = dat[rt].l + dat[rt].r >> 1;
        down(rt);
        if(l <= m) ret += query(l, r, rt << 1);
        if(r > m) ret += query(l, r, rt << 1 | 1);
        return ret;
    }
} T;

struct Edge {
    int to, nxt;
};

struct HLD {
    int head[N], cnt, tid;
    int sz[N], son[N], fa[N], dep[N], top[N], dfn[N], wh[N];
    Edge edge[N << 1];

    void init() {
        cnt = tid = 0;
        memset(head, -1, sizeof head);
        memset(son, 0, sizeof son);
    }

    void add_edge(int u, int v) {
        edge[cnt] = (Edge) {v, head[u]};
        head[u] = cnt++;
        edge[cnt] = (Edge) {u, head[v]};
        head[v] = cnt++;
    }
    //find heavy edge
    void dfs1(int u, int f, int d) {
        sz[u] = 1, fa[u] = f, dep[u] = d;
        for(int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].to;
            if(v == f) continue;
            dfs1(v, u, d + 1);
            if(!son[u] || sz[v] > sz[son[u]]) son[u] = v;
            sz[u] += sz[v];
        }
    }
    //connect heavy edge
    void dfs2(int u, int tp) {
        dfn[u] = ++tid;
        wh[tid] = u;
        top[u] = tp;
        if(son[u]) dfs2(son[u], tp);
        for(int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].to;
            if(v == fa[u] || v == son[u]) continue;
            dfs2(v, v);
        }
    }

    void update(int u, int v, int c) {
        int fu = top[u], fv = top[v];
        while(fu != fv) {
            if(dep[fu] < dep[fv]) {
                swap(u, v);
                swap(fu, fv);
            }
            T.update(dfn[fu], dfn[u], c, 1);
            // add[dfn[fu]].push_back(c);
            // sub[dfn[u] + 1].push_back(c);
            u = fa[fu];
            fu = top[u];
        }
        if(dep[u] > dep[v]) swap(u, v);
        T.update(dfn[u], dfn[v], c, 1);
        // add[dfn[u]].push_back(c);
        // sub[dfn[v] + 1].push_back(c);
    }
    int query(int u, int v) {
        int fu = top[u], fv = top[v];
        int ret = 0;
        while(fu != fv) {
            if(dep[fu] < dep[fv]) {
                swap(u, v);
                swap(fu, fv);
            }
            ret += T.query(dfn[fu], dfn[u], 1);
            // add[dfn[fu]].push_back(c);
            // sub[dfn[u] + 1].push_back(c);
            u = fa[fu];
            fu = top[u];
        }
        if(dep[u] > dep[v]) swap(u, v);
        ret += T.query(dfn[u], dfn[v], 1);
        // add[dfn[u]].push_back(c);
        // sub[dfn[v] + 1].push_back(c);
        return ret;
    }
    void build() {
        dfs1(1, -1, 0);
        dfs2(1, 1);
    }
};

HLD hld;

int ans[N];
int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
   
    int n, q; scanf("%d%d", &n, &q);
    hld.init();
    for(int i = 2; i <= n; ++i){
        int p; scanf("%d", &p);
        hld.add_edge(p, i);
    }
    hld.build();
    // puts("hld build");
    T.build(1, n, 1);
    // puts("build ok");
    
    while(q--){
        int c[3]; 
        for(int i = 0; i < 3; ++i) scanf("%d", c + i);
        int ans = 0;
        for(int i = 0; i < 3; ++i){
            int x = c[i], y = c[(i + 1) % 3], z = c[(i + 2) % 3];
            hld.update(x, z, 1);
            ans = max(ans, hld.query(y, z));
            hld.update(x, z, -1);
        }
        printf("%d\n", ans);
    }
    return 0;
}
