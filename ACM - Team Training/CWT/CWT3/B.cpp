//
//  Created by TaoSama on 2016-01-21
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q;
typedef long long LL;

struct Node {
    int l, r;
    LL mul;
    Node() {}
    Node(int l, int r): l(l), r(r) {mul = 1;}
};
Node operator*(Node A, Node B) {
    Node ret(A.l, B.r);
    if(~A.mul && ~B.mul && (long double)A.mul * B.mul <= 1e18)
        ret.mul = A.mul * B.mul;
    else ret.mul = -1;
    return ret;
}

struct SegTree {
    Node dat[N << 2];

    void build(int l, int r, int rt) {
        dat[rt].l = l, dat[rt].r = r, dat[rt].mul = 0;
        if(l == r) return;
        int m = l + r >> 1;
        build(l, m, rt << 1);
        build(m + 1, r, rt << 1 | 1);
    }

    void update(int o, LL v, int rt) {
        if(dat[rt].l == dat[rt].r) {
            dat[rt].mul = v;
            return;
        }
        int m = dat[rt].l + dat[rt].r >> 1;
        if(o <= m) update(o, v, rt << 1);
        else update(o, v, rt << 1 | 1);
        dat[rt] = dat[rt << 1] * dat[rt << 1 | 1];
    }

    Node query(int L, int R, int rt) {
        if(L <= dat[rt].l && dat[rt].r <= R) return dat[rt];
        int m = dat[rt].l + dat[rt].r >> 1;
        Node ret(-1, -1);
        if(L <= m) ret = ret * query(L, R, rt << 1);
        if(R > m) ret = ret * query(L, R, rt << 1 | 1);
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

    Node query(int u, int v) {
        Node ret(-1, -1);
        int fu = top[u], fv = top[v];
        while(fu != fv) {
            if(dep[fu] < dep[fv]) {
                swap(u, v);
                swap(fu, fv);
            }
            ret = ret * T.query(dfn[fu], dfn[u], 1);
            u = fa[fu], fu = top[u];
        }
        if(u == v) return ret;  //边权变点权 需要特判下
        if(dep[u] > dep[v]) swap(u, v);
        return ret * T.query(dfn[u] + 1, dfn[v], 1);
    }

    void build() {
        dfs1(1, -1, 0);
        dfs2(1, 1);
    }
    /*
    void update(int u, int v, int c){
        int fu = top[u], fv = top[v];
        while(fu != fv){
            if(dep[fu] < dep[fv]){
                swap(u, v);
                swap(fu, fv);
            }
            T.update(dfn[fu], dfn[u], c, 1);
            u = fa[fu];
            fu = top[u];
        }
        if(dep[u] > dep[v]) swap(u, v);
        T.update(dfn[u], dfn[v], c, 1);
    }*/
};

int u[N], v[N]; LL c[N];
HLD hld;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &q) == 2) {
        hld.init();
        for(int i = 1; i < n; ++i) {
            scanf("%d%d%I64d", u + i, v + i, c + i);
            hld.add_edge(u[i], v[i]);
        }
        hld.build();
        T.build(1, n, 1);
        for(int i = 1; i < n; ++i) {
            int &x = u[i], &y = v[i];
            if(hld.dep[x] > hld.dep[y]) swap(x, y);
            T.update(hld.dfn[y], c[i], 1);
        }

        while(q--) {
            int op; scanf("%d", &op);
            if(op == 1) {
                int a, b; LL y; scanf("%d%d%I64d", &a, &b, &y);
                LL ret = hld.query(a, b).mul;
                if(~ret) printf("%I64d\n", y / ret);
                else puts("0");
            } else {
                int p; LL c; scanf("%d%I64d", &p, &c);
                T.update(hld.dfn[v[p]], c, 1);
            }
        }
    }
    return 0;
}
