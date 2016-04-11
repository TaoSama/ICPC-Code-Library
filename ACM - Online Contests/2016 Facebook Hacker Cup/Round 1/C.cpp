//
//  Created by TaoSama on 2016-01-17
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

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, A, B;
typedef long long LL;
LL a[N];

LL calc(int x) {
    LL ret = 0;
    LL cycle = x / a[n], left = x % a[n];
    for(int i = 1; i <= n; ++i)
        ret += (a[i] - a[i - 1]) * (a[i] - a[i - 1]);
    ret *= cycle;
    int k = lower_bound(a + 1, a + n + 1, left) - a;
    for(int i = 1; i <= k; ++i)
        ret += (min(a[i], left) - a[i - 1]) * (min(a[i], left) - a[i - 1]);
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("yachtzee.txt", "r", stdin);
    freopen("yachtzee_out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &A, &B);
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", a + i);
            a[i] += a[i - 1];
        }
        double ans = 1.0 * (calc(B) - calc(A)) / 2 / (B - A);
        static int kase = 0;
        printf("Case #%d: %.9f\n", ++kase, ans);
    }
    return 0;
}
