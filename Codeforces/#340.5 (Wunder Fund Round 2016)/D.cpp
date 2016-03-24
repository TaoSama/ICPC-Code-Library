//
//  Created by TaoSama on 2016-01-30
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, x, y;
vector<int> G[N];

bool available[N];

void dfs(int u, int f, int &tree) {
    int cnt = 0;
    for(int v : G[u]) {
        if(v == f) continue;
        dfs(v, u, tree);
        cnt += available[v];
    }
    available[u] = cnt < 2;
    tree += min(cnt, 2);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &x, &y) == 3) {
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        if(x < y) {
            int tree = 0;
            memset(available, false, sizeof available);
            dfs(1, -1, tree);
            long long ans = 1LL * tree * x + 1LL * (n - 1 - tree) * y;
            printf("%I64d\n", ans);
        } else {
            bool star = false;
            for(int i = 1; i <= n; ++i) star |= G[i].size() == n - 1;
            long long ans = 1LL * (n - 2) * y + (star ? x : y);
            printf("%I64d\n", ans);
        }
    }
    return 0;
}
