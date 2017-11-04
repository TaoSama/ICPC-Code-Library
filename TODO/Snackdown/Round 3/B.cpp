//
//  Created by TaoSama on 2017-06-03
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 5e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q, w[N], val[N];

struct SegTree {
    int val[N << 2];

    void push_up(int rt) {
        val[rt] = val[rt << 1] + val[rt << 1 | 1];
    }

    void build(int l, int r, int rt) {
        val[rt] = 0;
        if(l == r) {
            return;
        }
        int m = l + r >> 1;
        build(l, m, rt << 1);
        build(m + 1, r, rt << 1 | 1);
        push_up(rt);
    }

    void update(int o, int v, int l, int r, int rt) {
        if(l == r) {
            val[rt] += v;
            return;
        }
        int m = l + r >> 1;
        if(o <= m) update(o, v, l, m, rt << 1);
        else update(o, v, m + 1, r, rt << 1 | 1);
        push_up(rt);
    }

    int query(int L, int R, int l, int r, int rt) {
        if(L <= l && r <= R) return val[rt];
        int m = l + r >> 1;
        int ret = 0;
        if(L <= m) ret += query(L, R, l, m, rt << 1);
        if(R > m) ret += query(L, R, m + 1, r, rt << 1 | 1);
        return ret;
    }
} T;


struct Edge {
    int v, nxt;
} bEdge[N << 1];
int head[N], cnt;
void addEdge(int u, int v) {
    bEdge[cnt] = (Edge) {v, head[u]};
    head[u] = cnt++;
    bEdge[cnt] = (Edge) {u, head[v]};
    head[v] = cnt++;
}

struct HLD {
    int head[N], cnt, tid;
    int sz[N], son[N], fa[N], dep[N], top[N], dfn[N];
    Edge edge[N << 1];

    void init() {
        cnt = tid = 0;
        for(int i = 1; i <= n; ++i) {
            head[i] = -1;
            son[i] = dfn[i] = 0;
        }
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            addEdge(u, v);
        }
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

    void update(int u, int c) {
        T.update(dfn[u], c, 1, n, 1);
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
        dfs1(1, -1, 0);
        dfs2(1, 1);
        // bfs();
        T.build(1, n, 1);
    }
} hld;

int ans[N];

void dfs(int u, int fa) {
    ans[u] = hld.query(1, u);
//    printf("%d = %d\n", u, ans[u]);
    hld.update(u, 1);
    for(int i = head[u]; ~i; i = bEdge[i].nxt) {
        int v = bEdge[i].v;
        if(v == fa) continue;
        dfs(v, u);
    }
    hld.update(u, -1);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        hld.init();
        hld.build();
//        prln(1);

        cnt = 0;
        for(int i = 1; i <= n; ++i) head[i] = -1;
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            addEdge(u, v);
        }
//        prln(2);

        dfs(1, -1);
        for(int i = 1; i <= n; ++i) printf("%d%c", ans[i], " \n"[i == n]);
    }

    return 0;
}
