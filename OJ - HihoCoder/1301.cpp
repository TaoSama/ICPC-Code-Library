//
//  Created by TaoSama on 2016-05-06
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
LL f[30];
int digit[30];

LL dfs(int i, int e) {
    if(!i) return 1;
    if(!e && ~f[i]) return f[i];
    LL ret = 0;
    int to = e ? digit[i] : 9;
    for(int d = 0; d <= to; ++d) {
        if(d == 4 || d == 7) continue;
        ret += dfs(i - 1, e && d == to);
    }
    return e ? ret : f[i] = ret;
}

LL calc(LL x) {
    int cnt = 0;
    for(; x; x /= 10) digit[++cnt] = x % 10;
    return dfs(cnt, 1);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%lld", &n);
    memset(f, -1, sizeof f);
    LL l = 0, r = 2e18;
    while(l <= r) {
        LL m = l + r >> 1;
        if(m + 1 - calc(m) < n) l = m + 1;
        else r = m - 1;
    }
    printf("%lld\n", l);
    return 0;
}
