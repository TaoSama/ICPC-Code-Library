//
//  Created by TaoSama on 2016-08-25
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
const int N = 4e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
vector<int> G[N];
int sz[N], maxSub[N], fa[N];
//u子树中不超过n/2的最大子树
//不经过u这颗子树fa子树中能取到的不超过n/2的最大子树
//再dfs一次变成不经过u这颗子树整棵树中能取到的不超过n/2的最大子树

void dfs1(int u, int f) {
    sz[u] = 1;
    int maxv = 0, nxtv = 0;
    for(int v : G[u]) {
        if(v == f) continue;
        dfs1(v, u);
        sz[u] += sz[v];

        if(maxSub[v] >= maxv) {
            nxtv = maxv;
            maxv = maxSub[v];
        } else if(maxSub[v] > nxtv) nxtv = maxSub[v];
    }

    for(int v : G[u]) {
        if(v == f) continue;
        if(maxSub[v] == maxv) fa[v] = nxtv;
        else fa[v] = maxv;
    }
    maxSub[u] = maxv;
    if(sz[u] <= n / 2) maxSub[u] = max(maxSub[u], sz[u]);
}

int ans[N];
void dfs2(int u, int f) {
    int cnt = 0, ok = 1;
    for(int v : G[u]) {
        if(v == f) continue;
        if(sz[v] > n / 2) {
            if(sz[v] - maxSub[v] > n / 2) ok = 0;
            else ++cnt;
        }
    }
    if(n - sz[u] > n / 2) {
        if(n - sz[u] - fa[u] > n / 2) ok = 0;
        else ++cnt;
    }
    ans[u] = ok && cnt <= 1;

    for(int v : G[u]) {
        if(v == f) continue;
        fa[v] = max(fa[v], fa[u]);
        if(n - sz[v] <= n / 2) fa[v] = max(fa[v], n - sz[v]);
        dfs2(v, u);
    }
}


int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        dfs1(1, 0);
        dfs2(1, 0);

        for(int i = 1; i <= n; ++i)
            printf("%d%c", ans[i], " \n"[i == n]);
    }

    return 0;
}
