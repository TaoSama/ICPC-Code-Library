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

int l, r;
int dp[35][35][35], digit[35];

int dfs(int i, int m0, int m1, bool first, bool e) {
    if(!i) return m0 >= m1;
    if(!e && ~dp[i][m0][m1]) return dp[i][m0][m1];
    int ret = 0;
    int to = e ? digit[i] : 1;
    for(int d = 0; d <= to; ++d)
        ret += dfs(i - 1, first && !d ? i == 1 : m0 + (d ^ 1),
                   m1 + d, first && !d, e && d == to);
    if(!e) dp[i][m0][m1] = ret;
    return ret;
}

int calc(int x) {
    int cnt = 0;
    for(; x; x >>= 1) digit[++cnt] = x & 1;
    return dfs(cnt, 0, 0, 1, 1);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    memset(dp, -1, sizeof dp);
    while(scanf("%d%d", &l, &r) == 2) {
        printf("%d\n", calc(r) - calc(l - 1));
    }
    return 0;
}
