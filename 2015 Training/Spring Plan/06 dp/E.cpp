//
//  Created by TaoSama on 2015-08-05
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

int dp[15][2], digit[15];
int l, r;

//i:= i-th digit s:= state's legality e:= is_limited
int dfs(int i, bool s, bool e) {
    if(i == 0) return 1;
    if(!e && dp[i][s] >= 0) return dp[i][s];

    int ret = 0;
    int to = e ? digit[i] : 9;
    for(int d = 0; d <= to; ++d) {
        if(d == 4 || s && d == 7) continue;
        ret += dfs(i - 1, d == 3, e && d == to);
    }
    if(!e) dp[i][s] = ret;
    return ret;
}

int calc(int x) {
    int cnt = 0;
    while(x) {
        digit[++cnt] = x % 10;
        x /= 10;
    }
    memset(dp, -1, sizeof dp);
    return dfs(cnt, 0, 1);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &l, &r) == 2) {
        printf("%d\n", calc(r) - calc(l - 1));
    }
    return 0;
}
