//
//  Created by TaoSama on 2015-08-24
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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

long long n, m;

long long f(long long x) {
    return x * (x - 1) * (x - 2) / 6;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%lld%lld", &n, &m) == 2) {
        long long ans = f((n + 1) * (m + 1));
        ans -= (n + 1) * f(m + 1) + (m + 1) * f(n + 1);
        for(int i = 2; i <= n; ++i)
            for(int j = 2; j <= m; ++j)
                ans -= (__gcd(i, j) - 1) * (n - i + 1) * (m - j + 1) * 2;
        printf("%lld\n", ans);
    }
    return 0;
}
