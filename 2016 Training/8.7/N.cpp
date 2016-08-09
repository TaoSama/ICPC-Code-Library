//
//  Created by TaoSama on 2016-08-07
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

int n;
vector<pair<int, int> > G[N];

int rtDw[N], rtUp[N], subUp[N];

void dfs1(int u, int f, int dw) {
    if(u != 1) {
        rtDw[u] = rtDw[f] + dw;
        rtUp[u] = rtUp[f] + !dw;
    }
    for(auto& p : G[u]) {
        int v = p.first, c = p.second;
        if(v == f) continue;
        dfs1(v, u, c);
        subUp[u] += subUp[v] + !c;
    }
//    pr(u); prln(subUp[u]);
}

int need[N];
void dfs2(int u, int f) {
    need[u] = rtDw[u] + subUp[1] - rtUp[u];
//    pr(u); pr(rtDw[u]); pr(subUp[1]); pr(subUp[1] - rtUp[u]); prln(need[u]);
    for(auto& p : G[u]) {
        int v = p.first, c = p.second;
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

    scanf("%d", &n);
    for(int i = 1; i < n; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        G[u].push_back({v, 1});
        G[v].push_back({u, 0});
    }

    dfs1(1, 0, 0);
    dfs2(1, 0);

    int minv = *min_element(need + 1, need + 1 + n);
    vector<int> ans;
    for(int i = 1; i <= n; ++i) if(need[i] == minv) ans.push_back(i);
    printf("%d\n", minv);
    for(int i = 0; i < ans.size(); ++i)
        printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);

    return 0;
}
