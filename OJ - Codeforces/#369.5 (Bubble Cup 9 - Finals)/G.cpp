//
//  Created by TaoSama on 2016-09-11
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 1e6 + 10;

struct Edge {
    int v, nxt, cost, cap;
} edge[M];
int head[N], cnt;

void addEdge(int u, int v, int c, int w1, int w2 = 0) {
    edge[cnt] = {v, head[u], c, w1};
    head[u] = cnt++;
    edge[cnt] = {u, head[v], -c, w2};
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


int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cnt = 0; memset(head, -1, sizeof head);

    int n, m; string s;
    cin >> n >> s >> m;
    int src = 0, des = n + 1;
    while(m--) {
        string t; int c;
        cin >> t >> c;
        for(int i = 0; i + t.size() <= s.size(); ++i)
            if(s.substr(i, t.size()) == t)
                addEdge(i + 1, i + t.size() + 1, -c, 1);
    }
    int k; cin >> k;
    addEdge(src, 1, 0, k);
    addEdge(n, des, 0, k);
    for(int i = 1; i <= s.size(); ++i)
        addEdge(i, i + 1, 0, k);

    int flow = 0, cost = 0;
    minCostMaxFlow(src, des, flow, cost);
    cout << -cost << endl;

    return 0;
}
