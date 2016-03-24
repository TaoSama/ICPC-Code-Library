//
//  Created by TaoSama on 2015-08-22
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

int n, q, tim, st[N], ed[N];
int maxv[N * 3];
int pnt[N], nxt[N], head[N], cnt;

void add_edge(int u, int v) {
    pnt[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

void dfs(int u) {
    st[u] = ++tim;
    for(int i = head[u]; ~i; i = nxt[i])
        dfs(pnt[i]);
    ed[u] = tim;
}

#define root 1, n - 1, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

void push_up(int rt) {
    maxv[rt] = max(maxv[rt << 1], maxv[rt << 1 | 1]);
}

void build(int l, int r, int rt) {
    maxv[rt] = -1;
    if(l == r) return;

    int m = l + r >> 1;
    build(lson);
    build(rson);
}

void update(int o, int v, int l, int r, int rt) {
    if(l == r) {
        maxv[rt] = v;
        return;
    }

    int m = l + r >> 1;
    if(o <= m) update(o, v, lson);
    else update(o, v, rson);
    push_up(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) return maxv[rt];

    int m = l + r >> 1, ret = -INF;
    if(L <= m) ret = max(ret, query(L, R, lson));
    if(R > m) ret = max(ret, query(L, R, rson));
    return ret;
}

struct Staff {
    int cap, loy, id;
    bool operator< (const Staff& rhs) const {
        if(cap != rhs.cap) return cap > rhs.cap;
        return id < rhs.id;
    }
} a[N];
int ans[N];
map<int, int> mp; //map the loyalty

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &q);

        cnt = 0; memset(head, -1, sizeof head);
        mp.clear();
        for(int v = 1; v < n; ++v) {
            int u, loy, cap; scanf("%d%d%d", &u, &loy, &cap);
            add_edge(u, v);
            a[v].loy = loy;
            a[v].cap = cap;
            mp[loy] = a[v].id = v;
        }
        tim = -1;
        dfs(0);
//      for(int i = 0; i < n; ++i) printf("i: %d st: %d ed: %d\n", i, st[i], ed[i]);
        build(root);
        sort(a + 1, a + n);

        //from big to small if found must greater equal than him
        for(int i = 1; i < n; ++i) {
            int cur = a[i].id;
//          printf("cur: %d st: %d ed: %d\n", cur, st[cur], ed[cur]);
            int loy = query(st[cur], ed[cur], root);
            ans[cur] = loy == -1 ? -1 : mp[loy];
            update(st[cur], a[i].loy, root);
        }
        while(q--) {
            int x; scanf("%d", &x);
            printf("%d\n", ans[x]);
        }
    }
    return 0;
}
