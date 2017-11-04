//
//  Created by TaoSama on 2015-12-17
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
const int N = 1e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k, ans;

struct Edge {
    int v, nxt, c;
} edge[N << 1];
int head[N], cnt;

void addEdge(int u, int v, int c) {
    edge[cnt] = (Edge) {v, head[u], c};
    head[u] = cnt++;
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
        mx[u] = max(mx[u], sz[v]);
    }
    mx[u] = max(mx[u], all - sz[u]);
    if(!centroid || mx[u] < mx[centroid]) centroid = u;
}

void getDs(int u, int f, int dis, vector<int>& ds) {
    ds.push_back(dis);
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(v == f || vis[v]) continue;
        getDs(v, u, dis + edge[i].c, ds);
    }
}

int calc(vector<int>& ds) {
    int ret = 0;
    sort(ds.begin(), ds.end());

    for(int i = 0, j = ds.size() - 1; i < j; ++i) {
        while(i < j && ds[i] + ds[j] > k) --j;
        ret += j - i;
    }
    return ret;
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

    vector<int> ds; ds.push_back(0);
    for(int i = head[s]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(vis[v]) continue;

        vector<int> tds;
        getDs(v, s, edge[i].c, tds);

        ans -= calc(tds);
        ds.insert(ds.end(), tds.begin(), tds.end());
    }

    ans += calc(ds);
    vis[s] = false;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &k) == 2 && (n || k)) {
        cnt = 0; memset(head, -1, sizeof head);
        for(int i = 1; i < n; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            addEdge(u, v, c);
            addEdge(v, u, c);
        }

        ans = 0;
        solve(1);
        printf("%d\n", ans);
    }
    return 0;
}
