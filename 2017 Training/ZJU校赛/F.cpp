//
//  Created by TaoSama on 2017-04-09
//  Copyright (c) 2016 TaoSama. All rights reserved.
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
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 1e6 + 10;

struct Edge {
    int id, v, nxt, cost, cap;
} edge[M];
int head[N], cnt;

void addEdge(int id, int u, int v, int c, int w1, int w2 = 0) {
    edge[cnt] = {id, v, head[u], c, w1};
    head[u] = cnt++;
    edge[cnt] = {id, u, head[v], -c, w2};
    head[v] = cnt++;
}

int in[N], d[N], delta[N], pre[N];
bool spfa(int s, int t) {
    deque<int> q; q.push_back(s);
    for(int i = s; i <= t; ++i) d[i] = INF, in[i] = false;
    delta[s] = INF; d[s] = 0; in[s] = true;
    while(q.size()) {
        int u = q.front(); q.pop_front();
        in[u] = false;
        for(int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].v, cap = edge[i].cap, cost = edge[i].cost;
            if(cap > 0 && d[v] > d[u] + cost) {
                delta[v] = min(delta[u], cap);
                d[v] = d[u] + cost;
                pre[v] = i;
                if(!in[v]) {
                    in[v] = true;
                    if(q.size() && d[v] <= d[q.front()]) q.push_front(v);
                    else q.push_back(v);
                }
            }
        }
    }
    return d[t] != INF;
}

void minCostMaxFlow(int s, int t, int& flow, int& cost) {
    while(spfa(s, t)) {
        flow += delta[t];
        cost += d[t] * delta[t];
        for(int i, u = t; u != s; u = edge[i ^ 1].v) {
            i = pre[u];
            edge[i].cap -= delta[t];
            edge[i ^ 1].cap += delta[t];
        }
    }
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
            scanf("%d%d", x + i, y + i);
            xs.push_back(x[i]);
            xs.push_back(++y[i]);
        }
        sort(xs.begin(), xs.end());
        xs.resize(unique(xs.begin(), xs.end()) - xs.begin());

        int s = 0, t = xs.size() + 1;
        addEdge(-1, s, 1, 0, 2); addEdge(-1, xs.size(), t, 0, 2);
        for(int i = 1; i < xs.size(); ++i) addEdge(-1, i, i + 1, 0, INF);
        for(int i = 1; i <= n; ++i) {
            int u = lower_bound(xs.begin(), xs.end(), x[i]) - xs.begin() + 1;
            int v = lower_bound(xs.begin(), xs.end(), y[i]) - xs.begin() + 1;
            addEdge(i, u, v, -1, 1);
        }
        int flow = 0, cost = 0;
        minCostMaxFlow(s, t, flow, cost);
        printf("%d\n", n + cost);

        vector<int> ans;
        for(int i = 1; i < cnt; i += 2) {
            if(edge[i].cap == 0 && edge[i ^ 1].cap == 1) {
                if(edge[i ^ 1].v >= 1 && edge[i ^ 1].v <= xs.size() &&
                        edge[i].v >= 1 && edge[i].v <= xs.size())
                    ans.push_back(edge[i].id);
            }
        }
        for(int i = 0; i < ans.size(); ++i) {
            if(i) putchar(' ');
            printf("%d", ans[i]);
        }
        puts("");
    }
    return 0;
}
