//
//  Created by TaoSama on 2016-08-15
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
#include <cassert>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
int n, a[N];
LL m, sum[N];

int L[N], R[N];

LL calc(LL h, int l, int i, int r) {
    LL h1 = h - (i - l);
    LL h2 = h - (r - i);
    LL all = -h;
    all += (h1 + h) * (i - l + 1) / 2;
    all += (h2 + h) * (r - i + 1) / 2;
    all += a[l] - h1;
    assert(a[l] >= h1);
    all += a[r] - h2;
    assert(a[r] >= h2);
    return all;
}

bool check(LL mid) {
    for(int i = 1; i <= n; ++i) if(a[i] >= mid) return true;

    memset(L, 0, sizeof L);
    memset(R, 0x3f, sizeof R);
    for(int i = 1; i <= n; ++i) {
        LL to1 = i + mid - a[i], to2 = i - (mid - a[i]);
        if(to1 <= n) L[to1] = max(L[to1], i);
        if(to2 >= 1) R[to2] = min(R[to2], i);
    }
    for(int i = 1; i <= n; ++i) L[i] = max(L[i], L[i - 1]);
    for(int i = n; i; --i) R[i] = min(R[i], R[i + 1]);

    for(int i = 1; i <= n; ++i) {
        int l = L[i], r = R[i];
        if(l == 0 || r == INF) continue;
        LL all = calc(mid, l, i, r);
        LL need = all - (sum[r] - sum[l - 1]);
        if(need <= m) return true;
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    freopen("landscape.in", "r", stdin);
    freopen("landscape.out", "w", stdout);

    while(scanf("%d%I64d", &n, &m) == 2) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            sum[i] = sum[i - 1] + a[i];
        }

        LL l = 1, r = 2e9, ans = -1;
        while(l <= r) {
            LL mid = l + r >> 1;
            if(check(mid)) ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        printf("%I64d\n", ans);
    }

    return 0;
}
