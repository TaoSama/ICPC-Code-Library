//
//  Created by TaoSama on 2016-03-08
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;

struct DSU {
    int n, p[N];
    void init(int _n) {
        n = _n;
        for(int i = 0; i < n; ++i) p[i] = i;
    }
    int find(int x) {
        return p[x] = p[x] == x ? x : find(p[x]);
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return;
        p[x] = y;
    }
} dsu;

typedef pair<int, int> P;

void merge(vector<P>& tmp) {
    sort(tmp.begin(), tmp.end());
    int sz = tmp.size();
    for(int j = 0; j < sz; ++j) {
        int p = j;
        while(j + 1 < sz && tmp[j + 1].first == tmp[p].first) {
            dsu.unite(tmp[j + 1].second, tmp[p].second);
            ++j;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &m);
    vector<vector<P> >  a(n, vector<P>(m)), b(m, vector<P>(n));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            int x; scanf("%d", &x);
            a[i][j] = {x, i * m + j};
            b[j][i] = {x, i * m + j};
        }
    }

    dsu.init(n * m);
    //merge row equal values
    for(int i = 0; i < n; ++i) merge(a[i]);
    //merge column equal values
    for(int i = 0; i < m; ++i) merge(b[i]);

    //new graph
    vector<int> in(n * m, 0);
    vector<vector<int> > g(n * m);
    for(int i = 0; i < n; ++i) {
        vector<P>& cur = a[i];
        for(int j = 0; j < m; ++j) {
            auto iter = upper_bound(cur.begin(), cur.end(), P(cur[j].first, INF));
            if(iter == cur.end()) continue;
            int u = dsu.find(cur[j].second), v = dsu.find(iter->second);
            g[u].push_back(v); ++in[v];
            for(int p = j; j < m && cur[j + 1].first == cur[p].first; ++j);
        }
    }
    for(int i = 0; i < m; ++i) {
        vector<P>& cur = b[i];
        for(int j = 0; j < n; ++j) {
            auto iter = upper_bound(cur.begin(), cur.end(), P(cur[j].first, INF));
            if(iter == cur.end()) continue;
            int u = dsu.find(cur[j].second), v = dsu.find(iter->second);
            g[u].push_back(v); ++in[v];
            for(int p = j; j < n && cur[j + 1].first == cur[p].first; ++j);
        }
    }

    queue<int> q;
    vector<int> ans(n * m, 0);
    for(int i = 0; i < n * m; ++i) {
        if(in[i]) continue;
        q.push(i);
        ans[i] = 1;
    }
    while(q.size()) {
        int u = q.front(); q.pop();
        for(int v : g[u]) {
            ans[v] = max(ans[v], ans[u] + 1);
            if(--in[v] == 0) q.push(v);
        }
    }

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            printf("%d%c", ans[dsu.find(i * m + j)], " \n"[j == m - 1]);
    return 0;
}
