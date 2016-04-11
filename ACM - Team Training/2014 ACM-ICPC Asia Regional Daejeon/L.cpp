//
//  Created by TaoSama on 2015-12-14
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
const int M = 1e6 + 10;

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

int minCostMaxFlow(int s, int t) {
    int ret = 0;
    while(spfa(s, t)) {
        ret += d[t] * delta[t];
        for(int i, u = t; u != s; u = pnt[i ^ 1]) {
            i = pre[u];
            cap[i] -= delta[t];
            cap[i ^ 1] += delta[t];
        }
    }
    return ret;
}

int n, x[N], y[N], w[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        cnt = 0; memset(head, -1, sizeof head);
        vector<int> xs;
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d%d", x + i, y + i, w + i);
            xs.push_back(x[i]);
            xs.push_back(++y[i]);
        }
        sort(xs.begin(), xs.end());
        xs.resize(unique(xs.begin(), xs.end()) - xs.begin());

        int s = 0, t = xs.size() + 1;
        add_double(s, 1, 0, 2); add_double(xs.size(), t, 0, 2);
        for(int i = 1; i < xs.size(); ++i) add_double(i, i + 1, 0, INF);
        for(int i = 1; i <= n; ++i) {
            int u = lower_bound(xs.begin(), xs.end(), x[i]) - xs.begin() + 1;
            int v = lower_bound(xs.begin(), xs.end(), y[i]) - xs.begin() + 1;
            add_double(u, v, -w[i], 1);
        }
        printf("%d\n", -minCostMaxFlow(s, t));
    }
    return 0;
}
