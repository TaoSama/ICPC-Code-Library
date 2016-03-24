//
//  Created by TaoSama on 2015-07-24
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

int n, m, dpr[N];

int nxt[N << 2], pnt[N << 2], col[N << 2], head[N << 2], cnt;
bool vis[N];

void add_edge(int u, int v, int c) {
    pnt[cnt] = v;
    col[cnt] = c;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

int rbfs() {
    queue<int> q;
    memset(dpr, 0x3f, sizeof dpr);
    q.push(n);  dpr[n] = 0;
    while(q.size()) {
        int u = q.front(); q.pop();
        for(int i = head[u]; ~i; i = nxt[i]) {
            int v = pnt[i];
            if(dpr[v] == INF) {
                dpr[v] = dpr[u] + 1;
                q.push(v);
            }
        }
    }
    return dpr[1];
}

vector<int> path;

void bfs() {
    path.clear();
    memset(vis, false, sizeof vis);
    vector<int> cur, next;
    cur.push_back(1);
    for(int i = 1; i <= dpr[1]; ++i) {
        int minc = INF;
        for(int j = 0; j < cur.size(); ++j) {
            int u = cur[j];
            for(int k = head[u]; ~k; k = nxt[k]) {
                int v = pnt[k], c = col[k];
                if(!vis[v] && dpr[v] == dpr[u] - 1)
                    minc = min(minc, c);
            }
        }
        path.push_back(minc);
        next.clear();
        for(int j = 0; j < cur.size(); ++j) {
            int u = cur[j];
            for(int k = head[u]; ~k; k = nxt[k]) {
                int v = pnt[k], c = col[k];
                if(!vis[v] && dpr[v] == dpr[u] - 1 && c == minc) {
                    vis[v] = true;
                    next.push_back(v);
                }
            }
        }
        cur = next;
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n , &m) == 2) {
        cnt = 0;
        memset(head, -1, sizeof head);
        for(int i = 1; i <= m; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            add_edge(u, v, c);
            add_edge(v, u, c);
        }

        int ans = rbfs();
        bfs();
        cout << ans << '\n';
        for(int i = 0; i < path.size(); ++i) {
            cout << path[i] << (i != path.size() - 1 ? ' ' : '\n');
        }
    }
    return 0;
}
