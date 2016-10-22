//
//  Created by TaoSama on 2016-09-07
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
struct Edge {
    int v, c, t;
};
vector<Edge> G[N], T[N];
vector<int> id[N];

typedef long long LL;
typedef pair<LL, int> Sta;
LL f[N];
bool done[N];

LL dijkstra(int s, int t) {
    priority_queue<Sta, vector<Sta>, greater<Sta> > q;
    memset(done, 0, sizeof done);
    memset(f, 0x3f, sizeof f);
    f[s] = 0; q.push({0, s});
    while(q.size()) {
        int u = q.top().second; q.pop();
        if(done[u]) continue;
        done[u] = true;

        for(Edge& e : T[u]) {
            int v = e.v, c = e.c;
            if(!done[v] && f[v] > f[u] + c) {
                f[v] = f[u] + c;
                q.push({f[v], v});
            }
        }
    }
    return f[t];
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= n; ++i) id[i].clear(), G[i].clear();
        for(int i = 1; i <= 2 * m + 2; ++i) T[i].clear();

        for(int i = 1; i <= m; ++i) {
            int u, v, c, t; scanf("%d%d%d%d", &u, &v, &c, &t);
            G[u].push_back({v, c, t});
            G[v].push_back({u, c, t});
        }

        auto cmp = [&](const Edge & e1, const Edge & e2) {
            return e1.c < e2.c;
        };
        for(int i = 1; i <= n; ++i) sort(G[i].begin(), G[i].end(), cmp);

        int idx = 0;
        for(int i = 1; i <= n; ++i) {
            id[i].resize(G[i].size());
            for(int j = 0; j < G[i].size(); ++j)
                id[i][j] = ++idx;
        }

        int src = ++idx, des = ++idx;
        for(int i = 0; i < G[1].size(); ++i) T[src].push_back({id[1][i], 0, 0});
        for(int i = 0; i < G[n].size(); ++i) T[id[n][i]].push_back({des, 0, 0});
        for(int u = 1; u <= n; ++u) {
            for(int i = 0; i < G[u].size(); ++i) {
                Edge& e = G[u][i];
                int v = e.v, c = e.c, t = e.t;
                int p = lower_bound(G[v].begin(), G[v].end(), (Edge) {u, c, t}, cmp)
                - G[v].begin();
                int x = id[u][i], y = id[v][p];
                T[x].push_back({y, t, 0});

                if(i) {
                    int y = id[u][i - 1], t = G[u][i].c - G[u][i - 1].c;
                    T[y].push_back({x, t, 0});
                    T[x].push_back({y, t, 0});
                }
            }
        }
        printf("%lld\n", dijkstra(src, des));
    }

    return 0;
}
