//
//  Created by TaoSama on 2017-03-05
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

int n, m, k;
int r[N], c[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < k; ++i) scanf("%d%d", r + i, c + i);
    long long ans = 1LL * n * (n + 1) / 2 * m * (m + 1) / 2;
    for(int s = 1; s < 1 << k; ++s) {
        int minx, miny, maxx, maxy;
        minx = miny = INF;
        maxx = maxy = -INF;
        int cnt = 0;
        for(int i = 0; i < k; ++i) {
            if(!(s >> i & 1)) continue;
            minx = min(minx, r[i]);
            miny = min(miny, c[i]);
            maxx = max(maxx, r[i]);
            maxy = max(maxy, c[i]);
            ++cnt;
        }
        if(cnt & 1) ans -= 1LL * minx * miny * (n - maxx + 1) * (m - maxy + 1);
        else ans += 1LL * minx * miny * (n - maxx + 1) * (m - maxy + 1);
    }
    printf("%lld\n", ans);

    return 0;
}
