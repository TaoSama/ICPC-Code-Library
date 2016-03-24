//
//  Created by TaoSama on 2015-08-27
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
const int N = 1e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 1e5 + 10;

int n, m, k, sum;

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
bool spfa(int s, int t, int &f, long long & c) {
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
    if(d[t] == INF) return false;

    f += delta[t];
    c += 1LL * delta[t] * d[t];
    for(int i, u = t; u != s; u = pnt[i ^ 1]) {
        i = pre[u];
        cap[i] -= delta[t];
        cap[i ^ 1] += delta[t];
    }
    return true;
}

bool minCostMaxFlow(int s, int t) {
    int flow = 0; long long cost = 0;
    while(spfa(s, t, flow, cost));
    return n - flow >= sum - (-cost);
}

int b[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int T; scanf("%d", &T);
    int kase = 0;
    while(T--) {
        scanf("%d%d%d", &n, &m, &k);
        sum = cnt = 0; memset(head, -1, sizeof head);
        for(int i = 1; i <= m; ++i) {
            scanf("%d", b + i);
            sum += b[i];
        }
        //s->candy we only care about special candies now
        int s = 0, t = n + m + 1;
        for(int i = 1; i <= n; ++i) add_double(s, i, 0, 1);
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                int x; scanf("%d", &x);
                if(x) add_double(j, n + i, 0, 1); //candy -> kid
            }
            add_double(n + i, t, -k, b[i] / k); //can take b[i] / k * k
            //1 * b[i] % k
            if(b[i] % k > 1) add_double(n + i, t, -b[i] % k, 1);
        }
        printf("Case #%d: %s\n", ++kase, minCostMaxFlow(s, t) ? "YES" : "NO");
    }
    return 0;
}
