//
//  Created by TaoSama on 2016-05-28
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, A, B;
struct Point {
    int x, y;
    void read() {
        scanf("%d%d", &x, &y);
    }
    int length(const Point& p) {
        return abs(x - p.x) + abs(y - p.y);
    }
} R[2], ps[N], hate[N], like[N];
int p2R[2][N], r2R[2][2];

struct TwoSat {
    static const int V = 1e3 + 10, E = 1e6 + 10;
    struct Edge {
        int v, nxt;
    } edge[E];
    int n, head[V], cnt, stk[V], top;
    int dfn[V], low[V], in[V], id[V], scc, dfsNum;

    void init(int _n) {
        n = _n;
        cnt = scc = dfsNum = 0;
        memset(dfn, 0, sizeof dfn);
        memset(head, -1, sizeof head);
    }
    void addEdge(int u, int v) {
        edge[cnt] = (Edge) {v, head[u]};
        head[u] = cnt++;
    }
    void tarjan(int u) {
        dfn[u] = low[u] = ++dfsNum;
        stk[++top] = u;
        in[u] = true;
        for(int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].v;
            if(!dfn[v]) {
                tarjan(v);
                low[u] = min(low[u], low[v]);
            } else if(in[v]) low[u] = min(low[u], dfn[v]);
        }
        if(low[u] == dfn[u]) {
            ++scc;
            while(true) {
                int v = stk[top--];
                in[v] = false;
                id[v] = scc;
                if(v == u) break;
            }
        }
    }
    bool twoSat() {
        for(int i = 0; i < n * 2; ++i) if(!dfn[i]) tarjan(i);
        for(int i = 0; i < n * 2; i += 2)
            if(id[i] == id[i ^ 1]) return false;
        return true;
    }
} solver;

bool solve(int x) {
    solver.init(n);
    for(int i = 0; i < A; ++i) {
        int u = hate[i].x, v = hate[i].y;
        u <<= 1; v <<= 1;
        solver.addEdge(u, v ^ 1);
        solver.addEdge(v ^ 1, u);
        solver.addEdge(u ^ 1, v);
        solver.addEdge(v, u ^ 1);
    }
    for(int i = 0; i < B; ++i) {
        int u = like[i].x, v = like[i].y;
        u <<= 1; v <<= 1;
        solver.addEdge(u, v);
        solver.addEdge(v, u);
        solver.addEdge(u ^ 1, v ^ 1);
        solver.addEdge(v ^ 1, u ^ 1);
    }
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            for(int a = 0; a < 2; ++a) {
                for(int b = 0; b < 2; ++b) {
                    int dis = p2R[a][i] + p2R[b][j] + r2R[a][b];
//                    printf("%d->%d:%d %d->%d:%d = %d\n",
//                           i, a, p2R[a][i], j, b, p2R[b][j], dis);
                    if(dis <= x) continue; //不矛盾
                    int u = i << 1 | a, v = j << 1 | b;
                    solver.addEdge(u, v ^ 1);
                    solver.addEdge(v, u ^ 1);
                }
            }
        }
    }
    return solver.twoSat();
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%d%d", &n, &A, &B) == 3) {
        for(int i = 0; i < 2; ++i) {
            R[i].read();
            for(int j = 0; j < i; ++j)
                r2R[i][j] = r2R[j][i] = R[i].length(R[j]);
        }
        for(int i = 0; i < n; ++i) {
            ps[i].read();
            for(int j = 0; j < 2; ++j)
                p2R[j][i] = ps[i].length(R[j]);
        }
        for(int i = 0; i < A; ++i) {
            hate[i].read();
            --hate[i].x; --hate[i].y;
        }
        for(int i = 0; i < B; ++i) {
            like[i].read();
            --like[i].x; --like[i].y;
        }

        int l = 0, r = 1e7, res = -1;
        while(l <= r) {
            int m = l + r >> 1;
            if(solve(m)) res = m, r = m - 1;
            else l = m + 1;
        }
        printf("%d\n", res);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
