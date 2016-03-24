//
//  Created by TaoSama on 2015-08-31
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 1e6 + 10;

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

int lev[N], cur[N];
bool bfs(int s, int t) {
    queue<int> q;
    memset(lev, 0, sizeof lev);
    q.push(s); lev[s] = 1;
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
            int d = dfs(v, t, min(cap[i], delta));
            cur[u] = i;
            ret += d; delta -= d;
            cap[i] -= d; cap[i ^ 1] += d;
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

int n, f, d;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &f, &d) == 3) {
        cnt = 0; memset(head, -1, sizeof head);
        int s = 0, t = f + 2 * n + d + 1;
        //i food f+i people
        //f+n+i people f+2n+i drink
        for(int i = 1; i <= f; ++i) {
            int x; scanf("%d", &x);
            add_double(s, i, x); //s->food
        }
        for(int i = 1; i <= d; ++i) {
            int x; scanf("%d", &x);
            add_double(f + 2 * n + i, t, x); //drink->t
        }
        for(int i = 1; i <= n; ++i) {
            char buf[205]; scanf("%s", buf + 1);
            for(int j = 1; j <= f; ++j)
                if(buf[j] == 'Y') add_double(j, f + i, 1); //food->p
        }
        for(int i = 1; i <= n; ++i) {
            add_double(f + i, f + n + i, 1); //p->p
            char buf[205]; scanf("%s", buf + 1);
            for(int j = 1; j <= d; ++j)
                if(buf[j] == 'Y') add_double(f + n + i, f + 2 * n + j, 1);
        }
        printf("%d\n", dinic(s, t));
    }
    return 0;
}
