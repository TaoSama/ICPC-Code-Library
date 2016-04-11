//
//  Created by TaoSama on 2015-11-22
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

int k, digit[15], dp[11][90][90];

int dfs(int i, int m, int sm, int e) {
    if(!i) return !m && !sm;
    if(!e && ~dp[i][m][sm]) return dp[i][m][sm];
    int to = e ? digit[i] : 9;
    int ret = 0;
    for(int d = 0; d <= to; ++d)
        ret += dfs(i - 1, (m * 10 + d) % k, (sm + d) % k, e && d == to);
    return e ? ret : dp[i][m][sm] = ret;
}

int calc(int x) {
    int cnt = 0;
    for(; x; x /= 10) digit[++cnt] = x % 10;
    if(k > cnt * 9) return 1; //only 0 can
    return dfs(cnt, 0, 0, 1);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    int t; scanf("%d", &t);
    while(t--) {
        int l, r; scanf("%d%d%d", &l, &r, &k);
        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n", ++kase, calc(r) - calc(l - 1));
    }
    return 0;
}
