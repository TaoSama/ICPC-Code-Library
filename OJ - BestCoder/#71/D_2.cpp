//
//  Created by TaoSama on 2016-02-10
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
struct Edge {
    int u, v, c;
    bool operator<(const Edge& e) const {
        return c < e.c;
    }
    bool operator==(const Edge& e) const {
        return u == e.u && v == e.v && c == e.c;
    }
} edge[15005];

Edge minEdge;
vector<Edge> G[2005];

bool dfs(int u, int fa, int t, multiset<int>& s) {
    if(u == t) return true;
    for(Edge& e : G[u]) {
        int v = e.v;
        if(v == fa) continue;
        if(dfs(v, u, t, s)) {
            minEdge = min(minEdge, e);
            return true;
        }
    }
    return false;
}

void del(multiset<int>& s) {
    int u = minEdge.u, v = minEdge.v, c = minEdge.c;
    s.erase(s.find(c));
    G[u].erase(find(G[u].begin(), G[u].end(), minEdge));
    swap(minEdge.u, minEdge.v);
    G[v].erase(find(G[v].begin(), G[v].end(), minEdge));

}

int p[2005];
int find(int x) {
    return p[x] = p[x] == x ? x : find(p[x]);
}

bool unite(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return false;
    p[u] = v;
    return true;
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
        for(int i = 1; i <= m; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            edge[i] = (Edge) {u, v, c};
        }
        sort(edge + 1, edge + 1 + m);
        multiset<int> s;
        for(int i = 1; i <= n; ++i) {
            p[i] = i;
            G[i].clear();
        }

        int ans = 2e9, cnt = 0;
        for(int i = 1; i <= m; ++i) {
            int u = edge[i].u, v = edge[i].v, c = edge[i].c;
            if(unite(u, v)) ++cnt;
            else {
                minEdge.c = 2e9;
                dfs(u, -1, v, s);
                del(s);
            }
            s.insert(c);
            G[u].push_back((Edge) {u, v, c});
            G[v].push_back((Edge) {v, u, c});
            if(cnt == n - 1) ans = min(ans, c - *s.begin());
        }
        if(ans == 2e9) ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}
