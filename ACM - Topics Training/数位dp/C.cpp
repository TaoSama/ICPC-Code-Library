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

int dp[10][2], digit[10];

int dfs(int i, bool s, bool e) {
    if(!i) return 1;
    if(!e && ~dp[i][s]) return dp[i][s];
    int ret = 0;
    int to = e ? digit[i] : 9;
    for(int d = 0; d <= to; ++d) {
        if(d == 4 || s && d == 2) continue;
        ret += dfs(i - 1, d == 6, e && d == to);
    }
    if(!e) dp[i][s] = ret;
    return ret;
}

int calc(int x) {
    int cnt = 0;
    for(; x; x /= 10) digit[++cnt] = x % 10;
    memset(dp, -1, sizeof dp);
    return dfs(cnt, 0, 1);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int l, r;
    while(scanf("%d%d", &l, &r) == 2 && l && r) {
        printf("%d\n", calc(r) - calc(l - 1));
    }
    return 0;
}
