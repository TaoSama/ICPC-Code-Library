//
//  Created by TaoSama on 2016-07-15
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

typedef long long LL;

map<LL, LL> mp;

int getDep(LL u) {
    return 63 - __builtin_clzll(u);
}

LL lca(LL u, LL v) {
    if(getDep(u) > getDep(v)) swap(u, v);
    while(getDep(u) != getDep(v)) v >>= 1;
    if(u == v) return u;
    while(u != v) u >>= 1, v >>= 1;
    return u;
}

void update(LL u, LL lca, LL v) {
    while(u != lca) {
		mp[u] += v;
		u >>= 1;
    }
}

LL query(LL u, LL lca) {
    LL ans = 0;
    while(u != lca) {
        if(mp.count(u)) ans += mp[u];
		u >>= 1;
    }
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int q; scanf("%d", &q);
    while(q--) {
        int op; scanf("%d", &op);
        if(op == 1) {
            LL u, v, w; scanf("%I64d%I64d%I64d", &u, &v, &w);
            LL _lca = lca(u, v);
            update(u, _lca, w);
            update(v, _lca, w);
        } else {
            LL u, v; scanf("%I64d%I64d", &u, &v);
            LL _lca = lca(u, v);
            LL ans = query(u, _lca) + query(v, _lca);
            printf("%I64d\n", ans);
        }
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
