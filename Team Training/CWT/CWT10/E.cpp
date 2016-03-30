//
//  Created by TaoSama on 2016-02-13
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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

int n, m;
struct Edge {
    int v, nxt, mark;
} edge[N << 1];
int head[N], cnt;

void addEdge(int u, int v, int mark) {
    edge[cnt] = (Edge) {v, head[u], mark};
    head[u] = cnt++;
}

int f[N], g[N], pre[N];

void bfs() {
    queue<int> q; q.push(1);
    memset(f, 0x3f, sizeof f);
    memset(g, 0, sizeof g);
    f[1] = g[1] = 0;
    while(q.size()) {
        int u = q.front(); q.pop();
        for(int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].v, mark = edge[i].mark;
            if(f[v] == INF) {
                f[v] = f[u] + 1;
                g[v] = g[u] + mark;
                pre[v] = i;
                q.push(v);
            } else if(f[v] == f[u] + 1) {
                if(g[u] + mark > g[v]) {
                    g[v] = g[u] + mark;
                    pre[v] = i;
                }
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        cnt = 0; memset(head, -1, sizeof head);
        int all = 0;
        for(int i = 1; i <= m; ++i) {
            int u, v, mark; scanf("%d%d%d", &u, &v, &mark);
            all += mark;
            addEdge(u, v, mark);
            addEdge(v, u, mark);
        }
        bfs();
        for(int u = n, id; u != 1; u = edge[id ^ 1].v) {
            id = pre[u];
            if(edge[id].mark == 0)
                edge[id].mark = edge[id ^ 1].mark = 2; //to repair
            else
                edge[id].mark = edge[id ^ 1].mark = 0; //ignore
        }
        printf("%d\n", f[n] + all - 2 * g[n]);
        for(int i = 0; i < cnt; i += 2) {
            if(!edge[i].mark) continue;
            printf("%d %d %d\n", edge[i ^ 1].v, edge[i].v, edge[i].mark - 1);
        }
    }
    return 0;
}
