//
//  Created by TaoSama on 2016-02-28
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
const int N = 2e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;

struct DSU {
    int n, m;
    int r[N], p[N];
    int row[N], col[N];
    void init(int _n, int _m) {
        n = _n; m = _m;
        for(int i = 1; i <= n + m; ++i) {
            p[i] = i;
            r[i] = 0;
            if(i <= n) row[i] = 1, col[i] = 0;
            else row[i] = 0, col[i] = 1;
        }
    }
    int find(int x) {
        return p[x] = p[x] == x ? x : find(p[x]);
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return;
        if(r[x] > r[y]) swap(x, y);
        p[x] = y;
        if(r[x] == r[y]) ++ r[y];
        row[y] += row[x]; row[x] = 0;
        col[y] += col[x]; col[x] = 0;
    }
    int get() {
        int ret = 0;
        for(int i = 1; i <= n + m; ++i) {
//          printf("%d: %d %d\n", i, row[i], col[i]);
            ret += max(row[i], col[i]);
        }
        return ret;
    }
} dsu;

int row[105][105];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2 && (n || m)) {
        dsu.init(n, m);
        memset(row, 0, sizeof row);
        for(int i = 1; i <= n; ++i) {
            int x, y; scanf("%d%d", &x, &y);
            row[x][y] = i, row[x + 1][y] = i;
        }

        for(int i = 1; i <= m; ++i) {
            int x, y; scanf("%d%d", &x, &y);
            if(row[x][y + 1]) dsu.unite(n + i, row[x][y + 1]);
            if(row[x][y]) dsu.unite(n + i, row[x][y]);
        }

        int ans = dsu.get();
        printf("%d\n", ans);
    }
    return 0;
}
