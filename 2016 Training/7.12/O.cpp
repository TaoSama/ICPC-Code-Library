//
//  Created by TaoSama on 2016-07-12
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
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

char s[105];
int c[3], e[3], p[3];
typedef long long LL;
LL b;

LL calc(LL x) {
    LL ret = 0;
    for(int i = 0; i < 3; ++i)
        ret += max(0LL, x * c[i] - e[i]) * p[i];
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%s", s) == 1) {
        for(int i = 0; i < 3; ++i) scanf("%d", e + i);
        for(int i = 0; i < 3; ++i) scanf("%d", p + i);
        scanf("%I64d", &b);

        memset(c, 0, sizeof c);
        for(int i = 0; s[i]; ++i) {
            if(s[i] == 'B') ++c[0];
            else if(s[i] == 'S') ++c[1];
            else ++c[2];
        }
//      printf("%d %d %d\n", c[0], c[1], c[2]);

        LL l = 1, r = 1e15, ans = 0;
        while(l <= r) {
            LL m = l + r >> 1;
            if(calc(m) <= b) ans = m, l = m + 1;
            else r = m - 1;
        }
        printf("%I64d\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
