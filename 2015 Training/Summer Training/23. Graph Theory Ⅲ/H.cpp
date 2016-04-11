//
//  Created by TaoSama on 2015-08-19
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
const int N = 45, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 1e5 + 10;

int pnt[M], cap[M], nxt[M], head[N], cnt;

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

int n, m, row[25], col[25];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) scanf("%d", row + i);
        //each to subtract 1 to ensure that all numbers in range of 1~20
        //that's because zero flow can be valid flow
        for(int i = n; i; --i) row[i] -= row[i - 1] + m; //row[i] -= m
        for(int i = 1; i <= m; ++i) scanf("%d", col + i);
        for(int i = m; i; --i) col[i] -= col[i - 1] + n; //col[i] -= n

        cnt = 0; memset(head, -1, sizeof head);
        //s->rowSum colSum->t
        //must construct first for get matrix's convenience
        int s = 0, t = n + m + 1;
        for(int i = 1; i <= n; ++i) add_double(s, i, row[i]);
        for(int i = 1; i <= m; ++i) add_double(n + i, t, col[i]);
        //reversing order also makes convenience
        for(int i = 1; i <= n; ++i) for(int j = m; j; --j) add_double(i, n + j, 19);

        dinic(s, t);
        printf("Matrix %d\n", ++kase);
        for(int i = 1; i <= n; ++i) {
            for(int x = head[i], j = 1; j <= m; ++j, x = nxt[x])
                printf("%d%c", cap[x ^ 1] + 1, " \n"[j == m]);
        }
        puts("");
    }
    return 0;
}
