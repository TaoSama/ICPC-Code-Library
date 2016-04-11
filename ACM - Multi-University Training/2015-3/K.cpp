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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k;
vector<int> G[N];

int f[N];
void dfs(int u) {
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

    while(scanf("%d%d", &n, &k) == 2) {
        for(int i = 1; i <= n; ++i) G[i].clear();
        vector<int> in(n + 1, 0);
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            ++in[v];
        }
        for(int i = 1; i <= n; ++i) if(!in[i]) dfs(1);
        int ans = 0;
        for(int i = 1; i <= n; ++i) ans += f[i] == k + 1;
        printf("%d\n", ans);
    }
    return 0;
}
