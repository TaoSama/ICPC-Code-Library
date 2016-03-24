//
//  Created by TaoSama on 2016-01-09
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
LL n;

int d[][2] = {{ -1, 2}, { -2, 0}, { -1, -2}, {1, -2}, {2, 0}, {1, 2}};

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%I64d", &n) == 1) {
        LL l = 1, r = 1e9;
        while(l <= r) {
            LL m = l + r >> 1;
            if(3 * m * (m + 1) <= n) l = m + 1;
            else r = m - 1;
        }
        n -= 3 * l * (l - 1);
        if(!n) {printf("%I64d 0\n", l - 1 << 1, 0); continue;}

        LL x = l << 1, y = 0;
        for(int i = 0; i < 6; ++i) {
            LL k = min(n, l);
            x += k * d[i][0];
            y += k * d[i][1];
            n -= k;
        }
        printf("%I64d %I64d\n", x, y);
    }
    return 0;
}
