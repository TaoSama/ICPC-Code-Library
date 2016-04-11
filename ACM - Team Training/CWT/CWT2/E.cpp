//
//  Created by TaoSama on 2016-01-21
//  Copyright (c) 2015 TaoSama. All rights reserved.
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

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, c[N];
vector<int> G[N];

typedef long long LL;
map<int, int> cnt[N];
map<int, LL> sum[N];
LL ans[N];

void dfs(int u, int f) {
    cnt[u][c[u]] = 1;
    sum[u][1] = c[u];
    for(int v : G[u]) {
        if(v == f) continue;
        dfs(v, u);
        if(cnt[v].size() > cnt[u].size()) {
            swap(cnt[u], cnt[v]);
            swap(sum[u], sum[v]);
        }
        for(auto x : cnt[v]) {
            int color = x.first, times = x.second;
            int original = cnt[u][color];
            if(original && !(sum[u][original] -= color))
                sum[u].erase(original);
            cnt[u][color] = (original += times);
            sum[u][original] += color;
        }
    }
    ans[u] = sum[u].rbegin()->second;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) {G[i].clear(); cnt[i].clear(); sum[i].clear();}
        for(int i = 1; i <= n; ++i) scanf("%d", c + i);
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1, -1);
        for(int i = 1; i <= n; ++i)
            printf("%I64d%c", ans[i], " \n"[i == n]);
    }
    return 0;
}
