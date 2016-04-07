//
//  Created by TaoSama on 2016-04-07
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
const int N = 5e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct DSU {
    int n, p[N * N], r[N * N];
    void init(int _n) {
        n = _n;
        for(int i = 0; i < n; ++i) p[i] = i, r[i] = 0;
    }
    int find(int x) {
        return p[x] = p[x] == x ? x : find(p[x]);
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return;
        if(r[x] > r[y]) swap(x, y);
        if(r[x] == r[y]) ++ r[y];
        p[x] = y;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
} dsu;

int n, m, q;
char a[N][N];
pair<int, int> qs[N * N];

inline int ID(int x, int y) {
    return x * m + y;
}

void process(int i, int j) {
    static int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};
    if(a[i][j] == '1') return;
    for(int k = 0; k < 4; ++k) {
        int x = i + d[k][0], y = j + d[k][1];
        if(y < 0 || y >= m) continue;
        if(x < 0) dsu.unite(ID(i, j), n * m);
        else if(x >= n) dsu.unite(ID(i, j), n * m + 1);
        else if(a[x][y] == '0') dsu.unite(ID(i, j), ID(x, y));
    }
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
        for(int i = 0; i < n; ++i) scanf("%s", a[i]);
        scanf("%d", &q);
        for(int i = 0; i < q; ++i) {
            int x, y; scanf("%d%d", &x, &y);
            qs[i] = {x, y};
            a[x][y] = '1';
        }

        dsu.init(n * m + 2);
        int s = n * m, t = s + 1;
        for(int i = 0; i < m; ++i) {
            if(a[0][i] == '0') dsu.unite(s, ID(0, i));
            if(a[n - 1][i] == '0') dsu.unite(ID(n - 1, i), t);
        }
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                process(i, j);

        if(dsu.same(s, t)) {puts("-1"); continue;}
        for(int i = q - 1; ~i; --i) {
            int x = qs[i].first, y = qs[i].second;
            a[x][y] = '0';
            process(x, y);
            if(dsu.same(s, t)) {
                printf("%d\n", i + 1);
                break;
            }
        }
    }
    return 0;
}
