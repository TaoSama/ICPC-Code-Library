//
//  Created by TaoSama on 2015-09-26
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

LL C, k1, b1, k2;

LL ksm(LL x, LL n, LL m) {
    LL ret = 1;
    while(n) {
        if(n & 1) ret = ret * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d%d%d%d", &C, &k1, &b1, &k2) == 4) {
        bool ok = false;
        printf("Case #%d:\n", ++kase);
        for(int a = 1; a < C; ++a) {
            int b = C - ksm(a, (k1 + b1) % (C - 1), C);
            if(ksm(a, k1 % (C - 1), C) == ksm(b, k2 % (C - 1), C)) {
                ok = true;
                printf("%d %d\n", a, b);
            }
        }
        if(!ok) puts("-1");
    }
    return 0;
}
