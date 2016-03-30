//
//  Created by TaoSama on 2015-12-08
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

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        LL l, r; scanf("%lld%lld", &l, &r);

//      LL a = l, b = l;
//      for(LL i = l; i <= r; ++i) a |= i, b &= i;

        LL ansAnd = l, ansOr = l;
        //trailing zeros for OR
        for(int i = 0; i < 64; ++i) {
            if(l >> i & 1) break;
            LL tmp = l + (1LL << i);
            if(tmp <= r) ansOr |= tmp;
        }
        //lowbit makes lowest 1 to 0 for AND
        //lowbit makes lowest 0 to 1(except trailing zeros) for OR
        while(l <= r) {
            ansOr |= l;
            ansAnd &= l;
            l += l & -l;
        }

        printf("Case %d: %lld %lld\n", ++kase, ansOr, ansAnd);
//      printf("Case %d: %lld %lld\n\n", kase, a, b);
    }
    return 0;
}
