//
//  Created by TaoSama on 2017-04-30
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct Point {
    int x, y, id;
    Point() {}
    Point(int x, int y, int id): x(x), y(y), id(id) {}
    Point operator-(const Point& p) const {
        return Point(x - p.x, y - p.y, -1);
    }
    double ang() {
        return atan2(y, x);
    }
    bool operator<(const Point& p) const {
        if(x != p.x) return x < p.x;
        return y < p.y;
    }
};

int n;
Point ps[N];
vector<int> G[N];

int sz[N];
void dfs1(int u, int fa) {
    sz[u] = 1;
    for(int v : G[u]) {
        if(v == fa) continue;
        dfs1(v, u);
        sz[u] += sz[v];
    }
}

int ans[N];
void dfs2(int u, int fa, int l, int n) {
    sort(ps + l, ps + l + n);
    ans[u] = ps[l].id;
    sort(ps + l + 1, ps + l + n, [&](const Point & A, const Point & B) {
        return (A - ps[l]).ang() < (B - ps[l]).ang();
    });
//    pr(u); pr(l); prln(n);
    ++l;
    for(int v : G[u]) {
        if(v == fa) continue;
        dfs2(v, u, l, sz[v]);
        l += sz[v];
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    for(int i = 1; i < n; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        ps[i] = Point(x, y, i);
    }

    dfs1(1, 0);
    dfs2(1, 0, 1, n);
    for(int i = 1; i <= n; ++i) printf("%d%c", ans[i], " \n"[i == n]);

    return 0;
}
