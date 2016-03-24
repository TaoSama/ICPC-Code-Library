//
//  Created by TaoSama on 2016-02-06
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#include <cassert>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 100 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

int n, k, vis[N];
vector<int> G[N];
LL f[N][2]; //1 for color1, 0 for others

void dfs(int u, int fa, int dep, int& cycle, int& sz) {
    if(vis[u]) {
        if(!cycle) cycle = dep - vis[u];
        return;
    }
    ++sz;
    vis[u] = dep;
    for(int v : G[u]) {
        if(v == fa) continue;
        dfs(v, u, dep + 1, cycle, sz);
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
        scanf("%d%d", &n, &k);
        for(int i = 0; i < n; ++i) G[i].clear();
        for(int i = 0; i < n; ++i) {
            int x; scanf("%d", &x);
            G[i].push_back(x);
            G[x].push_back(i);
        }

        f[1][0] = 0, f[1][1] = k;
        for(int i = 2; i <= n; ++i) {
            f[i][0] = (f[i - 1][0] * (k - 2) + f[i - 1][1] * (k - 1)) % MOD;
            f[i][1] = f[i - 1][0];
        }

        LL ans = 1;
        memset(vis, 0, sizeof vis);
        for(int i = 0; i < n; ++i) {
            if(vis[i]) continue;
            int cycle, sz; cycle = sz = 0;
            dfs(i, -1, 1, cycle, sz);
            if(!cycle) cycle = 2;
            ans = ans * f[cycle][0] % MOD;
            sz -= cycle;
            while(sz--) ans = ans * (k - 1) % MOD;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
