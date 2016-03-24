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

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 3e4 + 10;

int n, m;
struct Edge {
    int u, v, c;
    bool operator< (const Edge& e) const {
        return c < e.c;
    }
} edge[M];

int par[N];
int find(int x) {
    return par[x] = par[x] == x ? x : find(par[x]);
}

void kruskal(vector<int>& ans) {
    sort(edge + 1, edge + 1 + m);
    for(int i = 0; i < n; ++i) par[i] = i;
    for(int i = 1; i <= m; ++i) {
        int u = edge[i].u, v = edge[i].v;
        u = find(u), v = find(v);
        if(u == v) {
            ans.push_back(edge[i].c);
            continue;
        }
        par[v] = u;
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2 && (n || m)) {
        for(int i = 1; i <= m; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            edge[i] = (Edge) {u, v, c};
        }
        vector<int> ans;
        kruskal(ans);
        if(ans.size()) {
            for(int i = 0; i < ans.size(); ++i)
                printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
        } else puts("forest");
    }
    return 0;
}
