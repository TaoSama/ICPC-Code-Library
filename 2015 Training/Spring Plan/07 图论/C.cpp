//
//  Created by TaoSama on 2015-08-21
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;

struct Edge {
    int u, v, c;
    bool operator<(const Edge& rhs) const {
        return c < rhs.c;
    }
};
vector<Edge> G;

int p[1005];
int find(int x) {
    return p[x] = p[x] == x ? x : find(p[x]);
}

int kruskal() {
    int ret = 0;
    for(int i = 1; i <= n; ++i) p[i] = i;
    sort(G.begin(), G.end());
    for(int i = 0; i < G.size(); ++i) {
        Edge &e = G[i];
        int u = find(e.u), v = find(e.v);
        if(u == v) continue;
        p[u] = v;
        ret += e.c;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        G.clear();
        for(int i = 2; i <= n; ++i) {
            int x; scanf("%d", &x);
            G.push_back((Edge) {1, i, x});
        }
        for(int i = 2; i <= n; ++i) {
            for(int j = 2; j <= n; ++j) {
                int x; scanf("%d", &x);
                if(i == j) continue;
                G.push_back((Edge) {i, j, x});
            }
        }
        printf("%d\n", kruskal());
    }
    return 0;
}
