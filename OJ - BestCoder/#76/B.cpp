//
//  Created by TaoSama on 2016-03-19
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
vector<int> G[N];

void add(int &x, int y) {
    if((x += y) >= MOD) x -= MOD;
}

typedef long long LL;
LL f[N], sum[N];

void dfs(int u, int fa) {
    f[u] = sum[u] = 1;
    for(int v : G[u]) {
        if(v == fa) continue;
        dfs(v, u);
        sum[u] = sum[u] * (f[v] + 1) % MOD + sum[v] * f[u] % MOD;
        sum[u] %= MOD;
        f[u] = f[u] * (f[v] + 1) % MOD;
    }
}


int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 2; i <= n; ++i) {
            int x; scanf("%d", &x);
            G[x].push_back(i);
            G[i].push_back(x);
        }
        dfs(1, -1);

        int ans = 0;
        for(int i = 1; i <= n; ++i) add(ans, sum[i]);
        printf("%d\n", ans);
    }
    return 0;
}
