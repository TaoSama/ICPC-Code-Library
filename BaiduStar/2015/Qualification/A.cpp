//
//  Created by TaoSama on 2015-05-23
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e6 + 10;

long long n, dp[N];

void init() {
    dp[1] = 1; dp[2] = 2;
    for(int i = 3; i <= 1e6; ++i) {
        dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
        dp[i] %= MOD;
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    init();
    while(t--) {
        scanf("%I64d", &n);
        printf("Case #%d:\n%I64d\n", ++kase, dp[n]);
    }
    return 0;
}
