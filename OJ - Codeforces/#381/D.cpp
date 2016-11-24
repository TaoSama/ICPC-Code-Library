//
//  Created by TaoSama on 2016-11-24
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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];
vector<pair<int, int> > G[N];

int ans[N];
typedef long long LL;
pair<LL, int> stk[N];
void dfs(int u, LL dis, int dep) {
    stk[dep] = {dis, u};
    auto iter = lower_bound(stk + 1, stk + dep + 1, make_pair(dis - a[u], -INF));
    ++ans[u]; --ans[(--iter)->second];
    for(auto& e : G[u]) {
        int v, c; tie(v, c) = e;
        dfs(v, dis + c, dep + 1);
        ans[u] += ans[v];
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);


    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 2; i <= n; ++i) {
            int f, c; scanf("%d%d", &f, &c);
            G[f].push_back({i, c});
        }

        memset(ans, 0, sizeof ans);
        dfs(1, 0, 1);
        for(int i = 1; i <= n; ++i) printf("%d%c", ans[i] - 1, " \n"[i == n]);
    }

    return 0;
}
