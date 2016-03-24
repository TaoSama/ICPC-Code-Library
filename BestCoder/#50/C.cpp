//
//  Created by TaoSama on 2015-08-08
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

int n;
long long dp[65], ans[65];

void init() {
    dp[1] = dp[2] = 1;
    for(int i = 3; i <= 60; ++i) {
        dp[i] = 1;
        for(int j = 1; j <= i - 3; ++j)
            dp[i] += dp[j];
    }
    for(int i = 1; i <= 60; ++i)
        ans[i] += ans[i - 1] + dp[i];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    init();
    while(cin >> n) {
        cout << ans[n] << '\n';
    }
    return 0;
}
