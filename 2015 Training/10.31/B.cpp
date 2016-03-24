//
//  Created by TaoSama on 2015-10-31
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

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 2e4 + 10;

int n, m;

struct Edge {
    int u, v, c;
} e[M];

int realRoot, pre[N], in[N], id[N], vis[N];

int directedMST(int root, int n, int m) {
    int ret = 0;
    while(true) {
        memset(in, 0x3f, sizeof in);
        //find minimum "in" edge
        for(int i = 0; i < m; ++i) {
            int u = e[i].u, v = e[i].v;
            if(u != v && e[i].c < in[v]) {
                if(u == root) realRoot = i;
                pre[v] = u;
                in[v] = e[i].c;
            }
        }
        for(int i = 0; i < n; ++i) {
            if(i == root) continue;
            if(in[i] == INF) return -1; //isolate vertex
        }

        int cnt = 0;
        memset(id, -1, sizeof id);
        memset(vis, -1, sizeof vis);
        in[root] = 0;
        for(int i = 0; i < n; ++i) {
            ret += in[i];
            int u = i;  //judge circle
            while(id[u] == -1 && vis[u] != i && u != root) {
                vis[u] = i;
                u = pre[u];
            }
            //relabel
            if(id[u] == -1 && u != root) {
                for(int v = pre[u]; v != u; v = pre[v])
                    id[v] = cnt;
                id[u] = cnt++;
            }
        }
        if(cnt == 0) break; //no circle, already MST
        for(int i = 0; i < n; ++i) //other vertex
            if(id[i] == -1) id[i] = cnt++;

        //reconstruct graph
        for(int i = 0; i < m; ++i) {
            int u = e[i].u, v = e[i].v;
            e[i].u = id[u];
            e[i].v = id[v];
            if(u != v) e[i].c -= in[v];
        }
        n = cnt;
        root = id[root];
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        int sum = 0;
        for(int i = 0; i < m; ++i) {
            scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].c);
            sum += e[i].c;
        }
        ++sum;
        for(int i = 0; i < n; ++i)
            e[m + i] = (Edge) {n, i, sum};
        int ans = directedMST(n, n + 1, n + m);
        if(ans == -1 || ans - sum >= sum) puts("impossible");
        else printf("%d %d\n", ans - sum, realRoot - m);
        puts("");
    }
    return 0;
}
