//
//  Created by TaoSama on 2017-06-18
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
vector<int> G[N];
int c[N];

void dfs(int u, int fa, int d, pair<int, int>& diameter) {
    diameter = max(diameter, {d, u});
    for(int v : G[u]) {
        if(v == fa) continue;
        dfs(v, u, d + 1, diameter);
    }
}

void dfs2(int u, int fa, int d, int g, int& ans) {
    if(g == 1) ans = max(ans, d);
    for(int v : G[u]) {
        if(v == fa) continue;
        dfs2(v, u, d + 1, __gcd(g, c[v]), ans);
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    for(int i = 1; i < n; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i) scanf("%d", c + i);

    pair<int, int> diameter = { -1, -1};
    dfs(1, -1, 0, diameter);
    int a = diameter.second;
    dfs(a, -1, 0, diameter);
    int b = diameter.second;

    int ans = 0;
    dfs2(a, -1, 0, c[a], ans);
    dfs2(b, -1, 0, c[b], ans);
    printf("%d\n", ans);

    return 0;
}
