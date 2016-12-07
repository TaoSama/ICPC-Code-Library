//
//  Created by TaoSama on 2016-12-06
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

int n, m, V;
vector<int> G[N], cc[N];
int w[N], b[N];

bool vis[N];
void dfs(int u, int ccCnt) {
    vis[u] = true;
    cc[ccCnt].push_back(u);
    for(int v : G[u]) {
        if(vis[v]) continue;
        dfs(v, ccCnt);
    }
}

int f[N][N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &m, &V) == 3) {
        for(int i = 1; i <= n; ++i) scanf("%d", w + i);
        for(int i = 1; i <= n; ++i) scanf("%d", b + i);
        for(int i = 1; i <= n; ++i) G[i].clear(), cc[i].clear();
        for(int i = 1; i <= m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        int ccCnt = 0;
        memset(vis, 0, sizeof vis);
        for(int i = 1; i <= n; ++i) {
            if(vis[i]) continue;
            ++ccCnt;
            dfs(i, ccCnt);
        }

//      for(int i = 1; i <= ccCnt; ++i){
//          for(int v : cc[i]) printf("%d ", v); puts("");
//      }

        memset(f, 0, sizeof f);
        for(int i = 1; i <= ccCnt; ++i) {
            for(int j = 0; j <= V; ++j) {
                f[i][j] = max(f[i][j], f[i - 1][j]);
                int ws = 0, bs = 0;
                for(int k : cc[i]) {
                    ws += w[k];
                    bs += b[k];
                    if(j - w[k] < 0) continue;
                    int t = j - w[k];
                    f[i][j] = max(f[i][j], f[i - 1][t] + b[k]);
                }
                if(j >= ws) {
                    int t = j - ws;
                    f[i][j] = max(f[i][j], f[i - 1][t] + bs);
                }
            }
        }
        int ans = *max_element(f[ccCnt], f[ccCnt] + V + 1);
        printf("%d\n", ans);
    }

    return 0;
}
