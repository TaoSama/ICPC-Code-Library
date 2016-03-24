//
//  Created by TaoSama on 2015-05-07
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

int n, m, c;

int head[N * 10], pnt[N * 10], nxt[N * 10], cost[N * 10], cnt;

void add_edge(int u, int v, int c) {
    pnt[cnt] = v;
    cost[cnt] = c;
    nxt[cnt] = head[u];
    head[u] = cnt ++;
}

int d[2 * N], lay[N];
bool in[2 * N], have[N];

int spfa() {
    queue<int> q; q.push(1);
    memset(d, 0x3f, sizeof d);
    memset(in, false, sizeof in);
    d[1] = 0; in[1] = true;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        in[u] = false;
        for(int i = head[u]; ~i ; i = nxt[i]) {
            int v = pnt[i];
            if(d[v] > d[u] + cost[i]) {
                d[v] = d[u] + cost[i];
                if(!in[v]) q.push(v), in[v] = true;
            }
        }
    }
    return d[n];
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
        memset(have, false, sizeof have);
        scanf("%d%d%d", &n, &m, &c);

        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            lay[i] = x;
            have[x] = true;
        }

        for(int i = 1; i < n; ++i) {  //层层 c双向边(也可以不连)
            if(have[i] && have[i + 1]) {
                add_edge(n + i, n + i + 1, c);
                add_edge(n + i + 1, n + i, c);
            }
        }

        for(int i = 1; i <= n; ++i) {
            add_edge(n + lay[i], i, 0);   //层和点之间0
            if(lay[i] > 1) add_edge(i, n + lay[i] - 1, c); //点和相邻层c
            if(lay[i] < n) add_edge(i, n + lay[i] + 1, c);
        }

        for(int i = 1; i <= m; ++i) {
            int x, y, w; scanf("%d%d%d", &x, &y, &w);
            add_edge(x, y, w);
            add_edge(y, x, w);
        }

        /*for(int i = 1; i <= 2 * n; ++i) {
            cout << i << ": ";
            for(int j = head[i]; ~j; j = nxt[j])
                cout << pnt[j] << ' ';
            cout << endl;
        }*/

        int ans = spfa();
        if(ans == INF) ans = -1;
        printf("Case #%d: %d\n", ++kase, ans);
    }
    return 0;
}
