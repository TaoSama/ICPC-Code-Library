//
//  Created by TaoSama on 2016-09-18
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q, w[N], val[N];

struct Node {
    int l, r;
    int pre, suf, sum;
    Node() {pre = suf = sum = -INF;}
    Node rev() {
        Node ret = *this;
        swap(ret.pre, ret.suf);
        return ret;
    }
    void set(int v) {
        sum = 1;
        pre = suf = v;
    }
};


Node operator+ (const Node& A, const Node& B) {
    if(A.sum == -INF) return B;
    if(B.sum == -INF) return A;
    Node ret; ret.l = A.l, ret.r = B.r;
    ret.sum = A.sum + B.sum;
    ret.suf = B.suf; ret.pre = A.pre;
    if(A.suf == B.pre) ret.sum--;
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
        if(dat[rt].l == dat[rt].r) return;
        printAll(rt << 1);
        printAll(rt << 1 | 1);
    }

    Node query(int L, int R, int rt) {
        if(L <= dat[rt].l && dat[rt].r <= R) return dat[rt];
        push_down(rt);
        int m = dat[rt].l + dat[rt].r >> 1;
        Node ret;
        if(L <= m) ret = ret + query(L, R, rt << 1);
        if(R > m) ret = ret + query(L, R, rt << 1 | 1);
        return ret;
    }
} T;


struct Edge {
    int to, nxt;
};

int u[N], v[N], c[N];
struct HLD {
    int head[N], cnt, tid;
    int sz[N], son[N], fa[N], dep[N], top[N], dfn[N];
    Edge edge[N << 1];

    void init(int m) {
        cnt = tid = 0;
        memset(head, -1, sizeof head);
        memset(sz, 0, sizeof(sz));
        memset(son, 0, sizeof son);
        memset(fa, 0, sizeof(fa));
        memset(dep, 0, sizeof(dep));
        memset(dfn, 0, sizeof(dfn));
        memset(top, 0, sizeof(top));
        memset(degree, 0, sizeof(degree));

        ++degree[1];
        for(int i = 1; i <= m; ++i) {
            scanf("%d%d%d", &u[i], &v[i], &c[i]);
            addEdge(u[i], v[i]);
            ++degree[u[i]];
            ++degree[v[i]];
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
            int v = edge[i].to;
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
            int v = edge[i].to;
            if(v == fa[u] || v == son[u]) continue;
            dfs2(v, v);
        }
    }


    int degree[N];
    void bfs() {
        queue<int> q;
        for(int i = 1; i <= n; ++i)
            if(degree[i] == 1) q.push(i);
        while(!q.empty()) {
            int x = q.front(); q.pop();
            ++sz[x];
            for(int k = head[x]; k != -1; k = edge[k].nxt) {
                int y = edge[k].to;
                if(degree[y] > 1) {
                    fa[x] = y;
                    sz[y] += sz[x];
                    if(son[y] == 0 || sz[son[y]] < sz[x])
                        son[y] = x;
                    if(--degree[y] == 1) q.push(y);
                }
            }
        }

        q.push(1);
        dfn[1] = dep[1] = top[1] = 1;
        while(!q.empty()) {
            int x = q.front(); q.pop();
            int S = dfn[x];
            if(son[x] != 0) {
                top[son[x]] = top[x];
                dfn[son[x]] = S + 1;
                S += sz[son[x]];
                dep[son[x]] = dep[x] + 1;
                q.push(son[x]);
            }
            for(int k = head[x]; k != -1; k = edge[k].nxt) {
                int y = edge[k].to;
                if(dfn[y] > 0) continue;
                top[y] = y;
                dep[y] = dep[x] + 1;
                dfn[y] = S + 1;
                S += sz[y];
                q.push(y);
            }
        }
        for(int i = 1; i <= n; ++i) val[dfn[i]] = w[i];
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
        if(u == v) return;
        if(dep[u] > dep[v]) swap(u, v);
        T.update(dfn[u] + 1, dfn[v], c, 1);
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
        if(u == v) return (L + R).sum;
        if(dep[u] > dep[v]) L = L + T.query(dfn[v] + 1, dfn[u], 1).rev();
        else R = T.query(dfn[u] + 1, dfn[v], 1) + R;
        return (L + R).sum;
    }

    void build() {
//        printf("dfs1\n");
//        dfs1(1, -1, 0);
//        printf("dfs2\n");
//        dfs2(1, 1);
//        printf("build\n");
        bfs();
        T.build(1, n, 1);
    }
} hld;
int main() {
    int m;
    while(scanf("%d%d", &n, &m) != EOF) {
        hld.init(n - 1);
        hld.build();
        for(int i = 1; i < n; ++i) {
            int& x = u[i], &y = v[i];
            if(hld.dep[x] > hld.dep[y]) swap(x, y);
            T.update(hld.dfn[y], hld.dfn[y], c[i], 1);
        }
        for(int j = 1; j <= m; j++) {
            char s[10];
            scanf("%s", s);
            if(*s == 'Q') {
                int a, b; scanf("%d%d", &a, &b);
                if(a == b) printf("0\n");
                else printf("%d\n", hld.query(a, b));
            } else {
                int a, b, c; scanf("%d%d%d", &a, &b, &c);
                hld.update(a, b, c);
            }
        }
    }
    return 0;
}
