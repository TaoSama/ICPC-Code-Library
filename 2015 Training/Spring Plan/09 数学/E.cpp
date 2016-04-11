//
//  Created by TaoSama on 2015-09-24
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

typedef long long LL;

LL x, m;

LL ksm(LL x, LL n, LL m) {
    LL ret = 1;
    while(n) {
        if(n & 1) ret = ret * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return ret;
}

LL dfs(LL n) {
    if(n <= 18) {
        LL x = 0;
        for(int i = 1; i <= n; ++i)
            x = (x * 10 + 1) % m;
        return x;
    }
    LL tmp = dfs(n >> 1), mul = n & 1 ? 10 : 1;
//  cout << "tmp: " << tmp << " mul: " << mul << " " << ksm(10, n >> 1, m) << endl;
    return (tmp * ksm(10, n >> 1, m) % m * mul + tmp * mul + mul / 10) % m;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
//    ios_base::sync_with_stdio(0);

    while(scanf("%lld%lld", &x, &m) == 2) {
        printf("%lld\n", dfs(x));
    }
    return 0;
}
