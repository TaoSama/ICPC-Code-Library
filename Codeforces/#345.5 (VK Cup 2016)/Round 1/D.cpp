//
//  Created by TaoSama on 2016-03-29
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k;
int a[N];
typedef long long LL;

LL ksm(LL x, LL n, LL MOD) {
    LL ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &k);
    LL sum[2] = {}, mod[2] = {MOD, MOD + 2};
    LL power[2] = {1, 1}, base[2] = {2, 2};
    for(int i = 0; i <= n; ++i) {
        scanf("%d", a + i);
        for(int j = 0; j < 2; ++j) {
            sum[j] = (sum[j] + a[i] * power[j] % mod[j]) % mod[j];
            sum[j] = (sum[j] + mod[j]) % mod[j];
            power[j] = power[j] * base[j] % mod[j];
        }
    }

    int ans = 0;
    for(int i = 0; i < 2; ++i) power[i] = 1, base[i] = ksm(2, mod[i] - 2, mod[i]);
    for(int i = 0; i <= n; ++i) {
        LL delta[2];
        for(int j = 0; j < 2; ++j) {
            delta[j] = (a[i] - sum[j] * power[j] % mod[j]) % mod[j];
            delta[j] = (delta[j] + mod[j]) % mod[j];
            power[j] = power[j] * base[j] % mod[j];
        }

        LL cof = INF;
        if(delta[0] == delta[1]) cof = delta[0];
        if(delta[0] - mod[0] == delta[1] - mod[1]) cof = delta[0] - mod[0];
        if(abs(cof) > k || i == n && cof == 0) continue;

        ++ans;
    }
    printf("%d\n", ans);
    return 0;
}
