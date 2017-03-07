//
//  Created by TaoSama on 2017-02-23
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

// phi
LL phi(LL n) {
    LL ret = n;
    for(LL i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            ret = ret / i * (i - 1);
            while(n % i == 0) n /= i;
        }
    }
    if(n > 1) ret = ret / n * (n - 1);
    return ret;
}

LL F(LL n, LL k, LL e) {
    if(k == 1) return phi(n);
    if(e == 1) return 1;
    if(k & 1) return phi(F(n, k - 1, phi(e)));
    return F(n, k - 1, e);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> k) {
        cout << F(n, k, n) % MOD << endl;
    }

//  prln(phi(1000000000000LL));
//  prln(phi(phi(1000000000000LL)) % MOD);
    return 0;
}
