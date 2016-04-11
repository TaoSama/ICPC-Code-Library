//
//  Created by TaoSama on 2015-05-23
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, s, nxt[N << 1], pnt[N << 1], head[N << 1], cnt;
long long tim[N], good[N];

void add_edge(int u, int v) {
    pnt[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt ++;
}

void dfs(int u, int f = - 1) {
    bool wait = false;
    long long maxv = 0;
    if(good[u] == 0) wait = true;
    for(int i = head[u]; ~i; i = nxt[i]) {
        int &v = pnt[i];
        if(v == f) continue;
        dfs(v, u);
        good[u] += good[v];
        maxv = max(good[v] + tim[v], maxv);
    }
    if(maxv > 0) {
        tim[u] = maxv;
        good[u] -= maxv;
        if(wait) good[u]++, maxv--;
        good[f] += maxv;
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        cnt = 0;
        memset(head, -1, sizeof head);
        memset(tim, 0, sizeof tim);
        scanf("%d%d", &n, &s);
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            add_edge(u, v);
            add_edge(v, u);
        }
        for(int i = 1; i <= n; ++i) scanf("%lld", good + i);
        dfs(s);
        printf("Case #%d: %lld\n", ++kase, tim[s]);
    }
    return 0;
}
