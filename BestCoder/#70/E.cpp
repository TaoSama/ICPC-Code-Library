//
//  Created by TaoSama on 2015-08-18
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
const int N = 3e3, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 5e5 + 10;

int n, m;

int head[N], pnt[M], cap[M], cost[M], nxt[M], cnt;
void add_edge(int u, int v, int c, int w) {
    pnt[cnt] = v;
    cap[cnt] = w;
    cost[cnt] = c;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

void add_double(int u, int v, int c, int w1, int w2 = 0) {
    add_edge(u, v, c, w1);
    add_edge(v, u, -c, w2);
}

int d[N], in[N], delta[N], pre[N];
bool spfa(int s, int t) {
    queue<int> q; q.push(s);
    for(int i = s; i <= t; ++i) d[i] = INF, in[i] = false;
    d[s] = 0; delta[s] = INF; in[s] = true;
    while(q.size()) {
        int u = q.front(); q.pop();
        in[u] = false;
        for(int i = head[u]; ~i; i = nxt[i]) {
            int v = pnt[i];
            if(cap[i] > 0 && d[v] > d[u] + cost[i]) {
                d[v] = d[u] + cost[i];
                delta[v] = min(delta[u], cap[i]);
                pre[v] = i;
                if(!in[v]) q.push(v), in[v] = true;
            }
        }
    }
    return d[t] != INF;
}

int minCostMaxFlow(int s, int t, int flow) {
    int cost = 0;
    while(spfa(s, t)) {
        flow -= delta[t];
        cost += delta[t] * d[t];
        if(flow <= 0) break;

        for(int i, u = t; u != s; u = pnt[i ^ 1]) {
            i = pre[u];
            cap[i] -= delta[t];
            cap[i ^ 1] += delta[t];
        }
    }
    return cost;
}

int z[55][55];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &m, &n);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                scanf("%d", &z[i][j]);

        cnt = 0; memset(head, -1, sizeof head);
        int s = 0, t = n + n * m + 1;
        for(int i = 1; i <= n; ++i) add_double(s, i, 0, 1); //source
        for(int j = 1; j <= m; ++j) {
            for(int k = 1; k <= n; ++k) {
                add_double(n + (j - 1) * n + k, t, 0, 1);  //sink
                for(int i = 1; i <= n; ++i)
                    add_double(i, n + (j - 1) * n + k, k * z[i][j], 1);
            }
        }

        printf("%d\n", minCostMaxFlow(s, t, n));
    }
    return 0;
}
