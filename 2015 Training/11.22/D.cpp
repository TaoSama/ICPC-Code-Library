//
//  Created by TaoSama on 2015-11-22
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 2e3 + 10;

int n, m;
struct Edge {
    int v, nxt, c;
} edge[M];
int head[N], cnt;

void addEdge(int u, int v, int c) {
    edge[cnt] = (Edge) {v, head[u], c};
    head[u] = cnt++;
}

bool in[N], vis[N];
int dp[N], num[N], negative;

void dfs(int u) {
    vis[u] = true;
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(vis[v]) continue;
        dfs(v);
    }
}

void spfa(int s) {
    queue<int> q; q.push(s);
    memset(dp, 0x3f, sizeof dp);
    memset(in, false, sizeof in);
    memset(num, 0, sizeof num);
    in[s] = num[s] = 1; dp[s] = 0;
    while(q.size()) {
        int u = q.front(); q.pop();
        in[u] = false;
        for(int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].v;
            if(vis[v]) continue;
            if(dp[v] > dp[u] + edge[i].c) {
                dp[v] = dp[u] + edge[i].c;
                if(!in[v]) {
                    in[v] = true;
                    if(++num[v] >= n) {
                        negative = true;
                        dfs(v);
                    }
                    q.push(v);
                }
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\in.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        cnt = 0; memset(head, -1, sizeof head);
        scanf("%d%d", &n, &m);
        while(m--) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            addEdge(v, u, c);  //reversing graph, cycle to point
        }

        negative = false;
        memset(vis, false, sizeof vis);
        for(int i = 0; i < n; ++i) {
            if(vis[i]) continue;
            spfa(i);
        }

        if(!negative) {
            printf("Case %d: impossible\n", ++kase);
            continue;
        }
        printf("Case %d:", ++kase);
        for(int i = 0; i < n; ++i) if(vis[i]) printf(" %d", i);
        puts("");
    }
    return 0;
}
