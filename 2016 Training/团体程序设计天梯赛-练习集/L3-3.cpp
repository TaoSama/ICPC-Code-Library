//
//  Created by TaoSama on 2016-05-07
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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

int n;
struct DSU {
    int n, p[N], sz[N];
    void init(int _n) {
        n = _n;
        for(int i = 1; i <= n; ++i) p[i] = i, sz[i] = 1;
    }
    int find(int x) {
        return p[x] = p[x] == x ? x : find(p[x]);
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        p[x] = y;
        sz[y] += sz[x]; sz[x] = 0;
    }
} dsu;
vector<int> G[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        int k; scanf("%d:", &k);
        while(k--) {
            int x; scanf("%d", &x);
            G[x].push_back(i);
        }
    }

    dsu.init(n);
    for(int i = 1; i <= 1000; ++i) {
        for(int j = 1; j < G[i].size(); ++j) {
            int x = G[i][j - 1], y = G[i][j];
            dsu.unite(x, y);
        }
    }
    vector<int> ans;
    for(int i = 1; i <= 1000; ++i) {
        if(dsu.p[i] != i) continue;
        ans.push_back(dsu.sz[i]);
    }
    sort(ans.begin(), ans.end());

    printf("%d\n", ans.size());
    for(int i = ans.size() - 1; ~i; --i)
        printf("%d%c", ans[i], " \n"[i == 0]);

#ifdef LOCAL
    printf("\n\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
