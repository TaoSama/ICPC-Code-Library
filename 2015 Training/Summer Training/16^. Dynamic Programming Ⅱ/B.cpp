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

int n, T;
vector<int> G[N];

//dp[i]:= let i send to his boss need how many workers
int dfs(int u) {
    if(G[u].empty()) return 1;
    int k = G[u].size();
    vector<int> dp;
    for(int i = 0; i < k; ++i) {
        int v = G[u][i];
        dp.push_back(dfs(v));
    }
    sort(dp.begin(), dp.end());
    int c = (k * T - 1) / 100 + 1, ret = 0;
    for(int i = 0; i < c; ++i) ret += dp[i];
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &T) == 2 && (n || T)) {
        for(int i = 0; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= n; ++i) {
            int u; scanf("%d", &u);
            G[u].push_back(i);
        }
        printf("%d\n", dfs(0));
    }
    return 0;
}
