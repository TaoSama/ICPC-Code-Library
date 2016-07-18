//
//  Created by TaoSama on 2016-07-03
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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
const int M = N;

//必须添加超源超汇 0->s n+1->t
//特判起终点相同的情况 -> WA
struct Edge {
    int v, nxt, cap, flow;
} edge[M];
int head[N], cnt;

void addEdge(int u, int v, int c1) {
    edge[cnt] = {v, head[u], c1, 0};
    head[u] = cnt++;
    edge[cnt] = {u, head[v], 0, 0};
    head[v] = cnt++;
}

int lev[N], cur[N];
bool bfs(int s, int t) {
    queue<int> q;
    memset(lev, 0, sizeof lev);
    q.push(s);  lev[s] = 1;
    while(q.size() && !lev[t]) {
        int u = q.front(); q.pop();
        for(int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].v;
            if(edge[i].cap > edge[i].flow && !lev[v]) {
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
    for(int i = cur[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(edge[i].cap > edge[i].flow && lev[v] == lev[u] + 1) {
            int d = dfs(v, t, min(delta, edge[i].cap - edge[i].flow));
            cur[u] = i;
            ret += d; delta -= d;
            edge[i].flow += d;
            edge[i ^ 1].flow -= d;

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


int n, m, vis[N];
int a, b, mid;

void dfs(int u, int t, vector<int>& path) {
    if(u >= 1 && u <= n) path.push_back(u);
    if(u == t) return;
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(edge[i].cap && edge[i].flow) {
            --edge[i].flow;
            dfs(v, t, path);
            break;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//    freopen("C:\\Users\\TaoSama\\Desktop\\out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        scanf("%d%d%d", &a, &b, &mid);

        cnt = 0; memset(head, -1, sizeof head);

        int s = 0, t = 2 * n + 1;
        addEdge(s, mid, 1);
        addEdge(s, mid + n, 1);
        addEdge(a + n, t, 1);
        addEdge(b + n, t, 1);
        for(int i = 1; i <= n; ++i) addEdge(i, i + n, 1);

        for(int i = 1; i <= m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            addEdge(u + n, v, 1); //u' -> v
            addEdge(v + n, u, 1); //v' -> u
        }

        int flow = dinic(s, t);
//        prln(flow);
//
//        for(int i = 0; i <= 2 * n + 1; ++i)
//            for(int j = head[i]; ~j; j = edge[j].nxt)
//                if(edge[j].cap && edge[j].flow)
//                    printf("%d %d %d\n", i, edge[j].v, edge[j].cap);

        vector<int> path[2];
        dfs(mid, t, path[0]);
        dfs(mid + n, t, path[1]);

//        prln(path[0].size());
//        prln(path[1].size());

        if(find(path[0].begin(), path[0].end(), a) != path[0].end()) {
            reverse(path[0].begin(), path[0].end());
        } else {
            reverse(path[1].begin(), path[1].end());
            swap(path[0], path[1]);
        }

        bool first = true;
        for(int i = 0; i < 2; ++i) {
            for(int u : path[i]) {
                if(u < 1 || u > n) continue;
                if(first) first = false;
                else putchar(' ');
                printf("%d", u);
            }
        }
        puts("");
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
