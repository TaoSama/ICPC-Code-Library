//
//  Created by TaoSama on 2016-03-13
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

#define y1 asdasdasd

int w, h, n;
int x1[N], y1[N], x2[N], y2[N];
bool vis[N];
vector<int> G[N];

bool intersect(int i, int j) {
    int minx = max(x1[i], x1[j]);
    int maxx = min(x2[i], x2[j]);
    int miny = max(y1[i], y1[j]);
    int maxy = min(y2[i], y2[j]);
    if(minx >= maxx || miny >= maxy) return false;
    return true;
}

bool inside(int x, int y, int i) {
    return x > x1[i] && x < x2[i] && y > y1[i] && y < y2[i];
}

//i被j包含
int cover(int i, int j) {
    int ret = 0;
    if(inside(x1[i], y1[i], j)) ret |= 1;
    if(inside(x1[i], y2[i], j)) ret |= 2;
    if(inside(x2[i], y2[i], j)) ret |= 4;
    if(inside(x2[i], y1[i], j)) ret |= 8;
    return ret;
}

void dfs(int st, int u, int& sta) {
    vis[u] = true;
    for(int v : G[u]) {
        if(vis[v]) continue;
        sta |= cover(st, v);
        dfs(st, v, sta);
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d%d", &w, &h, &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d%d%d%d", x1 + i, y1 + i, x2 + i, y2 + i);
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = i + 1; j <= n; ++j)
            if(intersect(i, j)) G[i].push_back(j);
    }
//    for(int i = 1; i <= n; ++i){
//      printf("%d: ", i);
//      for(int v : G[i]) printf("%d ", v); puts("");
//    }
    pair<int, int> ans = make_pair(0, 0);
    for(int i = 1; i <= n; ++i) {
        memset(vis, false, sizeof vis);
        int sta = 0;
        dfs(i, i, sta);
        if(sta == 15) continue;
        int cnt = 0;
        for(int j = 1; j <= n; ++j) cnt += vis[j];
        if(cnt > ans.first) ans = make_pair(cnt, i);
    }
    printf("%d %d\n", ans.first, ans.second);
    return 0;
}
