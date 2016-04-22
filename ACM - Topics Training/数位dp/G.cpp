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

int n, dp[15][3][13], digit[15];

int dfs(int i, int s, int mod, int e) {
    if(!i) return s == 2 && !mod;
    if(!e && ~dp[i][s][mod]) return dp[i][s][mod];
    int ret = 0;
    int to = e ? digit[i] : 9;
    for(int d = 0; d <= to; ++d) {
        int t = 0;
        if(s == 2 || s == 1 && d == 3) t = 2;
        else if(d == 1) t = 1;
        ret += dfs(i - 1, t, (mod * 10 + d) % 13, e && d == to);
    }
    if(!e) dp[i][s][mod] = ret;
    return ret;
}

int calc(int x) {
    int cnt = 0;
    for(; x; x /= 10) digit[++cnt] = x % 10;
    memset(dp, -1, sizeof dp);
    return dfs(cnt, 0, 0, 1);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        printf("%d\n", calc(n));
    }
    return 0;
}
