//
//  Created by TaoSama on 2016-01-22
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
#include <bitset>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 4e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct Node {
    int l, r;
    bitset<61> c;
    Node() {}
    void setColor(int col) {
        c.reset();
        c[col] = 1;
    }
    Node(int l, int r): l(l), r(r) {c.reset();}
} dat[N << 2];

Node operator+(Node A, Node B) {
    Node ret(A.l, B.r);
    ret.c = A.c | B.c;
    return ret;
}

int setc[N << 2];

void push_down(int rt) {
    if(setc[rt]) {
        dat[rt << 1].setColor(setc[rt]);
        dat[rt << 1 | 1].setColor(setc[rt]);
        setc[rt << 1] = setc[rt << 1 | 1] = setc[rt];
        setc[rt] = 0;
    }
}

void build(int l, int r, int rt) {
    dat[rt].l = l, dat[rt].r = r;
    if(l == r) return;
    int m = l + r >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
}

void update(int L, int R, int c, int rt) {
    if(L <= dat[rt].l && dat[rt].r <= R) {
        dat[rt].setColor(c);
        setc[rt] = c;
        return;
    }
    int m = dat[rt].l + dat[rt].r >> 1;
    push_down(rt);
    if(L <= m) update(L, R, c, rt << 1);
    if(R > m) update(L, R, c, rt << 1 | 1);
    dat[rt] = dat[rt << 1] + dat[rt << 1 | 1];
}

Node query(int L, int R, int rt) {
    if(L <= dat[rt].l && dat[rt].r <= R) return dat[rt];
    Node ret(-1, -1);
    push_down(rt);
    int m = dat[rt].l + dat[rt].r >> 1;
    if(L <= m) ret = ret + query(L, R, rt << 1);
    if(R > m) ret = ret + query(L, R, rt << 1 | 1);
    return ret;
}

int n, q, col[N];

vector<int> G[N];
int st[N], ed[N], dfn;
void dfs(int u, int f) {
    st[u] = ++dfn;
    for(int v : G[u])
        if(v != f) dfs(v, u);
    ed[u] = dfn;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &q) == 2) {
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= n; ++i) scanf("%d", col + i);

        build(1, n, 1);
        memset(setc, 0, sizeof setc);

        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfn = 0;
        dfs(1, -1);
        for(int i = 1; i <= n; ++i) update(st[i], st[i], col[i], 1);

        while(q--) {
            int op, x, y; scanf("%d%d", &op, &x);
            if(op == 1) {
                scanf("%d", &y);
                update(st[x], ed[x], y, 1);
            } else {
                Node ret = query(st[x], ed[x], 1);
                int ans = ret.c.count();
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
