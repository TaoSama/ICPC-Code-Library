//
//  Created by TaoSama on 2017-03-23
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, s;

const int V = N * 5;
vector<pair<int, int>> G[V];
inline void addEdge(int u, int v, int c) {
    G[u].push_back({v, c});
}

int id[2][N << 2], idx;
void build(int l, int r, int rt, int wh) {
    id[wh][rt] = ++idx;
    if(l == r) {
        if(wh == 0) addEdge(id[wh][rt], l, 0);
        else addEdge(l, id[wh][rt], 0);
        return;
    }
    int m = l + r >> 1;
    build(l, m, rt << 1, wh);
    build(m + 1, r, rt << 1 | 1, wh);
    if(wh == 0) {
        addEdge(id[wh][rt], id[wh][rt << 1], 0);
        addEdge(id[wh][rt], id[wh][rt << 1 | 1], 0);
    } else {
        addEdge(id[wh][rt << 1], id[wh][rt], 0);
        addEdge(id[wh][rt << 1 | 1], id[wh][rt], 0);
    }
}

vector<int> vs;
void get(int L, int R, int l, int r, int rt, int wh) {
    if(L <= l && r <= R) {
        vs.push_back(id[wh][rt]);
        return;
    }
    int m = l + r >> 1;
    if(L <= m) get(L, R, l, m, rt << 1, wh);
    if(R > m) get(L, R, m + 1, r, rt << 1 | 1, wh);
}

typedef long long LL;
const LL LLINF = 0x3f3f3f3f3f3f3f3fLL;
LL d[V]; bool done[V];
void dijkstra(int s) {
    for(int i = 1; i <= 5 * n; ++i) done[i] = false, d[i] = LLINF;
    priority_queue<pair<LL, int>> q; q.push({ -0, s});
    d[s] = 0;
    while(q.size()) {
        int u = q.top().second; q.pop();
        if(done[u]) continue;
        done[u] = true;
        for(auto& e : G[u]) {
            int v, c; tie(v, c) = e;
            if(d[v] > d[u] + c) {
                d[v] = d[u] + c;
                q.push({ -d[v], v});
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

    while(scanf("%d%d%d", &n, &m, &s) == 3) {
        for(int i = 1; i <= 5 * n; ++i) G[i].clear();

        idx = n;
        build(1, n, 1, 0);
        build(1, n, 1, 1);
        while(m--) {
            int t, u; scanf("%d%d", &t, &u);
            if(t == 1) {
                int v, c; scanf("%d%d", &v, &c);
                addEdge(u, v, c);
            } else if(t == 2) {
                vs.clear();
                int l, r, c; scanf("%d%d%d", &l, &r, &c);
                get(l, r, 1, n, 1, 0);
                for(int v : vs) addEdge(u, v, c);
            } else {
                vs.clear();
                int l, r, c; scanf("%d%d%d", &l, &r, &c);
                get(l, r, 1, n, 1, 1);
                for(int v : vs) addEdge(v, u, c);
            }
        }

        dijkstra(s);
        for(int i = 1; i <= n; ++i) {
            if(d[i] == LLINF) d[i] = -1;
            printf("%I64d%c", d[i], " \n"[i == n]);
        }
    }

    return 0;
}
