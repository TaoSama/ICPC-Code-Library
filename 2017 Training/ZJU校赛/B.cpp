//
//  Created by TaoSama on 2017-04-10
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

int n;
vector<int> G[N];

int sz[N], dep[N];
int stk[N], top;
LL s[N], coff[N];

void dfs1(int u, int fa) {
    sz[u] = 1;
    dep[u] = dep[fa] + 1;
    for(int v : G[u]) {
        if(v == fa) continue;
        dfs1(v, u);
        sz[u] += sz[v];
    }
}

LL ans;
// save: \sum_x dep[x]-(1+dep[u]-dep[x])= \sum_x 2*dep[x]-1-dep[u]
void dfs2(int u, int fa) {
    if(top) s[top] -= coff[top] * sz[u];
    stk[++top] = u;
    coff[top] = -2 * dep[u] + 1;
    s[top] = s[top - 1] + coff[top] * sz[u];

    if(top > 1) {
        int mid = (top + 1) / 2;
        LL cur = s[top] - s[mid] + 1LL * dep[u] * sz[stk[mid + 1]];
        ans = min(ans, cur);
    }
    for(int v : G[u]) {
        if(v == fa) continue;
        dfs2(v, u);
    }
    --top;
    if(top) s[top] += coff[top] * sz[u];
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
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        dep[0] = -1;
        dfs1(1, 0);
        ans = 0;
        dfs2(1, 0);
        for(int i = 1; i <= n; ++i) ans += dep[i];
        printf("%lld\n", ans);
    }

    return 0;
}
