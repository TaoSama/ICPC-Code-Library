//
//  Created by TaoSama on 2017-04-11
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
const int N = 3e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, d;
bool cut[N], vis[N];
vector<pair<int, int>> G[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &m, &d) == 3) {
        vector<pair<int, int>> q; q.reserve(n);
        for(int i = 1; i <= m; ++i) {
            int x; scanf("%d", &x);
            q.push_back({x, 0});
        }

        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back({v, i});
            G[v].push_back({u, i});
        }

        memset(vis, 0, sizeof vis);
        memset(cut, 0, sizeof cut);
        for(int i = 0; i < q.size(); ++i) {
            int u, fa; tie(u, fa) = q[i];
            if(vis[u]) continue;
            vis[u] = true;
            for(const auto& e : G[u]) {
                int v, id; tie(v, id) = e;
                if(v == fa) continue;
                if(vis[v]) {
                    cut[id] = true;
                    continue;
                }
                q.push_back({v, u});
            }
        }

        vector<int> ans;
        for(int i = 1; i < n; ++i) if(cut[i]) ans.push_back(i);
        printf("%d\n", ans.size());
        for(int i = 0; i < ans.size(); ++i)
            printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
    }

    return 0;
}
