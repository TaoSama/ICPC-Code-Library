//
//  Created by TaoSama on 2016-09-05
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

int n, c[N];
int all, sum[N];
map<int, int> cnt[N];
int ans[N], full[N];

vector<pair<int, int> > G[N];

void dfs(int u, int fa, int id) {
    cnt[u].clear();
    full[u] = 0;
    if(++cnt[u][c[u]] == sum[c[u]]) ++full[u];

    for(auto& p : G[u]) {
        int v, id2; tie(v, id2) = p;
        if(v == fa) continue;
        dfs(v, u, id2);

        if(cnt[u].size() < cnt[v].size()) {
            swap(cnt[u], cnt[v]);
            swap(full[u], full[v]);
        }
        for(auto& p2 : cnt[v]) {
            int c, num; tie(c, num) = p2;
            if((cnt[u][c] += num) == sum[c]) ++full[u];
        }
        cnt[v].clear();
    }

    ans[id] = all - cnt[u].size() + full[u];
    ans[id] = all - ans[id];
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", c + i);

        all = 0;
        memset(sum, 0, sizeof sum);
        for(int i = 1; i <= n; ++i) {
            if(!sum[c[i]]) ++all;
            ++sum[c[i]];
        }

        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back({v, i});
            G[v].push_back({u, i});
        }

        dfs(1, 0, 0);
        for(int i = 1; i < n; ++i) printf("%d\n", ans[i]);
    }

    return 0;
}
