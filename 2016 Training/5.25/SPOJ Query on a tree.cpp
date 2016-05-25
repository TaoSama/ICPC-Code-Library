//
//  Created by TaoSama on 2015-10-09
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

int n;

struct Node {
    int l, r;
    int maxv;
};

struct SegTree {
    Node dat[N << 2];

    void push_up(int rt) {
        dat[rt].maxv = max(dat[rt << 1].maxv, dat[rt << 1 | 1].maxv);
    }

    void build(int l, int r, int rt) {
        dat[rt].l = l, dat[rt].r = r, dat[rt].maxv = 0;
        if(l == r) return;
        int m = l + r >> 1;
        build(l, m, rt << 1);
        build(m + 1, r, rt << 1 | 1);
    }

    void update(int o, int v, int rt) {
        if(dat[rt].l == dat[rt].r) {
            dat[rt].maxv = v;
            return;
        }
        int m = dat[rt].l + dat[rt].r >> 1;
        if(o <= m) update(o, v, rt << 1);
        else update(o, v, rt << 1 | 1);
        push_up(rt);
    }

    int query(int L, int R, int rt) {
        if(L <= dat[rt].l && dat[rt].r <= R)
            return dat[rt].maxv;
        int m = dat[rt].l + dat[rt].r >> 1, ret = 0;
        if(L <= m) ret = max(ret, query(L, R, rt << 1));
        if(R > m) ret = max(ret, query(L, R, rt << 1 | 1));
        return ret;
    }
};
SegTree T;

struct Edge {
    int to, nxt;
};

struct HLD {
    int head[N], cnt, tid;
    int sz[N], son[N], fa[N], dep[N], top[N], dfn[N];
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
        top[u] = tp;
        if(son[u]) dfs2(son[u], tp);
        for(int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].to;
            if(v == fa[u] || v == son[u]) continue;
            dfs2(v, v);
        }
    }

    int query(int u, int v) {
        int ret = 0;
        int fu = top[u], fv = top[v];
        while(fu != fv) {
            if(dep[fu] < dep[fv]) {
                swap(u, v);
                swap(fu, fv);
            }
            ret = max(ret, T.query(dfn[fu], dfn[u], 1));
            u = fa[fu], fu = top[u];
        }
        if(u == v) return ret;  //边权变点权 需要特判下
        if(dep[u] > dep[v]) swap(u, v);
        return max(ret, T.query(dfn[u] + 1, dfn[v], 1));
    }

    void build() {
        dfs1(1, -1, 0);
        dfs2(1, 1);
    }
};

int u[N], v[N], c[N];
HLD hld;

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        hld.init();
        for(int i = 1; i < n; ++i) {
            scanf("%d%d%d", u + i, v + i, c + i);
            hld.add_edge(u[i], v[i]);
        }
        hld.build();
        T.build(1, n, 1);
        for(int i = 1; i < n; ++i) {
            int &x = u[i], &y = v[i];
            if(hld.dep[x] > hld.dep[y]) swap(x, y);
            T.update(hld.dfn[y], c[i], 1);
        }

        char op[10];
        if(t) puts("");
        while(scanf("%s", op) == 1 && *op != 'D') {
            int x, y; scanf("%d%d", &x, &y);
            if(*op == 'C') T.update(hld.dfn[v[x]], y, 1);
            else printf("%d\n", hld.query(x, y));
        }
    }
    return 0;
}
