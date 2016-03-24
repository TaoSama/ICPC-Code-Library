//
//  Created by TaoSama on 2015-08-13
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
vector<int> G[1505];

int dp[1505][2]; // dp[i][0,1]:= not put or put

void dfs(int u, int f) {
    dp[u][0] = 0; dp[u][1] = 1;
    for(auto &v : G[u]) {
        if(v == f) continue;
        dfs(v, u);
        dp[u][1] += min(dp[v][0], dp[v][1]);
        dp[u][0] += dp[v][1];
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 0; i < n; ++i) G[i].clear();
        for(int i = 1; i <= n; ++i) {
            int u, v, k; scanf("%d:(%d)", &u, &k);
            for(int j = 1; j <= k; ++j) {
                scanf("%d", &v);
                G[u].push_back(v);
                G[v].push_back(u);
            }
        }
        dfs(0, -1);
        printf("%d\n", min(dp[0][1], dp[0][0]));
    }
    return 0;
}
