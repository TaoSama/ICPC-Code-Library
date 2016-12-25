//
//  Created by TaoSama on 2016-12-14
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, c[N];
vector<int> G[N];

typedef long long LL;
LL f[N][2], ans[N];
const LL LLINF = 0x3f3f3f3f3f3f3f3fLL;

void dfs(int u, int fa) {
    f[u][0] = -LLINF;
    f[u][1] = c[u];
    ans[u] = -LLINF;
    LL first = -LLINF, second = -LLINF;
    for(int v : G[u]) {
        if(v == fa) continue;
        dfs(v, u);
        ans[u] = max(ans[u], ans[v]);
        f[u][1] += f[v][1];
        f[u][0] = max({f[u][0], f[v][0], f[v][1]});
        LL t = max(f[v][0], f[v][1]);
        if(t > first) {
            swap(first, second);
            first = t;
        } else if(t > second)
            second = t;
    }
    if(second != -LLINF) ans[u] = max(ans[u], first + second);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);


    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= n; ++i) scanf("%d", c + i);
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1, 0);
        if(ans[1] != -LLINF) printf("%I64d\n", ans[1]);
        else puts("Impossible");
    }
    return 0;
}
