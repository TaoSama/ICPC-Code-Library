//
//  Created by TaoSama on 2017-02-12
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
vector<int> G[N];

int w[N], val[N];

struct SegmentTree {
    struct Node {
        int addv, base, sum;
        void clear() {
            addv = base = sum = 0;
        }
        void add(int v) {
            addv += v;
            sum += v * base;
        }
    } dat[N << 2];

    void down(int rt) {
        int& lazy = dat[rt].addv;
        if(!lazy) return;
        dat[rt << 1].add(lazy);
        dat[rt << 1 | 1].add(lazy);
        lazy = 0;
    }

    void build(int l, int r, int rt) {
        dat[rt].clear();
        if(l == r) {
            dat[rt].base = val[l];
            return;
        }
        int m = l + r >> 1;
        build(l, m, rt << 1);
        build(m + 1, r, rt << 1 | 1);
        dat[rt].base = dat[rt << 1].base + dat[rt << 1 | 1].base;
    }

    void update(int L, int R, int l, int r, int rt) {
        if(L <= l && r <= R) {
            dat[rt].add(1);
            return;
        }
        down(rt);
        int m = l + r >> 1;
        if(L <= m) update(L, R, l, m, rt << 1);
        if(R > m) update(L, R, m + 1, r, rt << 1 | 1);
        dat[rt].sum = dat[rt << 1].sum + dat[rt << 1 | 1].sum;
    }

    int query(int L, int R, int l, int r, int rt) {
        if(L <= l && r <= R) return dat[rt].sum;
        down(rt);
        int m = l + r >> 1, ret = 0;
        if(L <= m) ret += query(L, R, l, m, rt << 1);
        if(R > m) ret += query(L, R, m + 1, r, rt << 1 | 1);
        return ret;
    }
} T;

struct HLD {
    int head[N], cnt, tid;
    int sz[N], son[N], fa[N], dep[N], top[N], dfn[N];
    struct Edge {
        int v, nxt;
    } edge[N << 1];

    void init() {
        cnt = tid = 0;
        memset(head, -1, sizeof head);
        memset(son, 0, sizeof son);
    }

    void addEdge(int u, int v) {
        edge[cnt] = (Edge) {v, head[u]};
        head[u] = cnt++;
        edge[cnt] = (Edge) {u, head[v]};
        head[v] = cnt++;
    }
    //find son edge
    void dfs1(int u, int f, int d) {
        sz[u] = 1, fa[u] = f, dep[u] = d;
        for(int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].v;
            if(v == f) continue;
            dfs1(v, u, d + 1);
            if(!son[u] || sz[v] > sz[son[u]]) son[u] = v;
            sz[u] += sz[v];
        }
        w[u] -= w[f];
    }
    //connect son edge
    void dfs2(int u, int tp) {
        dfn[u] = ++tid;
        val[tid] = w[u];
        top[u] = tp;
        if(son[u]) dfs2(son[u], tp);
        for(int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].v;
            if(v == fa[u] || v == son[u]) continue;
            dfs2(v, v);
        }
    }

    void update(int u, int v) {
        int fu = top[u], fv = top[v];
        while(fu != fv) {
            if(dep[fu] < dep[fv]) {
                swap(u, v);
                swap(fu, fv);
            }
            T.update(dfn[fu], dfn[u], 1, n, 1);
            u = fa[fu];
            fu = top[u];
        }
        if(dep[u] > dep[v]) swap(u, v);
        T.update(dfn[u], dfn[v], 1, n, 1);
    }

    int query(int u, int v) {
        int ret = 0;
        int fu = top[u], fv = top[v];
        while(fu != fv) {
            if(dep[fu] < dep[fv]) {
                swap(u, v);
                swap(fu, fv);
            }
            ret += T.query(dfn[fu], dfn[u], 1, n, 1);
            u = fa[fu];
            fu = top[u];
        }
        if(dep[u] > dep[v]) swap(u, v);
        ret += T.query(dfn[u], dfn[v], 1, n, 1);
        return ret;
    }

    void build() {
        dfs1(1, 0, 0);
        dfs2(1, 1);
        T.build(1, n, 1);
    }
} hld;

int ans[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) {
            G[i].clear();
            scanf("%d", w + i);
        }

        hld.init();
        for(int i = 2; i <= n; ++i) {
            int f; scanf("%d", &f);
            hld.addEdge(i, f);
        }

        hld.build();
        hld.update(1, 1);
        for(int i = 2; i <= n; ++i) {
            printf("%d\n", hld.query(1, i));
            hld.update(1, i);
        }
    }

    return 0;
}
