//
//  Created by TaoSama on 2015-11-07
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
            cur[u] = i;
            ret += d; delta -= d;
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

int n, m, p;
char a[105][105];

int get(int x, int y) {
    return m * (x - 1) + y;
}

int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};

bool isIllegal(int x, int y) {
    return x < 1 || x > n || y < 1 || y > m;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &m, &p) == 3) {
        for(int i = 1; i <= n; ++i) scanf("%s", a[i] + 1);
        cnt = 0; memset(head, -1, sizeof head);
        int s = 0, t = 2 * n * m + 1, OFF = n * m;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(a[i][j] == '~') continue;
                if(a[i][j] == '*') add_double(s, get(i, j), 1);
                if(a[i][j] == '#') add_double(get(i, j), t, p);
                if(a[i][j] == '.') add_double(get(i, j), get(i, j) + OFF, 1);
                for(int k = 0; k < 4; ++k) {
                    int nx = i + d[k][0], ny = j + d[k][1];
                    if(isIllegal(nx, ny) || a[nx][ny] == '*' || a[nx][ny] == '~') continue;
                    if(a[i][j] == '.') add_double(get(i, j) + OFF, get(nx, ny), 1);
                    else add_double(get(i, j), get(nx, ny), INF);
                }
            }
        }
        printf("%d\n", dinic(s, t));
    }
    return 0;
}
