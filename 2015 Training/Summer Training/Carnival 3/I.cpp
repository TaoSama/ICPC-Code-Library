//
//  Created by TaoSama on 2015-08-09
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

LL n, m, k;

LL ksm(LL x, LL n) {
    LL ret = 1;
    while(n) {
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return ret;
}

LL fac_2(LL x) {
    LL ret = 1;
    for(int i = x; i >= x - 1; --i)
        ret = ret * i % MOD;
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m >> k) {
        if(k > n || k == 1) {
            cout << ksm(m, n) << '\n';
        } else if(k == n) {
            cout << ksm(m, (k + 1) / 2) << '\n';
        } else if(k & 1) {
            LL ans = (m + fac_2(m)) % MOD;
            cout << ans << '\n';
        } else {
            cout << m << '\n';
        }
    }
    return 0;
}
