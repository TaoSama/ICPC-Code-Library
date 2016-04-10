//
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

struct DSU {
    int n, p[N];
    void init(int _n) {
        n = _n;
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
    bool same(int x, int y) {
        return find(x) == find(y);
    }
} dsu;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        int n, m; scanf("%d%d", &n, &m);
        dsu.init(n);
        for(int i = 1; i <= m; ++i) {
            int op, a, b; scanf("%d%d%d", &op, &a, &b);
            if(op == 1) dsu.unite(a, b);
            else puts(dsu.same(a, b) ? "Yes" : "No");
        }
    }
    return 0;
}
