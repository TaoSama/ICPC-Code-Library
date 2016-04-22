//
//  Created by TaoSama on 2015-10-19
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

int __lcm(int a, int b) {
    return a / __gcd(a, b) * b;
}

typedef long long LL;

//lcm 1...9 = 2520
const int MAGIC = 2520;
LL dp[25][MAGIC][50], digit[25];
int mp[MAGIC]; //total 48

LL dfs(int i, int mod, int lcm, int e) {
    if(!i) return mod % lcm == 0;
    if(!e && ~dp[i][mod][mp[lcm]]) return dp[i][mod][mp[lcm]];
    LL ret = 0;
    int to = e ? digit[i] : 9;
    for(int d = 0; d <= to; ++d) {
        ret += dfs(i - 1, (mod * 10 + d) % MAGIC,
                   d ? __lcm(lcm, d) : lcm, e && d == to);
    }
    if(!e) dp[i][mod][mp[lcm]] = ret;
    return ret;
}

LL calc(LL x) {
    int cnt = 0;
    for(; x; x /= 10) digit[++cnt] = x % 10;
    return dfs(cnt, 0, 1, 1);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int cnt = 0;
    for(int i = 1; i <= MAGIC; ++i)
        if(MAGIC % i == 0) mp[i] = ++cnt;
    memset(dp, -1, sizeof dp);
    while(t--) {
        LL l, r; scanf("%I64d%I64d", &l, &r);
        printf("%I64d\n", calc(r) - calc(l - 1));
    }
    return 0;
}
