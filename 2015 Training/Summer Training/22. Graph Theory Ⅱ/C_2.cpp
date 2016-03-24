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
const int N = 205, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int pnt[N << 1], nxt[N << 1], cap[N << 1], head[N << 1], cnt;
void add_edge(int u, int v, int w) {
    pnt[cnt] = v;
    cap[cnt] = w;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

int delta[N], pre[N]; //alternative flow, current vertex's index
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
                    pre[v] = i;  //record the current edge's index
                    q.push(v);
                }
            }
            if(delta[t]) break;  //found an augmenting path
        }
        if(!delta[t]) break;  //no more augmenting path, it is already max flow

        //update the vertex's residual flow in the current augmenting path
        flow += delta[t];
        for(int u = t, i; u != s; u = pnt[i ^  1]) { //previous vertex
            i = pre[u];  //previous edge's index
            cap[i] -= delta[t];
            cap[i ^ 1] += delta[t];
        }
    }
    return flow;
}

int n, m;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &m, &n) == 2) {
        cnt = 0; memset(head, -1, sizeof head);
        for(int i = 1; i <= m; ++i) {
            int u, v, w; scanf("%d%d%d", &u, &v, &w);
            add_edge(u, v, w);
            add_edge(v, u, 0);
        }
        printf("%d\n", maxFlow(1, n));
    }
    return 0;
}
