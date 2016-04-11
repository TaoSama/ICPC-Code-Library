//
//  Created by TaoSama on 2015-08-18
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
const int N = 1e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 1e5 + 10;

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

int n, m, k;
int need[N][N], have[N][N];
int needK[N], haveK[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &m, &k) == 3 && (n || m || k)) {
        memset(needK, 0, sizeof needK);
        memset(haveK, 0, sizeof haveK);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= k; ++j) {
                scanf("%d", &need[i][j]);  //i-th man j-th goods
                needK[j] += need[i][j]; //total j-th goods
            }
        }
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= k; ++j) {
                scanf("%d", &have[i][j]);
                haveK[j] += have[i][j];
            }
        }

        bool ok = true;
        for(int i = 1; i <= k; ++i) {
            if(needK[i] > haveK[i]) { //judge all goods is enough
                ok = false;
                break;
            }
        }

        int ans = 0;
        int s = 0, t = n + m + 1;
        for(int z = 1; z <= k; ++z) {
            cnt = 0; memset(head, -1, sizeof head);
            for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= m; ++j) {
                    int x; scanf("%d", &x); //send from j-place to i-people
                    add_double(j, m + i, x, INF);
                }
            }
            if(!ok) continue;
            for(int i = 1; i <= m; ++i)
                add_double(s, i, 0, have[i][z]);
            for(int i = 1; i <= n; ++i)
                add_double(m + i, t, 0, need[i][z]);
            ans += minCostMaxFlow(s, t);
        }
        if(ok) printf("%d\n", ans);
        else puts("-1");
    }
    return 0;
}
