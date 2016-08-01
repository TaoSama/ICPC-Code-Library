//
//  Created by TaoSama on 2016-07-29
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

typedef long long LL;

int n, m;
LL a[N], b[N];
int sum[N];

bool check(LL x) {
    memset(sum, 0, sizeof sum);
    for(int i = 1; i <= m; ++i) {
        int l = lower_bound(a + 1, a + 1 + n, b[i] - x) - a;
        int r = upper_bound(a + 1, a + 1 + n, b[i] + x) - a;
        --r;
//        pr(i); pr(l); prln(r);
        if(l > r) continue;
        ++sum[l]; -- sum[r + 1];
    }
    for(int i = 2; i <= n; ++i) sum[i] += sum[i - 1];
    return !count(sum + 1, sum + 1 + n, 0);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%I64d", a + i);
    for(int i = 1; i <= m; ++i) scanf("%I64d", b + i);

//    prln(check(1));

    LL l = 0, r = 2e9 + 10, ans = -1;
    while(l <= r) {
        int m = (l + r) / 2;
        if(check(m)) ans = m, r = m - 1;
        else l = m + 1;
    }
//    prln(check((int)2e9));
    printf("%I64d\n", ans);

    return 0;
}
