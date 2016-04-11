//
//  Created by TaoSama on 2016-04-09
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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

int n, m;
struct Edge {
    int u, v, c;
    bool operator<(const Edge& e) const {
        return c < e.c;
    }
} edge[N];


struct DSU {
    int n, p[N];
    void init(int _n) {
        n = _n;
        for(int i = 1; i <= n; ++i) p[i] = i;
    }
    int find(int x) {
        return p[x] = p[x] == x ? x : find(p[x]);
    }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        p[x] = y;
        return true;
    }
} dsu;

int w[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        int ans = INF;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", w + i);
            ans = min(ans, w[i]);
        }
        for(int i = 1; i <= m; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            edge[i] = (Edge) {u, v, 2 * c + w[u] + w[v]};
        }
        sort(edge + 1, edge + 1 + m);

        dsu.init(n);
        int cnt = 0;
        for(int i = 1; i <= m; ++i) {
            int u = edge[i].u, v = edge[i].v;
            if(dsu.unite(u, v)) {
                ans += edge[i].c;
                if(++cnt == n - 1) break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
