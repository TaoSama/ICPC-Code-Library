//
//  Created by TaoSama on 2017-01-12
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
vector<int> pos[N], G[N];
pair<int, int> val[N];
const int SEED[2] = {999999937, 999999929};

int f[N], vis[N];

int dfs(int u, int k) {
    vis[u] = k;
    for(int v : G[u])
        if(!vis[v]) dfs(v, k);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    f[0] = 1;
    for(int i = 1; i < N; ++i) f[i] = 1LL * f[i - 1] * i % MOD;

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= m; ++i) pos[i].clear();
        for(int i = 1; i <= n; ++i) {
            int cnt; scanf("%d", &cnt);
            while(cnt--) {
                int x; scanf("%d", &x);
                pos[x].push_back(i);
            }
        }
        for(int i = 1; i <= m; ++i) {
            int a = 0, b = 0;
            for(int v : pos[i]) {
                a = (1LL * a * SEED[0] + v) % MOD;
                b = (1LL * b * SEED[1] + v) % (MOD + 2);
            }
            val[i] = {a, b};
        }
        vector<int> id(m + 1);
        for(int i = 1; i <= m; ++i) id[i] = i;
        sort(id.begin() + 1, id.end(), [](int x, int y) {
            return val[x] < val[y];
        });

        for(int i = 1; i <= m; ++i) G[i].clear();
        int blank = 0;
        for(int i = 1; i <= m; ++i) blank += !pos[i].size();
        for(int i = 1; i + 1 <= m; ++i) {
            int u = id[i], v = id[i + 1];
            if(!pos[u].size() || !pos[v].size()) continue;
            if(val[u] == val[v]) {
                G[u].push_back(v);
                G[v].push_back(u);
            }
        }

        int cc = 0;
        memset(vis, 0, sizeof vis);
        for(int i = 1; i <= m; ++i) {
            if(vis[i]) continue;
            dfs(i, ++cc);
        }

        vector<int> sz(m + 1, 0);
        for(int i = 1; i <= m; ++i) ++sz[vis[i]];

        int ans = f[blank];
        for(int i = 1; i <= cc; ++i) ans = 1LL * ans * f[sz[i]] % MOD;

        printf("%d\n", ans);
    }

    return 0;
}
