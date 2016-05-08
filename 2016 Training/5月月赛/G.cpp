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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
struct DSU {
    int n, p[N];
    set<int> s[N];
    void init(int _n) {
        n = _n;
        for(int i = 1; i <= n; ++i) resume(i);
    }
    void resume(int i) {
        p[i] = i;
        s[i].clear();
        s[i].insert(i);
    }
    int find(int x) {
        return p[x] == x ? x : find(p[x]);
    }
    void del(int x) {
        x = find(x);
        for(auto u : s[x]) {
            if(u == x) continue;
            resume(u);
        }
        resume(x);
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return;
        if(s[x].size() > s[y].size()) swap(x, y);
        p[x] = y;
        for(auto u : s[x]) s[y].insert(u);
    }
    int size(int x) {
        x = find(x);
        return s[x].size();
    }
    bool same(int x, int y) {
        x = find(x), y = find(y);
        return x == y;
    }
} dsu;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        dsu.init(n);
        while(m--) {
            char op[2];
            int x, y; scanf("%s%d", op, &x);
            if(*op == 'U') {
                scanf("%d", &y);
                dsu.unite(x, y);
            } else if(*op == 'D') dsu.del(x);
            else if(*op == 'S') printf("%d\n", dsu.size(x));
            else {
                scanf("%d", &y);
                puts(dsu.same(x, y) ? "Yes" : "No");
            }
        }
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
