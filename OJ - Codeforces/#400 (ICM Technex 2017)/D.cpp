//
//  Created by TaoSama on 2017-02-23
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

struct TwoSat {
    static const int V = 2e5 + 10, E = 1e6 + 10;
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
        edge[cnt] = (Edge) {u, head[v]};
        head[v] = cnt++;
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

int n, m;
int col[N], g[N][2];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m) {
        memset(g, 0, sizeof g);
        for(int i = 1; i <= n; ++i) cin >> col[i];
        for(int i = 1; i <= m; ++i) {
            int cnt; cin >> cnt;
            while(cnt--) {
                int x; cin >> x;
                if(g[x][0]) g[x][1] = i;
                else g[x][0] = i;
            }
        }

        solver.init(m);
        for(int i = 1; i <= n; ++i) {
            int a = g[i][0] - 1, b = g[i][1] - 1;
            a <<= 1, b <<= 1;
            if(col[i]) {
                solver.addEdge(a, b);
                solver.addEdge(a ^ 1, b ^ 1);
            } else {
                solver.addEdge(a, b ^ 1);
                solver.addEdge(a ^ 1, b);
            }
        }
        cout << (solver.twoSat() ? "YES" : "NO") << endl;
    }

    return 0;
}
