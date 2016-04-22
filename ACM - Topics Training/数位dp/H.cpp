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

int A, B, F;
int dp[10][5000], digit[10];

int dfs(int i, int w, int e) {
    if(!i) return w >= 0;
    if(!e && ~dp[i][w]) return dp[i][w];
    int ret = 0;
    int to = e ? digit[i] : 9;
    for(int d = 0; d <= to; ++d) {
        if(w - d * (1 << i - 1) < 0) break;
        ret += dfs(i - 1, w - d * (1 << i - 1), e && d == to);
    }
    return e ? ret : dp[i][w] = ret;
}

int calc() {
    int cnt = 0;
    for(; B; B /= 10) digit[++cnt] = B % 10;
    F = 0;
    for(int i = 0; A; ++i, A /= 10) F += A % 10 * (1 << i);
    return dfs(cnt, F, 1);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    memset(dp, -1, sizeof dp);
    int kase = 0;
    while(t--) {
        scanf("%d%d", &A, &B);
        printf("Case #%d: %d\n", ++kase, calc());
    }
    return 0;
}
