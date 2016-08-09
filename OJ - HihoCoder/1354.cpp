//
//  Created by TaoSama on 2016-08-07
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, k;
int ox[N], oy[N];
int b[N], a[N];

struct Edge {
    int v, c;
};
vector<Edge> G[N];

int ID(int x, int y) {
    return (x - 1) * m + y;
}

void add(int x, int y, int w) {
//  pr(x); pr(y); prln(w);
    G[x].push_back({y, w});
    G[y].push_back({x, w});
}

int d[N], in[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &m);
    for(int i = 1; i < n; ++i) scanf("%d", b + i);
    for(int i = 1; i < m; ++i) scanf("%d", a + i);

    set<pair<int, int> > s;
    scanf("%d", &k);
    for(int i = 1; i <= k; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        s.insert({x, y});
    }

    for(int i = 1; i <= n * m; ++i) G[i].clear();

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(s.count({i, j})) continue;
            if(i - 1 >= 1 && !s.count({i - 1, j})) {
//                printf("(%d, %d), (%d, %d) %d\n", i - 1, j, i, j, b[i - 1]);
                add(ID(i - 1, j), ID(i, j), b[i - 1]);
            }

            if(i + 1 <= n && !s.count({i + 1, j})) {
//                printf("(%d, %d), (%d, %d) %d\n", i + 1, j, i, j, b[i]);
                add(ID(i + 1, j), ID(i, j), b[i]);
            }

            if(j - 1 >= 1 && !s.count({i, j - 1})) {
//                  printf("(%d, %d), (%d, %d) %d\n", i , j - 1, i, j, a[i - 1]);
                add(ID(i, j), ID(i, j - 1), a[j - 1]);
            }

            if(j + 1 <= m && !s.count({i, j + 1})) {
//                printf("(%d, %d), (%d, %d) %d\n", i, j + 1, i, j, b[i - 1]);
                add(ID(i, j), ID(i, j + 1), a[j]);
            }
        }
    }

    int Q; scanf("%d", &Q);
    while(Q--) {
        int x, y, p, q; scanf("%d%d%d%d", &x, &y, &p, &q);
        int s = ID(x, y), g = ID(p, q);
//        pr(s); prln(g);
        {
            memset(d, 0x3f, sizeof d);
            memset(in, 0, sizeof in);
            queue<int> q;
            q.push(s);
            d[s] = 0; in[s] = 1;
            while(q.size()) {
                int u = q.front(); q.pop();
                in[u] = false;
                for(Edge& e : G[u]) {
                    int v = e.v, c = e.c;
                    if(d[v] > d[u] + c) {
                        d[v] = d[u] + c;
                        if(!in[v]) in[v] = true, q.push(v);
                    }
                }
            }
        }
        int ans = d[g];
        if(ans == INF) ans = -1;
        printf("%d\n", ans);
    }

    return 0;
}
