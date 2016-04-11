//
//  Created by TaoSama on 2015-09-25
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

int n, m, p;
int dp[60005];
//1: dp[i][j]:= i desert j energy's minimum size
//2: dp[i][j]:= i truck j cost's maximum size

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &m, &p);

        memset(dp, 0x3f, sizeof dp);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i) {
            int w, v, c; scanf("%d%d%d", &w, &v, &c);
            for(int k = 1; c > 0; c -= k, k <<= 1) {
                int mul = min(k, c);
                for(int j = p + 100; j >= mul * w; --j)
                    dp[j] = min(dp[j], dp[j - mul * w] + mul * v);
            }
        }
        int V = INF;
        for(int i = p; i <= p + 100; ++i) V = min(V, dp[i]);
//      printf("V: %d\n", V);

        memset(dp, 0, sizeof dp);
        int ans = INF;
        for(int i = 1; i <= m; ++i) {
            int v, w, c; scanf("%d%d%d", &v, &w, &c);
            for(int k = 1; c > 0; c -= k, k <<= 1) {
                int mul = min(k, c);
                for(int j = 50000; j >= mul * w; --j) {
                    dp[j] = max(dp[j], dp[j - mul * w] + mul * v);
                    if(dp[j] >= V) ans = min(ans, j);
                }
            }
        }
        if(ans == INF) puts("TAT");
        else printf("%d\n", ans);
    }
    return 0;
}
