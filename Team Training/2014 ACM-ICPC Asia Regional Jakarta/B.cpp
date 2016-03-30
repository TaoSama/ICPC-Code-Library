//
//  Created by TaoSama on 2015-12-21
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#include <unordered_set>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
vector<int> G[N];
bool vis[N];

void dfs(int u, int f, int &sz, int &sum) {
    ++sz; sum += G[u].size();
    vis[u] = true;
    for(int v : G[u]) {
        if(v == f || vis[v]) continue;
        dfs(v, f, sz, sum);
    }
}

bool test(int u, int v) {
    memset(vis, false, sizeof vis);
    int sz1 = 0, sum1 = 0;
    dfs(u, v, sz1, sum1);

    memset(vis, false, sizeof vis);
    int sz2 = 0, sum2 = 0;
    dfs(v, u, sz2, sum2);

    return sz1 == sz2 && sum1 == sum2 && sum1 == sz1 * (sz1 - 1) + 1;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) G[i].clear();
        while(m--) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        int ans = 0;
        for(int u = 1; u <= n; ++u)
            for(int v : G[u])  ans += test(u, v);

        static int kase = 0;
        printf("Case #%d: %d\n", ++kase, ans >> 1);
    }
    return 0;
}
