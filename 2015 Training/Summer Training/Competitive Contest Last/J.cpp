//
//  Created by TaoSama on 2015-09-12
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

int head[N], pnt[M], cap[M], nxt[M], cnt;

void add_edge(int u, int v, int w) {
    pnt[cnt] = v;
    cap[cnt] = w;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

void add_double(int u, int v, int w1, int w2 = 0) {
    add_edge(u, v, w1);
    add_edge(v, u, w2);
}

//lev:= get hierarchical graph
//once we can't a new augmenting path, then it gets long or doesn't exist
//then we need bfs to get a new hierarchical graph again

//cur:= current gap optimization
//to guarantee that do not check useless edge over one time
int lev[N], cur[N];
bool bfs(int s, int t) {
    queue<int> q;
    memset(lev, 0, sizeof lev);
    q.push(s);  lev[s] = 1;
    while(q.size() && !lev[t]) {
        int u = q.front(); q.pop();
        for(int i = head[u]; ~i; i = nxt[i]) {
            int v = pnt[i];
            if(cap[i] > 0 && !lev[v]) {
                lev[v] = lev[u] + 1;
                q.push(v);
            }
        }
    }
    return lev[t];
}

int dfs(int u, int t, int delta) {
    if(u == t || !delta) return delta;
    int ret = 0;
    for(int i = cur[u]; ~i; i = nxt[i]) {
        int v = pnt[i];
        if(cap[i] > 0 && lev[v] == lev[u] + 1) {
            int d = dfs(v, t, min(delta, cap[i]));
            cur[u] = i;            //current gap optimization
            ret += d; delta -= d;  //multiple path augmenting
            cap[i] -= d;
            cap[i ^ 1] += d;

            if(delta == 0) return ret;
        }
    }
    lev[u] = 0;
    return ret;
}

int dinic(int s, int t) {
    int ret = 0;
    while(bfs(s, t)) {
        for(int i = s; i <= t; ++i) cur[i] = head[i];
        ret += dfs(s, t, INF);
    }
    return ret;
}

int n, m, tmp[M];
typedef pair<int, int> P;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        cnt = 0; memset(head, -1, sizeof head);
        int s = 0, t = n + 1;
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            add_double(s, i, x);
        }

        vector<P> fix;
        for(int i = 1; i <= m; ++i) {
            int u, v, w, p; scanf("%d%d%d%d", &u, &v, &w, &p);
            if(p < 0) {
                add_double(u, v, INF);
                add_double(u, t, w);
            } else if(p == 0) add_double(u, v, INF);
            else {
                fix.push_back(P(cnt, w)); //save the edge
                add_double(u, v, 1); //fix
            }
        }

        int k = fix.size();
        int maxFlow = -INF, minCost = INF;
        for(int i = 0; i < cnt; ++i) tmp[i] = cap[i]; //save
        for(int S = 0; S < 1 << k; ++S) {
            int curCost = 0;
            for(int i = 0; i < k; ++i) {
                if(S >> i & 1) {
                    P &e = fix[i];
                    curCost += e.second;
                    cap[e.first] = INF;
                }
            }

            int curFlow = dinic(s, t);
            if(maxFlow < curFlow) {
                maxFlow = curFlow;
                minCost = curCost;
            } else if(maxFlow == curFlow && minCost > curCost) minCost = curCost;

            //recover graph
            for(int i = 0; i < cnt; ++i) cap[i] = tmp[i];
        }
        if(maxFlow == 0) puts("Poor Heaven Empire");
        else printf("%d %d\n", maxFlow, minCost);
    }
    return 0;
}
