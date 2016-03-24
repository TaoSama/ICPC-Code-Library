//
//  Created by TaoSama on 2015-10-23
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

int n, q;
vector<int> add[N], sub[N];

struct Node {
    int l, r;
    int maxv, type;
};

struct SegTree {
    Node dat[N << 2];

    void push_up(int rt) {
        int ls = rt << 1, rs = ls | 1;
        if(dat[rs].maxv > dat[ls].maxv) {
            dat[rt].maxv = dat[rs].maxv;
            dat[rt].type = dat[rs].type;
        } else {
            dat[rt].maxv = dat[ls].maxv;
            dat[rt].type = dat[ls].type;
        }
    }

    void build(int l, int r, int rt) {
        dat[rt].l = l, dat[rt].r = r, dat[rt].maxv = 0;
        if(l == r) {
            dat[rt].type = l;
            return;
        }
        int m = l + r >> 1;
        build(l, m, rt << 1);
        build(m + 1, r, rt << 1 | 1);
        push_up(rt);
    }

    void update(int o, int v, int rt) {
        if(dat[rt].l == dat[rt].r) {
            dat[rt].maxv += v;
            return;
        }
        int m = dat[rt].l + dat[rt].r >> 1;
        if(o <= m) update(o, v, rt << 1);
        else update(o, v, rt << 1 | 1);
        push_up(rt);
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
            add[dfn[fu]].push_back(c);
            sub[dfn[u] + 1].push_back(c);
            u = fa[fu];
            fu = top[u];
        }
        if(dep[u] > dep[v]) swap(u, v);
        add[dfn[u]].push_back(c);
        sub[dfn[v] + 1].push_back(c);
    }

    void build() {
        dfs1(1, -1, 0);
        dfs2(1, 1);
    }
};

HLD hld;

int ans[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    while(scanf("%d%d", &n, &q) == 2 && (n || q)) {
        hld.init();
        for(int i = 1; i <= n; ++i) add[i].clear(), sub[i].clear();
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            hld.add_edge(u, v);
        }
        hld.build();
        while(q--) {
            int x, y, z; scanf("%d%d%d", &x, &y, &z);
            hld.update(x, y, z);
        }

        T.build(1, 100000, 1);
        for(int i = 1; i <= n; ++i) {
            for(auto c : add[i]) T.update(c, 1, 1);
            for(auto c : sub[i]) T.update(c, -1, 1);
            int u = hld.wh[i];
            if(T.dat[1].maxv == 0) ans[u] = 0;
            else ans[u] = T.dat[1].type;
        }
        for(int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
    }
    return 0;
}
