//
//  Created by TaoSama on 2016-07-23
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

int n, k;
int a[N];
vector<int> G[N];
typedef long long LL;

int sz[N];
void dfs1(int u, int f) {
    sz[u] = a[u];
    for(int v : G[u]) {
        if(v == f) continue;
        dfs1(v, u);
        sz[u] += sz[v];
    }
}

void dfs2(int u, int f, LL& ans) {
    for(int v : G[u]) {
        if(v == f) continue;
        ans += min(sz[v], sz[1] - sz[v]);
        dfs2(v, u, ans);
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    scanf("%d%d", &n, &k);
    for(int i = 1; i <= k << 1; ++i) {
        int x; scanf("%d", &x);
        a[x] = 1;
    }
    for(int i = 1; i < n; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs1(1, -1);
    LL ans = 0;
    dfs2(1, -1, ans);
    printf("%I64d\n", ans);

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
