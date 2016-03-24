//
//  Created by TaoSama on 2015-08-07
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
int dp[10005][3];
//0->server    1->father is server, i not    2->neither, son has a server
vector<int> G[N];

void dfs(int u, int f) {
    dp[u][0] = 1; dp[u][1] = 0; dp[u][2] = 10000;
    for(auto &v : G[u]) {
        if(v == f) continue;
        dfs(v, u);
        dp[u][0] += min(dp[v][1], dp[v][0]); //son can be both sever & non-sever
        dp[u][1] += dp[v][2]; //son's son can have a server
    }

    for(auto &v : G[u]) {
        if(v == f) continue;
        //neither u or his father is server
        //from [u][1]->[u][2] only difference is one server
        dp[u][2] = min(dp[u][2], dp[u][1] - dp[v][2] + dp[v][0]);
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1 && n != -1) {
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1, -1);
        printf("%d\n", min(dp[1][0], dp[1][2]));
        scanf("%d", &n);
    }
    return 0;
}
