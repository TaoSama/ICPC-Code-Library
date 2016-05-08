//
//  Created by TaoSama on 2016-05-06
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
const int N = 500 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, s, d;
int a[N];
int f[N], cnt[N], cost[N], pre[N];
bool done[N];

struct Edge {
    int v, c;
};
vector<Edge> G[N];
typedef pair<int, int> P;

void dijkstra() {
    priority_queue<P, vector<P>, greater<P> > q;
    q.push({0, s});
    memset(f, 0x3f, sizeof f);
    memset(cnt, 0, sizeof cnt);
    memset(cost, 0, sizeof cost);
    memset(done, false, sizeof done);
    f[s] = 0; cnt[s] = 1; cost[s] = a[s];
    while(q.size()) {
        int u = q.top().second; q.pop();
        if(done[u]) continue;
        done[u] = true;
        for(Edge& e : G[u]) {
            int v = e.v, c = e.c;
            if(f[v] > f[u] + c) {
                f[v] = f[u] + c;
                cnt[v] = cnt[u];
                cost[v] = cost[u] + a[v];
                pre[v] = u;
                q.push({f[v], v});
            } else if(f[v] == f[u] + c) {
                cnt[v] += cnt[u];
                if(cost[v] < cost[u] + a[v]) {
                    cost[v] = cost[u] + a[v];
                    pre[v] = u;
                }
                q.push({f[v], v});
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    scanf("%d%d%d%d", &n, &m, &s, &d);
    for(int i = 0; i < n; ++i) scanf("%d", a + i);
    for(int i = 0; i < m; ++i) {
        int u, v, c; scanf("%d%d%d", &u, &v, &c);
        G[u].push_back({v, c});
        G[v].push_back({u, c});
    }
    dijkstra();

    printf("%d %d\n", cnt[d], cost[d]);
    vector<int> path;
    for(int u = d; ; u = pre[u]) {
        path.push_back(u);
        if(u == s) break;
    }
    for(int i = path.size() - 1; ~i; --i)
        printf("%d%c", path[i], " \n"[i == 0]);

#ifdef LOCAL
    printf("\n\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
