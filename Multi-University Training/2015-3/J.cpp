//
//  Created by TaoSama on 2016-03-22
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
const int N = 5e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, w[N];
vector<int> G[N];

int f[N];
void dfs(int u) {
    if(f[u]) return;
    f[u] = 1;
    for(int v : G[u]) {
        dfs(v);
        f[u] += f[v];
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", w + i);
            G[i].clear();
        }
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            if(w[u] > w[v]) swap(u, v);
            G[u].push_back(v);
        }

        int ans = 0;
        memset(f, 0, sizeof f);
        for(int i = 1; i <= n; ++i) {
            dfs(i);
            ans = max(ans, f[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
