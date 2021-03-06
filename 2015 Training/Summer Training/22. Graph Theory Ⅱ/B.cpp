//
//  Created by TaoSama on 2015-08-17
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int pnt[N], nxt[N], head[N], cap[N], cnt;

void add_edge(int u, int v, int w) {
    pnt[cnt] = v;
    cap[cnt] = w;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

int delta[105], pre[105];
int maxFlow(int s, int t) {
    int flow = 0;
    while(true) {
        queue<int> q;
        memset(delta, 0, sizeof delta);
        q.push(s); delta[s] = INF;
        while(q.size()) {
            int u = q.front(); q.pop();
            for(int i = head[u]; ~i; i = nxt[i]) {
                int v = pnt[i];
                if(!delta[v] && cap[i] > 0) {
                    delta[v] = min(delta[u], cap[i]);
                    pre[v] = i;
                    q.push(v);
                }
            }
            if(delta[t]) break;
        }
        if(!delta[t]) break;

        flow += delta[t];
        for(int i, u = t; u != s; u = pnt[i ^ 1]) {
            i = pre[u];
            cap[i] -= delta[t];
            cap[i ^ 1] += delta[t];
        }
    }
    return flow;
}

int n, m, s, t;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d", &n) == 1 && n) {
        scanf("%d%d%d", &s, &t, &m);
        cnt = 0; memset(head, -1, sizeof head);
        for(int i = 1; i <= m; ++i) {
            int u, v, w; scanf("%d%d%d", &u, &v, &w);
            add_edge(u, v, w);
            add_edge(v, u, w);
        }
        printf("Network %d\nThe bandwidth is %d.\n\n", ++kase, maxFlow(s, t));
    }
    return 0;
}
