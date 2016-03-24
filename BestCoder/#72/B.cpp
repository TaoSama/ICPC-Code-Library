//
//  Created by TaoSama on 2016-02-13
//  Copyright (c) 2016 TaoSama. All rights reserved.
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
const int N = 3e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
struct Edge {
    int u, v, c;
};
vector<Edge> G[30];

struct DSU {
    int p[N];
    void init() {
        for(int i = 1; i <= n; ++i) p[i] = i;
    }
    int find(int x) {
        return p[x] = p[x] == x ? x : find(p[x]);
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return;
        p[x] = y;
    }
    int count() {
        int cc = 0;
        for(int i = 1; i <= n; ++i) cc += p[i] == i;
        return cc;
    }
} dsu;

bool isConnected(int x, int p) {
    dsu.init();
    for(Edge& e : G[x]) {
        if(e.c >> p & 1) {
            dsu.unite(e.u, e.v);
        }
    }
    return dsu.count() == 1;
}

int solve(int x) {
    int ret = 1 << x;
    for(int i = x - 1; ~i; --i) {
        if(isConnected(x, i))
            ret |= 1 << i;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < 30; ++i) G[i].clear();
        for(int i = 1; i <= m; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            for(int j = 0; j < 30; ++j)
                if(c >> j & 1) G[j].push_back((Edge) {u, v, c});
        }
        int ans = 0;
        for(int i = 29; ~i; --i) {
            if(isConnected(i, i)) {
                ans = solve(i);
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
