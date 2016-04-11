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
#include <ctime>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 3e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 1e6 + 10;

int n, m;
char a[15][15];
int d[15][15][15][15];

int head[N], pnt[M], nxt[M], cnt;
void add_edge(int u, int v) {
    pnt[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

bool vis[N];
int match[N];
bool dfs(int u) {
    for(int i = head[u]; ~i; i = nxt[i]) {
        int v = pnt[i];
        if(vis[v]) continue;
        vis[v] = true;
        if(match[v] == -1 || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int dr[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};
void bfs(int x, int y, int d[15][15]) {
    queue<int> qx, qy;
    d[x][y] = 0;
    qx.push(x); qy.push(y);
    while(qx.size()) {
        x = qx.front(); qx.pop();
        y = qy.front(); qy.pop();
        for(int i = 0; i < 4; ++i) {
            int nx = x + dr[i][0], ny = y + dr[i][1];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(a[nx][ny] == '.' && d[nx][ny] == INF) {
                d[nx][ny] = d[x][y] + 1;
                qx.push(nx);
                qy.push(ny);
            }
        }
    }
}

void solve() {
    vector<int> dx, dy, px, py;  //door, people
    memset(d, 0x3f, sizeof d);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(a[i][j] == 'D') {
                dx.push_back(i);
                dy.push_back(j);
                //get the distance of the each door to every '.'
                bfs(i, j, d[i][j]);
            } else if(a[i][j] == '.') {
                px.push_back(i);
                py.push_back(j);
            }
        }
    }

    cnt = 0; memset(head, -1, sizeof head);
    int tot = n * m, door = dx.size(), peo = px.size();
    for(int i = 0; i < door; ++i) {
        for(int j = 0; j < peo; ++j) {
            int &cur = d[dx[i]][dy[i]][px[j]][py[j]]; //door->peo minimum distance
            if(cur == INF) continue;
            for(int k = cur; k <= tot; ++k)
                add_edge((k - 1) * door + i + 1, tot * door + j + 1);
        }
    }

    if(peo == 0) {puts("0"); return;}

    int num = 0;
    memset(match, -1, sizeof match);
    //each door's maximum time add together
    for(int i = 1; i <= tot * door; ++i) {
        memset(vis, false, sizeof vis);
        if(dfs(i) && ++num == peo) {
            printf("%d\n", (i - 1) / door + 1);
            return;
        }
    }
    puts("impossible");
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) scanf("%s", a[i] + 1);
        solve();
    }
    return 0;
}
