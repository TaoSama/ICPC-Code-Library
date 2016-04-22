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

LL dp[20][20][1500], digit[20]; //total 1377

LL dfs(int i, int p, int sum, int e) {
    if(!i) return sum == 0;
    if(!e && ~dp[i][p][sum]) return dp[i][p][sum];
    int to = e ? digit[i] : 9;
    LL ret = 0;
    for(int d = 0; d <= to; ++d)
        ret += dfs(i - 1, p, sum + (i - p) * d, e && d == to);
    return e ? ret : dp[i][p][sum] = ret;
}

LL calc(LL x) {
    int cnt = 0;
    for(; x; x /= 10) digit[++cnt] = x % 10;
    LL ret = 0;
    for(int i = 1; i <= cnt; ++i)
        ret += dfs(cnt, i, 0, 1);
    return ret - cnt + 1;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    memset(dp, -1, sizeof dp);
    while(t--) {
        LL l, r; scanf("%I64d%I64d", &l, &r);
        printf("%I64d\n", calc(r) - calc(l - 1));
    }
    return 0;
}
