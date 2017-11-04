//
//  Created by TaoSama on 2017-01-14
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
vector<pair<int, int> > G[N];
pair<int, int> maxSub[N], fa[N];
//u子树中不超过n/2的最大子树
//不经过u这颗子树fa子树中能取到的不超过n/2的最大子树
//再dfs一次变成不经过u这颗子树整棵树中能取到的不超过n/2的最大子树

void getMax(pair<int, int>& x, pair<int, int> y) {
    if(y.first > x.first) x = y;
    else if(y.first == x.first) x.second += y.second;
}

void dfs1(int u, int f) {
    pair<int, int> maxv = {0, 1}, nxtv = { -INF, -INF};
    for(auto& e : G[u]) {
        int v, c; tie(v, c) = e;
        if(v == f) continue;
        dfs1(v, u);
        pair<int, int> cur = {maxSub[v].first + c, maxSub[v].second};
        if(cur.first > maxv.first) {
            nxtv = maxv;
            maxv = cur;
        } else if(cur.first == maxv.first) maxv.second += cur.second;
        else getMax(nxtv, cur);
    }

	printf("u = %d max = %d %d nxt = %d %d\n", u, maxv.first, maxv.second,
			nxtv.first, nxtv.second);
    for(auto& e : G[u]) {
        int v, c; tie(v, c) = e;
        if(v == f) continue;
        pair<int, int> cur = {maxSub[v].first + c, maxSub[v].second};
        if(cur.first == maxv.first) fa[v] = nxtv;
        else fa[v] = maxv;
    }
    maxSub[u] = maxv;
}

pair<int, int> ans[N];
void dfs2(int u, int f) {
    printf("u = %d max = %d %d fa = %d %d\n", u, maxSub[u].first, maxSub[u].second,
           fa[u].first, fa[u].second);
    ans[u] = {maxSub[u].first + fa[u].first, maxSub[u].second* fa[u].second};
    for(auto& e : G[u]) {
        int v, c; tie(v, c) = e;
        if(v == f) continue;
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
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            G[u].push_back({v, c});
            G[v].push_back({u, c});
        }
        fa[1] = {0, 1};
        dfs1(1, 0);
        dfs2(1, 0);
        static int kase = 0;
        printf("Case #%d:", ++kase);
        for(int i = 1; i <= n; ++i) printf(" %d", ans[i].second);
        puts("");
    }

    return 0;
}
