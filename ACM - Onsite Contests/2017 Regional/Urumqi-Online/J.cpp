
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 1e5 + 10;

struct Edge {
    int v, nxt, cost, cap;
} edge[M];
int head[N], cnt;

void addEdge(int u, int v, int c, int w1, int w2 = 0) {
    // printf("%d %d %d %d\n", u, v, c, w1);
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

int n, m;

map<string, int> mp;
int ID(const string& s) {
    if(!mp.count(s)) {
        mp[s] = ++n;
    }
    return mp[s];
}

char src[N], des[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; scanf("%d", &t);
    while(t--) {
        int m; scanf("%d", &m);
        n = 0; mp.clear();
        vector<pair<pair<int, int>, int>> g;
        int sum = 0;
        for(int i = 1; i <= m; ++i) {
            int c; scanf("%s%s%d", src, des, &c);
            int u = ID(src), v = ID(des);
            g.push_back({{u, v}, c});
            // printf("%d %d %d\n", u, v, c);
            sum += c + c;
        }
        
        cnt = 0; 
        for(int i = 0; i < 3 * n; ++i) head[i] = -1;
        int dalian = mp["Dalian"], xian = mp["Xian"], shanghai = mp["Shanghai"];
        // printf("dalian = %d xian = %d shanghai = %d\n", dalian, xian, shanghai);
        if(!dalian || !xian || !shanghai) {
            puts("-1");
            continue;
        }
        int s = 0, t = 2 * n + 1;
        // printf("s = %d t = %d\n", s, t);
        addEdge(s, shanghai, 0, 2);
        addEdge(xian + n, t, 0, 1); 
        addEdge(dalian + n, t, 0, 1);
        addEdge(shanghai, shanghai + n, 0, 1);
        for(int i = 1; i <= n; ++i) {
            addEdge(i, i + n, 0, 1); 
        }
        for(const auto& e : g) {
            int u, v, c = e.second;
            tie(u, v) = e.first;
            addEdge(u + n, v, c, INF);
            addEdge(v + n, u, c, INF);
        }
        int flow = 0, cost = 0; 
        minCostMaxFlow(s, t, flow, cost);
        // printf("flow = %d\n", flow);
        if(flow == 2) {
            printf("%d\n", cost);
        }
        else puts("-1");
    }
    return 0;
}
