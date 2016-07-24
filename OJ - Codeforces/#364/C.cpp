//
//  Created by TaoSama on 2016-07-23
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

int n, m;
int s, t, cost[N];

struct Edge {
    int v, nxt;
} edge[N];
int head[N], cnt;

void addEdge(int u, int v) {
    edge[cnt] = {v, head[u]};
    head[u] = cnt++;
    edge[cnt] = {u, head[v]};
    head[v] = cnt++;
}

int low[N], dfn[N], dfsNum;
bool bridge[N];
void tarjan(int u, int f, int del) {
    low[u] = dfn[u] = ++dfsNum;
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        if(i == (f ^ 1) || (i >> 1) == del) continue;
        int v = edge[i].v;
        if(!dfn[v]) {
            tarjan(v, i, del);
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u]) bridge[i >> 1] = true;
        } else low[u] = min(low[u], dfn[v]);
    }
}

bool vis[N];
bool getPath(int u, int t, int del, vector<int>& path) {
    vis[u] = true;
    if(u == t) return true;
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        if((i >> 1) == del) continue;
        int v = edge[i].v;
        if(vis[v]) continue;
        if(getPath(v, t, del, path)) {
            path.push_back(i >> 1);
            return true;
        }
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%d", &n, &m) == 2) {
        scanf("%d%d", &s, &t);
        cnt = 0; memset(head, -1, sizeof head);
        for(int i = 0; i < m; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            cost[i] = c;
            addEdge(u, v);
        }

        vector<int> path;
        memset(vis, 0, sizeof vis);
        getPath(s, t, -1, path);
        if(path.empty()) {
            puts("0\n0");
            continue;
        }

//        puts("path1: ");
//        for(int e : path) printf("%d ", e + 1); puts("");

        pair<int, vector<int> > ans = {INF * 2, vector<int>()};
        for(int e1 : path) {
            //get bridges
            dfsNum = 0;
            memset(dfn, 0, sizeof dfn);
            memset(bridge, 0, sizeof bridge);
            tarjan(s, -1, e1);

            vector<int> newPath;
            memset(vis, 0, sizeof vis);
            //already disconnected
            if(!getPath(s, t, e1, newPath))
                ans = min(ans, {cost[e1], vector<int>{e1} });

//            printf("del %d: \n", e1 + 1);
//            for(int e : path) printf("%d ", e + 1); puts("");

            for(int e2 : newPath) {
                if(!bridge[e2]) continue;
//                prln(cost[e1] + cost[e2]);
                ans = min(ans, {cost[e1] + cost[e2], vector<int>{e1, e2} });
            }
        }

        int cost; vector<int> choose;
        tie(cost, choose) = ans;
        if(cost == INF * 2) puts("-1");
        else {
            printf("%d\n%d\n", cost, choose.size());
            for(int e : choose) printf("%d ", e + 1); puts("");
        }
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
