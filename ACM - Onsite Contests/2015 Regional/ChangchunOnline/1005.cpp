//
//  Created by TaoSama on 2015-09-13
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
const int N = 2e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 1e5 + 10;

int n, m, q;
long long ans[5005];
struct Edge {
    int u, v, c;
    Edge() {}
    Edge(int u, int v, int c) : u(u), v(v), c(c) {}
    bool operator< (const Edge& rhs) const {
        return c < rhs.c;
    }
} G[M];
struct Query {
    int d, id;
    Query() {}
    Query(int d, int id): d(d), id(id) {}
    bool operator< (const Query& rhs) const {
        return d < rhs.d;
    }
} Q[5005];

long long now;
int par[N], rnk[N], num[N];

int find(int x) {
    return par[x] == x ? x : find(par[x]);
}

void unite(int x, int y) {
    x = find(x); y = find(y);
    if(x == y) return;
    now += num[x] * num[y];
    if(rnk[x] < rnk[y]) {
        par[x] = y;
        num[y] += num[x]; num[x] = 0;
    } else {
        par[y] = x;
        if(rnk[x] == rnk[y]) ++rnk[x];
        num[x] += num[y]; num[y] = 0;
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &m, &q);
        for(int i = 0; i < m; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            G[i] = Edge(u, v, c);
        }
        sort(G, G + m);
        for(int i = 0; i < q; ++i) {
            int x; scanf("%d", &x);
            Q[i] = Query(x, i);
        }
        sort(Q, Q + q);

        for(int i = 1; i <= n; ++i) {
            par[i] = i;
            rnk[i] = 0;
            num[i] = 1;
        }

        memset(ans, 0, sizeof ans);
        now = 0;
        for(int i = 0, j = 0; i < q; ++i) {
            int cur = Q[i].d;
            while(j < m) {
                Edge &e = G[j];
                if(e.c <= cur) {
                    unite(e.u, e.v);
                } else break;
                ++j;
            }
            ans[Q[i].id] = now;
        }
        for(int i = 0; i < q; ++i) printf("%I64d\n", ans[i] * 2);
    }
    return 0;
}
