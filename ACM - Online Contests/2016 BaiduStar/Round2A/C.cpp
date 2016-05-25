//
//  Created by TaoSama on 2016-05-21
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

int n, m;
vector<int> G[N];

typedef long long LL;
const LL INFLL = 0x3f3f3f3f3f3f3f3fLL;
LL a[N], b[N], maxv[N << 2], add[N << 2];

void down(int rt) {
    if(add[rt]) {
        int ls = rt << 1, rs = ls | 1;
        maxv[ls] += add[rt];
        maxv[rs] += add[rt];
        add[ls] += add[rt];
        add[rs] += add[rt];
        add[rt] = 0;
    }
}

void up(int rt) {
    maxv[rt] = max(maxv[rt << 1], maxv[rt << 1 | 1]);
}

void build(int l, int r, int rt) {
    add[rt] = 0;
    if(l == r) {
        maxv[rt] = b[l];
        return;
    }
    int m = l + r >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    up(rt);
}

void update(int L, int R, LL v, int l, int r, int rt) {
    if(L <= l && r <= R) {
        add[rt] += v;
        maxv[rt] += v;
        return;
    }
    down(rt);
    int m = l + r >> 1;
    if(L <= m) update(L, R, v, l, m, rt << 1);
    if(R > m) update(L, R, v, m + 1, r, rt << 1 | 1);
    up(rt);
}

LL query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) {
        return maxv[rt];
    }
    down(rt);
    int m = l + r >> 1;
    LL ret = -INFLL;
    if(L <= m) ret = max(ret, query(L, R, l, m, rt << 1));
    if(R > m) ret = max(ret, query(L, R, m + 1, r, rt << 1 | 1));
    return ret;
}

int dfsNum, st[N], ed[N];
void dfs(int u, int f, LL c) {
    st[u] = ++dfsNum;
    b[dfsNum] = c;
//    printf("%d %d %I64d %I64d\n", u, dfsNum, a[u], b[dfsNum]);
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(v == f) continue;
        dfs(v, u, c + a[v]);
    }
    ed[u] = dfsNum;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i < n; ++i) {
            int u, v, c; scanf("%d%d", &u, &v);
            ++u, ++v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i = 1; i <= n; ++i) scanf("%I64d", a + i);
        dfsNum = 0;
        dfs(1, -1, a[1]);
        build(1, n, 1);

//        for(int i = 1; i <= n; ++i)
//          printf("%d (%d, %d) %I64d\n", i, st[i], ed[i], b[st[i]]);

        static int kase = 0;
        printf("Case #%d:\n", ++kase);
        while(m--) {
            int op, x, y; scanf("%d%d", &op, &x);
            ++x;
            if(op == 0) {
                scanf("%I64d", &y);
                update(st[x], ed[x], y - a[x], 1, n, 1);
                a[x] = y;
            } else {
                printf("%I64d\n", query(st[x], ed[x], 1, n, 1));
            }
        }
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
