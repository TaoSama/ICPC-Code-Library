//
//  Created by TaoSama on 2015-12-18
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
const int M = 2e7 + 10;

int n, C, ans;

void getMax(int &x, int y) {x = max(x, y);}

struct BIT {
    int mx[M];
    void del(int i) {
        for(; i < M; i += i & -i) mx[i] = 0;
    }
    void update(int i, int v) {
        for(; i < M; i += i & -i) getMax(mx[i], v);
    }
    int query(int i) {
        int ret = 0;
        for(; i; i -= i & -i) getMax(ret, mx[i]);
        return ret;
    }
} bit;

struct Edge {
    int v, nxt, c, b;
} edge[N << 1];
int head[N], cnt;

void addEdge(int u, int v, int c, int b) {
    edge[cnt] = (Edge) {v, head[u], c, b};
    head[u] = cnt++;
    edge[cnt] = (Edge) {u, head[v], c, b};
    head[v] = cnt++;
}

bool vis[N];
int sz[N], mx[N], centroid;

int getAll(int u, int f) {
    int ret = 1;
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(v == f || vis[v]) continue;
        ret += getAll(v, u);
    }
    return ret;
}

void getCentroid(int u, int f, int all) {
    sz[u] = 1; mx[u] = 0;
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(v == f || vis[v]) continue;
        getCentroid(v, u, all);
        sz[u] += sz[v];
        getMax(mx[u], sz[v]);
    }
    getMax(mx[u], all - sz[u]);
    if(!centroid || mx[u] < mx[centroid]) centroid = u;
}

typedef pair<int, int> P;

void getPath(int u, int f, int cost, int profit, vector<P>& path) {
    if(cost > C) return;
    path.push_back(P(cost, profit));
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(v == f || vis[v]) continue;
        getPath(v, u, cost + edge[i].c, profit + edge[i].b, path);
    }
}

void solve(int u) {
    centroid = 0;
    getCentroid(u, -1, getAll(u, -1));
    int s = centroid;
    vis[s] = true;

    for(int i = head[s]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(vis[v]) continue;
        solve(v);
    }

    vector<P> dummy;
    for(int i = head[s]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(vis[v]) continue;

        vector<P> path;
        getPath(v, s, edge[i].c, edge[i].b, path);
        for(P &p : path) getMax(ans, p.second + bit.query(C - p.first));
        for(P &p : path) bit.update(p.first, p.second);
        dummy.insert(dummy.end(), path.begin(), path.end());
    }

    for(P &p : dummy) bit.del(p.first);
    vis[s] = false;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        cnt = 0; memset(head, -1, sizeof head);
        scanf("%d", &n);
        for(int i = 1; i < n; ++i) {
            int u, v, c, b; scanf("%d%d%d%d", &u, &v, &c, &b);
            addEdge(u, v, c, b);
        }
        scanf("%d", &C);

        ans = 0;
        solve(1);
        printf("%d\n", ans);
    }
    return 0;
}
