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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q, w[N], val[N];

struct Node {
    int l, r;
    int pre, suf, sub, sum;
    Node() {pre = suf = sub = sum = -INF;}
    Node rev() {
        Node ret = *this;
        swap(ret.pre, ret.suf);
        return ret;
    }
    void set(int v) {
        sum = v * (r - l + 1);
        pre = suf = sub = max(v, sum);
    }
};

void printNode(Node x) {
    printf("l: %d r: %d pre: %d suf: %d sub: %d sum: %d\n",
           x.l, x.r, x.pre, x.suf, x.sub, x.sum);
}

Node operator+ (const Node& A, const Node& B) {
    if(A.sub == -INF) return B;
    if(B.sub == -INF) return A;
    Node ret; ret.l = A.l, ret.r = B.r;
    ret.sum = A.sum + B.sum;
    ret.pre = max(A.pre, A.sum + B.pre);
    ret.suf = max(B.suf, B.sum + A.suf);
    ret.sub = max(A.suf + B.pre, max(A.sub, B.sub));
    return ret;
}

struct SegTree {
    Node dat[N << 2];
    int setv[N << 2];

    void push_up(int rt) {
        dat[rt] = dat[rt << 1] + dat[rt << 1 | 1];
    }

    void push_down(int rt) {
        if(setv[rt] != -INF) {
            int v = setv[rt], ls = rt << 1, rs = ls | 1;
            setv[ls] = setv[rs] = v;
            dat[ls].set(v);
            dat[rs].set(v);
            setv[rt] = -INF;
        }
    }

    void build(int l, int r, int rt) {
        setv[rt] = -INF;
        if(l == r) {
            dat[rt].l = l, dat[rt].r = r;
            dat[rt].set(val[l]);
            return;
        }
        int m = l + r >> 1;
        build(l, m, rt << 1);
        build(m + 1, r, rt << 1 | 1);
        push_up(rt);
    }

    void update(int L, int R, int v, int rt) {
        if(L <= dat[rt].l && dat[rt].r <= R) {
            setv[rt] = v;
            dat[rt].set(v);
            return;
        }
        push_down(rt);
        int m = dat[rt].l + dat[rt].r >> 1;
        if(L <= m) update(L, R, v, rt << 1);
        if(R > m) update(L, R, v, rt << 1 | 1);
        push_up(rt);
    }

    void printAll(int rt) {
        printNode(dat[rt]);
        if(dat[rt].l == dat[rt].r) return;
        printAll(rt << 1);
        printAll(rt << 1 | 1);
    }

    Node query(int L, int R, int rt) {
        if(L <= dat[rt].l && dat[rt].r <= R) return dat[rt];
        push_down(rt);
        int m = dat[rt].l + dat[rt].r >> 1;
        Node ret;
        if(L <= m && R > m) ret = query(L, R, rt << 1) + query(L, R, rt << 1 | 1);
        else if(L <= m) ret = query(L, R, rt << 1);
        else if(R > m) ret = query(L, R, rt << 1 | 1);
        return ret;
    }
};

struct Edge {
    int to, nxt;
};

struct HLD {
    int head[N], cnt, tid;
    int sz[N], son[N], fa[N], dep[N], top[N], dfn[N];
    Edge edge[N << 1];
    SegTree T;

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
        val[tid] = w[u];
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
            u = fa[fu];
            fu = top[u];
        }
        if(dep[u] > dep[v]) swap(u, v);
        T.update(dfn[u], dfn[v], c, 1);
    }

    int query(int u, int v) {
        Node L, R;  //there [l,r] info doesn't matter
        int fu = top[u], fv = top[v];
        while(fu != fv) {
            if(dep[fu] > dep[fv]) {
                L = L + T.query(dfn[fu], dfn[u], 1).rev();
                u = fa[fu], fu = top[u];
            } else {
                R = T.query(dfn[fv], dfn[v], 1) + R;
                v = fa[fv], fv = top[v];
            }
        }
        if(dep[u] > dep[v]) L = L + T.query(dfn[v], dfn[u], 1).rev();
        else R = T.query(dfn[u], dfn[v], 1) + R;
        return (L + R).sub;
    }

    void build() {
        dfs1(1, -1, 0);
        dfs2(1, 1);
        T.build(1, n, 1);
    }
};

HLD hld;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
//    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &q) == 2) {
        hld.init();
        for(int i = 1; i <= n; ++i) scanf("%d", w + i);
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            hld.add_edge(u, v);
        }
        hld.build();
        while(q--) {
            int op, x, y, z; scanf("%d%d%d%d", &op, &x, &y, &z);
            if(op == 1) hld.update(x, y, z);
            else printf("%d\n", hld.query(x, y));
        }
    }
    return 0;
}
