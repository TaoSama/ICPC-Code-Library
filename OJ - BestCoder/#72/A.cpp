//
//  Created by TaoSama on 2016-02-13
//  Copyright (c) 2016 TaoSama. All rights reserved.
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

int n;
long long seed, p[N][2];
inline long long rand(long long l, long long r) {
    static long long mo = 1e9 + 7, g = 78125;
    return l + ((seed *= g) %= mo) % (r - l + 1);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%I64d", &n, &seed);
        for(int i = 1; i <= n; ++i) {
            p[i][0] = rand(-1000000000, 1000000000);
            p[i][1] = rand(-1000000000, 1000000000);
        }
        LL ans = 0;
        for(int s = 0; s < 1 << 2; ++s) {
            LL minv = 1e18, maxv = -1e18;
            for(int i = 1; i <= n; ++i) {
                LL cur = 0;
                for(int j = 0; j < 2; ++j)
                    if(s >> j & 1) cur += p[i][j];
                    else cur -= p[i][j];
                minv = min(minv, cur);
                maxv = max(maxv, cur);
            }
            ans = max(ans, maxv - minv);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
