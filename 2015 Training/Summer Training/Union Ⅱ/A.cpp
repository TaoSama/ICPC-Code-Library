//
//  Created by TaoSama on 2015-08-24
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

int n, m, k, a[2005];
long long dp[2005][300];
map<int, int> mp;
vector<int> G[2005];

long long __lcm(long long a, long long b) {
    return a / __gcd(a, b) * b;
}

long long dfs(int u, int x) {
    long long &ret = dp[u][mp[x]];
    if(~ret) return ret;
    if(u == n) return ret = (x == k);

    ret = 0;
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        long long lcm = __lcm(x, a[v]);
        if(x == lcm || k % lcm) continue;
        ret = (ret + dfs(v, lcm)) % MOD;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &m, &k) == 3) {
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
        }
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);

        int id = 0; mp.clear();
        for(int i = 2; i * i <= k; ++i) {
            if(k % i == 0) {
                mp[i] = ++id;
                if(i != k / i) mp[k / i] = ++id;
            }
        }

        memset(dp, -1, sizeof dp);
        printf("%lld\n", dfs(1, a[1]));
    }
    return 0;
}
