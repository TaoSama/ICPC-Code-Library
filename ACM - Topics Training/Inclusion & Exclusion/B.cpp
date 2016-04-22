//
//  Created by TaoSama on 2015-10-24
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

LL l, r, cnt[60];

LL ksm(LL x, int n) {
    LL ret = 1;
    while(n) {
        if(n & 1) {
            if(1.0 * ret * x > 2e18) return -1;
            ret *= x;
        }
        if(1.0 * x * x > 2e18 && n > 1) return -1;
        x *= x;
        n >>= 1;
    }
    return ret;
}

//pow(x, 1 / n)
LL get(LL x, int n) {
    LL l = 1, r = x;
    while(l <= r) {
        LL m = l + r >> 1;
        LL ret = ksm(m, n);
        if(~ret && ret <= x) l = m + 1;
        else r = m - 1;
    }
    return l - 1;
}

LL calc(LL x) {
    LL ret = 0;
    for(int i = 1; i < 60; ++i)
        cnt[i] = get(x, i);
    for(int i = 60 - 1; i; --i) {
        for(int j = 2 * i; j < 60; j += i)
            cnt[i] -= cnt[j];
        ret += 1LL * i * cnt[i];
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%I64d%I64d", &l, &r) == 2 && (l || r)) {
        printf("%I64d\n", calc(r) - calc(l - 1));
    }
    return 0;
}
