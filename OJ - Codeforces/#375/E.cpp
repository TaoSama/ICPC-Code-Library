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
#include <cassert>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 1e5 + 10;

int head[N], pnt[M], cap[M], nxt[M], cnt;
void add_edge(int u, int v, int w) {
    pnt[cnt] = v;
    cap[cnt] = w;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

void add_edge(int u, int v) {
    pnt[cnt] = v;
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

int n, m;
int in[N], out[N];

int stk[M], top;
set<int> vis;
void euler(int u) {
    for(int i = head[u]; ~i; i = nxt[i]) {
        int v = pnt[i];
        if(vis.count(i)) continue;
        vis.insert(i);
        euler(v);
    }
    stk[++top] = u;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int T; scanf("%d", &T);
    int kase = 0;
    while(T--) {
        scanf("%d%d", &n, &m);
        cnt = 0; memset(head, -1, sizeof head);
        memset(in, 0, sizeof in);
        memset(out, 0, sizeof out);

        vector<int> du, dv;
        for(int i = 1; i <= m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            //suspect u->v  we can change later, only they can be changed..
            add_double(u, v, 1);
            ++in[v]; ++out[u];
        }
        vector<int> odd;
        for(int i = 1; i <= n; ++i)
            if((in[i] + out[i]) & 1) odd.push_back(i);
        //odd degree appears even times...
        for(int i = 0; i < odd.size(); i += 2) {
            add_double(odd[i], odd[i + 1], 1);
            ++out[odd[i]];
            ++in[odd[i + 1]];
        }

        bool ok = true, can = false;
        int s = 0, t = n + 1, sum = 0;
        for(int i = 1; i <= n; ++i) {
            //parity doesn't match, Euler circuit doesn't exist
            if((in[i] + out[i]) & 1) { //never here..
                continue;
            }
            //transport "out degree"
            int dif = abs(out[i] - in[i] >> 1);
            if(out[i] > in[i]) {
                add_double(s, i, dif);
                sum += dif;
            }
            //accept "out degree"
            else add_double(i, t, dif);
        }

        int ret = dinic(s, t);
        assert(sum == ret);

        printf("%d\n", n - odd.size());
        //construct the Euler circuit
        for(int i = 0; i < 2 * m; i += 2) {
            if(cap[i]) printf("%d %d\n", pnt[i ^ 1], pnt[i]);
            else printf("%d %d\n", pnt[i], pnt[i ^ 1]);
        }
    }
    return 0;
}
