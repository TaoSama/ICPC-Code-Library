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
const int N = 2e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 1e5 + 10;

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

int in[N], d[N], delta[N], pre[N];
bool spfa(int s, int t) {
    queue<int> q; q.push(s);
    for(int i = s; i <= t; ++i) d[i] = INF, in[i] = false;
    delta[s] = INF; d[s] = 0; in[s] = true;
    while(q.size()) {
        int u = q.front(); q.pop();
        in[u] = false;
        for(int i = head[u]; ~i; i = nxt[i]) {
            int v = pnt[i];
            if(cap[i] > 0 && d[v] > d[u] + cost[i]) {

                delta[v] = min(delta[u], cap[i]);
                d[v] = d[u] + cost[i];
                pre[v] = i;
                if(!in[v]) q.push(v), in[v] = true;
            }
        }
    }
    return d[t] != INF;
}

int minCostMaxFlow(int s, int t, int &flow) {
    int ret = 0;
    while(spfa(s, t)) {
        flow += delta[t];
        ret += d[t] * delta[t];
        for(int i, u = t; u != s; u = pnt[i ^ 1]) {
            i = pre[u];
            cap[i] -= delta[t];
            cap[i ^ 1] += delta[t];
        }
    }
    return ret;
}

int n;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1 && n) {
        cnt = 0; memset(head, -1, sizeof head);
        int s = 0, t = 2 * n + 1;
        for(int u = 1, v; u <= n; ++u) {
            add_double(s, u, 0, 1);
            add_double(n + u, t, 0, 1);
            while(scanf("%d", &v) && v) {
                int c; scanf("%d", &c);
                add_double(u, n + v, c, 1);
            }
        }
        int cnt = 0, ans = minCostMaxFlow(s, t, cnt);
        if(cnt < n) puts("N");
        else printf("%d\n", ans);
    }
    return 0;
}
