//
//  Created by TaoSama on 2016-02-03
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int p[N], r[N], id[N];

int find(int x) {
    return p[x] == x ? x : find(p[x]);
}

int unite(int x, int y, int q) {
    x = find(x), y = find(y);
    if(x == y) return false;
    if(r[x] > r[y]) swap(x, y);
    p[x] = y;
    id[x] = q;
    if(r[x] == r[y]) ++r[y];
    return true;
}

int lca(int u, int v) {
    set<int> s;
    while(u != p[u]) s.insert(u), u = p[u];
    s.insert(u);
    while(!s.count(v) && v != p[v]) v = p[v];
    if(!s.count(v)) return 0;
    return v;
}

int query(int x, int y) {
    int _lca = lca(x, y);
//  printf("u: %d v: %d lca: %d\n", x, y, _lca);
    if(!_lca) return 0;
    int ret = 0;
    while(x != _lca) ret = max(ret, id[x]), x = p[x];
    while(y != _lca) ret = max(ret, id[y]), y = p[y];
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
        for(int i = 1; i <= n; ++i) p[i] = i, r[i] = 0;
        int ans = 0, cc = n;
        for(int i = 1; i <= m; ++i) {
            int op, x, y; scanf("%d%d%d", &op, &x, &y);
            x ^= ans, y ^= ans;
//          printf("op..... %d %d %d\n", op, x, y);
            if(op == 0) {
                cc -= unite(x, y, i);
                ans = cc;
            } else {
                ans = query(x, y);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
