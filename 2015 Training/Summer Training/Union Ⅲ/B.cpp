//
//  Created by TaoSama on 2015-08-26
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
bool isPrime(LL x) {
    for(LL i = 2; i * i <= x; ++i)
        if(x % i == 0) return false;
    return x != 1;
}

LL b, n;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%lld%lld", &b, &n) == 2) {
        LL ans = 0;
        for(int i = 1; i <= n; ++i)  ans = ans * b + 1;
//      printf("%lld\n", ans);
        puts(isPrime(ans) ? "YES" : "NO");
    }
    return 0;
}
