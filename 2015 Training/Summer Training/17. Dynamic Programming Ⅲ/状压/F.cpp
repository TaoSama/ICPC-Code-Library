//
//  Created by TaoSama on 2015-08-10
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

int k;
long long n, dp[65][65];

//dp[i][j]:= i-th balloon experiment j times can determine the height
//if i is broken can determine dp[i-1][j-1] + 1, if not, then dp[i][j-1]
void gao() {
    for(int i = 1; i < 64; ++i)
        for(int j = 1; j < 64; ++j)
            dp[i][j] = dp[i - 1][j - 1] + 1 + dp[i][j - 1];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    gao();
    while(scanf("%d%lld", &k, &n) == 2 && k) {
        if(k > 63) k = 63;
        long long ans = lower_bound(dp[k], dp[k] + 64, n) - dp[k];
        if(ans > 63) puts("More than 63 trials needed.");
        else printf("%lld\n", ans);
    }
    return 0;
}
