//
//  Created by TaoSama on 2016-02-03
//  Copyright (c) 2015 TaoSama. All rights reserved.
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
#include <cassert>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct DSU {
    int n, p[N], r[N];
    void init(int _n) {
        n = _n;
        for(int i = 1; i <= n; ++i) p[i] = i, r[i] = 0;
    }
    int find(int x) {
        return p[x] = p[x] == x ? x : find(p[x]);
    }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        if(r[x] < r[y]) p[x] = y;
        else {
            p[y] = x;
            if(r[x] == r[y]) ++r[x];
        }
        return true;
    }
    bool same(int x, int y) {
        x = find(x), y = find(y);
        return x == y;
    }
} dsu, tmp;

int n, m;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        dsu.init(n);
        int last = 0, ans = n;
        vector<pair<pair<int, int>, int> > Q;
        for(int q = 1; q <= m; ++q) {
            int op, u, v; scanf("%d%d%d", &op, &u, &v);
            u ^= last, v ^= last;
//          printf("op.... %d %d %d\n", op, u, v);
            if(op == 0) {
                Q.push_back(make_pair(make_pair(u, v), q));
                ans -= dsu.unite(u, v);
                printf("%d\n", ans);
                last = ans;
            } else {
                int ret = dsu.same(u, v);
                if(ret) {
                    tmp.init(n);
                    for(int i = 0; i < Q.size(); ++i) {
                        int x = Q[i].first.first, y = Q[i].first.second;
                        int k = Q[i].second;
                        tmp.unite(x, y);
                        if(tmp.same(u, v)) {
                            ret = k;
                            break;
                        }
                    }
                }
                printf("%d\n", ret);
                last = ret;
            }
        }
    }
    return 0;
}
