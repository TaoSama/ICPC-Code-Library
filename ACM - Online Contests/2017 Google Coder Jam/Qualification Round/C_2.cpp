//
//  Created by TaoSama on 2017-04-08
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
LL n, k;

map<LL, LL> mp;

LL dfs(LL n, LL x) {
    if(n < x) return 0;
    if(mp.count(n)) return mp[n];
    LL& ret = mp[n];
    ret = 0;
    LL mid = (n + 1) / 2;
    ret = 1 + dfs(mid - 1, x) + dfs(n - mid, x);
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%lld%lld", &n, &k);

        LL l = 1, r = n, ans = -1;
        while(l <= r) {
            LL mid = (l + r) / 2;
            mp.clear();
            if(dfs(n, mid) >= k) l = mid + 1, ans = mid;
            else r = mid - 1;
        }

        LL mid = (ans + 1) / 2, ls = mid - 1, rs = ans - mid;

        static int kase = 0;
        printf("Case #%d: %lld %lld\n", ++kase, rs, ls);
    }

    return 0;
}
