//
//  Created by TaoSama on 2015-05-20
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 3e5 + 10;

int n, m;
struct E {
    int id, v, cost;
};
typedef pair<long long, int> P;

vector<E> G[N];

long long d[N];
int minCost[N], ed[N];
bool used[N];

long long dijkstra(int s) {
    memset(d, 0x3f, sizeof d);
    memset(minCost, 0x3f, sizeof minCost);
    //memset(used, false, sizeof used);
    d[s] = minCost[s] = 0;
    priority_queue<P, vector<P>, greater<P> > pq;
    pq.push(P(0, s));
    long long ret = 0;
    while(!pq.empty()) {
        P p = pq.top(); pq.pop();
        int u = p.second;
        long long dis = p.first;
        if(dis > d[u]) continue;
        //used[u] = true;
        ret += minCost[u];
        for(int i = 0; i < G[u].size(); ++i) {
            E &e = G[u][i];
            if(d[e.v] > d[u] + e.cost) {
                d[e.v] = d[u] + e.cost;
                minCost[e.v] = e.cost;
                ed[e.v] = e.id;
                pq.push(P(d[e.v], e.v));
            } else if(d[e.v] == d[u] + e.cost &&
                      minCost[e.v] > e.cost) {
                minCost[e.v] = e.cost;
                ed[e.v] = e.id;
            }
        }
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
		for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= m; ++i) {
            int x, y, z; scanf("%d%d%d", &x, &y, &z);
            G[x].push_back((E) {i, y, z});
            G[y].push_back((E) {i, x, z});
        }
        int s; scanf("%d", &s);
        long long ans = dijkstra(s);
        printf("%I64d\n", ans);
        for(int i = 1; i <= n; ++i)
            if(i != s) printf("%d ", ed[i]);
        puts("");
    }
    return 0;
}
