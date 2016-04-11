//
//  Created by TaoSama on 2015-09-20
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
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int dp[N];
bool vis[N];

inline int read() {
    char c = getchar();
    int f = 1, x = 0;
    while(!isdigit(c)) {
//      if(c == '-') f = -1;
        c = getchar();
    }
    while(isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

vector<int> T[N], G[N];

int ans;
int dfs(int u) {
    vis[u] = true;
    for(int i = 0; i < T[u].size(); ++i) {
        int v = T[u][i];
        dfs(v);
        dp[u] += dp[v] - 1;
    }
    ans = min(ans, dp[u]);
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(vis[v]) --dp[v];
    }
    vis[u] = false;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; t = read();
    int kase = 0;
    while(t--) {
        n = read(); m = read();
        for(int i = 1; i <= n; ++i) T[i].clear(), G[i].clear();
        memset(dp, 0, sizeof dp);
        memset(vis, false, sizeof vis);
        for(int i = 1; i < n; ++i) {
            int u = read(), v = read();
            if(u > v) swap(u, v);
            T[u].push_back(v);
            dp[u]++; dp[v]++;
        }
        for(int i = n; i <= m; ++i) {
            int u = read(), v = read();
            if(u > v) swap(u, v);
            G[u].push_back(v);
            dp[u]++; dp[v]++;
        }

        ans = INF;
        dfs(1);
        printf("Case #%d: %d\n", ++kase, ans);
    }
    return 0;
}
