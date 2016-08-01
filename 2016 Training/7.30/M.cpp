//
//  Created by TaoSama on 2016-07-30
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
const int N = 5e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, p[N];
struct State {
    int id, priority, time;
    bool operator<(const State& s) const {
        return priority > s.priority;
    }
};
vector<State> s[N];
struct Edge {
    int v, c;
} fa[N];
vector<Edge> G[N];

int ans[N];

void dfs(int u, int f, int cap) {
    if(~f) {
        sort(s[u].begin(), s[u].end());
        for(State& sta : s[u]) ++sta.time;
        while(cap-- && s[u].size()) {
            s[f].push_back(s[u].back());
            s[u].pop_back();
        }
    }
    for(Edge& e : G[u]) {
        int v = e.v, c = e.c;
        if(v == f) continue;
        dfs(v, u, c);
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
        for(int i = 1; i <= n; ++i) scanf("%d", p + i);
        for(int i = 1; i < n; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            G[u].push_back({v, c});
            G[v].push_back({u, c});
        }

        for(int i = 1; i <= n; ++i) {
            s[i].clear();
            s[i].push_back({i, p[i], 0});
        }

        while(s[1].size() != n) dfs(1, -1, -1);
        for(auto& sta : s[1]) ans[sta.id] = sta.time;
        for(int i = 1; i <= n; ++i) printf("%d%c", ans[i], " \n"[i == n]);
    }

    return 0;
}
