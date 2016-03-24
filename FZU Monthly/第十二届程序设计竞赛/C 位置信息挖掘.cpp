//
//  Created by TaoSama on 2015-05-06
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int par[2 * N], city[N], rank[3 * N];
void init(int n) {
    for(int i = 1; i <= n; ++i)
        par[i] = i, rank[i] = 0;
}

int find(int x) {
    int t = x, f;
    while(t != par[t]) t = par[t];
    while(x != par[x])
        f = par[x], par[x] = t, x = f;
    return x;
}

void unite(int x, int y) {
    x = find(x); y = find(y);
    if(x == y) return;
    if(rank[x] < rank[y]) par[x] = y;
    else {
        par[y] = x;
        if(rank[x] == rank[y]) ++rank[x];
    }
}

int n, m, q;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &m, &q) == 3) {
        memset(city, 0, sizeof city);
        init(n + m); //i->1..n  u->n+1..n+m
        int x, y, z;
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d", &x, &y);
            if(y) city[x] = y;
        }
        for(int i = 1; i <= m; ++i) {
            scanf("%d%d%d", &x, &y, &z);
            if(z) city[x + n] = city[y] = z;
            par[find(x + n)] = par[find(y)];
        }

        for(int i = 1; i <= n + m; ++i)
            if(city[i]) city[find(i)] = city[i];

        for(int i = 1; i <= q; ++i) {
            scanf("%d%d", &x, &y);
            int ans;
            if(x) ans = city[find(y + n)];
            else ans = city[find(y)];
            printf("%d\n", ans);
        }
    }
    return 0;
}
