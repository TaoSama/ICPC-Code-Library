//
//  Created by TaoSama on 2015-12-12
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

typedef unsigned long long ULL;

ULL l, r;

ULL calc(ULL x) {
    if(x == 0) return 1;
    int k = 63 - __builtin_clzll(x + 1);
    if(x == (1ULL << k) - 1) return 3 * calc((1ULL << k - 1) - 1);
    return calc((1ULL << k) - 1) + 2 * calc(x - (1ULL << k));
}

void gao() {
//  freopen("B.txt", "w", stdout);
    int table[105][105];
    for(int i = 0; i < 1 << 5; ++i) {
        printf("%3d: ", i);
        for(int j = 0; j <= i; ++j) {
            if(j == 0 || j == i) table[i][j] = 1;
            else table[i][j] = (table[i - 1][j] + table[i - 1][j - 1]) & 1;
            printf("%d ", table[i][j]);
        }
        puts("");
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

//  gao();
    while(scanf("%llu%llu", &l, &r) == 2 && (l || r)) {
        ULL ans = calc(r) - (l ? calc(l - 1) : 0);
        printf("%llu\n", ans);
    }
    return 0;
}
