//
//  Created by TaoSama on 2016-04-23
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
#include <functional>
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
    int v, d, c;
};
vector<Edge> G[N];

typedef long long LL;
typedef pair<LL, int> P;
LL f[N], g[N];
bool done[N];
pair<LL, LL> dijkstra() {
    priority_queue<P, vector<P>, greater<P> > q;
    q.push({0, 0});
    memset(f, 0x3f, sizeof f);
    memset(g, 0x3f, sizeof g);
    memset(done, 0, sizeof done);
    f[0] = g[0] = 0;
    while(q.size()) {
        int u = q.top().second; q.pop();
        if(done[u]) continue;
        done[u] = true;
        for(Edge& e : G[u]) {
            int v = e.v, d = e.d, c = e.c;
            if(f[v] > f[u] + d || f[v] == f[u] + d && g[v] > c) {
                f[v] = f[u] + d;
                g[v] = c;
                q.push({f[v], v});
            }
        }
    }
    pair<LL, LL> ret = {0, 0};
    for(int i = 0; i < n; ++i) {
        ret.first += f[i];
        ret.second += g[i];
    }
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
        for(int i = 0; i < n; ++i) G[i].clear();
        for(int i = 1; i <= m; ++i) {
            int u, v, d, c; scanf("%d%d%d%d", &u, &v, &d, &c);
            G[u].push_back({v, d, c});
            G[v].push_back({u, d, c});
        }
        auto ans = dijkstra();
        printf("%lld %lld\n", ans.first, ans.second);
    }
    return 0;
}
