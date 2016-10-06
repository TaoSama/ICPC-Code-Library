//
//  Created by TaoSama on 2016-10-06
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q;
int sons[N], fa[N], dep[N];
vector<int> G[N];

int qs[N], imp[N];

void dfs(int u, int f) {
    sons[u] = 0;
    for(int v : G[u]) {
        if(v == f) continue;
        fa[v] = u;
        ++sons[u];
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1, 0);

        static int kase = 0;
        printf("Case #%d:\n", ++kase);
        while(q--) {
            int k; scanf("%d", &k);
            for(int i = 1; i <= k; ++i) {
                scanf("%d", qs + i);
                imp[qs[i]] = sons[qs[i]];
            }
            sort(qs + 1, qs + 1 + k, [](int x, int y) {
                return dep[x] > dep[y];
            });

            int ans = n;
            for(int i = 1; i <= k; ++i) {
                int x = qs[i];
                if(imp[x] < 2) --ans;
                if(imp[x] == 0) --imp[fa[x]];
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}
