//
//  Created by TaoSama on 2015-09-01
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
int dp[15], digit[15];

int dfs(int i, bool e) {
    if(i == 0) return 1;
    if(!e && dp[i] >= 0) return dp[i];

    int ret = 0;
    int to = e ? digit[i] : 9;
    for(int d = 0; d <= to; ++d) {
        if(d == 3 || d == 8) continue;
        ret += dfs(i - 1, e && d == to);
    }
    if(!e) dp[i] = ret;
    return ret;
}

int calc(int x) {
    int cnt = 0;
    while(x) {
        digit[++cnt] = x % 10;
        x /= 10;
    }
    memset(dp, -1, sizeof dp);
    return dfs(cnt, 1);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1 && n) {
        printf("%d: %d\n", n, calc(n) - 1);
    }
    return 0;
}
