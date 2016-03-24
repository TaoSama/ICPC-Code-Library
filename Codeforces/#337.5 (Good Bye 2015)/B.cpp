//
//  Created by TaoSama on 2015-10-21
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

LL l, r;
LL dp[70][2][70], digit[70];

LL dfs(int i, int m0, int m1, bool first, bool e) {
    if(!i) return m0;
    if(!e && ~dp[i][m0][m1]) return dp[i][m0][m1];
    LL ret = 0;
    int to = e ? digit[i] : 1;
    for(int d = 0; d <= to; ++d) {
        if(m0 && !d) continue;
        ret += dfs(i - 1, first && !d ? i == 1 : m0 + (d ^ 1),
                   m1 + d, first && !d, e && d == to);
    }
    if(!e) dp[i][m0][m1] = ret;
    return ret;
}

LL calc(LL x) {
    if(!x) return 1;
    LL cnt = 0;
    for(; x; x >>= 1) digit[++cnt] = x & 1;
    return dfs(cnt, 0, 0, 1, 1);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    memset(dp, -1, sizeof dp);
    while(scanf("%I64d%I64d", &l, &r) == 2) {
//      pr(calc(l - 1)); prln(calc(r));
        printf("%I64d\n", calc(r) - calc(l - 1));
    }
    return 0;
}
