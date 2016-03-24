//
//  Created by TaoSama on 2015-11-19
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, a[N], b[N];
int dp[N][N], down[N][N], up[N][N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        for(int i = 1; i <= m; ++i) scanf("%d", b + i);

        for(int i = 2; i <= n; ++i) {
            for(int j = 2; j <= m; ++j) {
                if(a[i] == b[j - 1]) down[i][j] = j - 1;
                else down[i][j] = down[i][j - 1];
            }
        }
        for(int i = 2; i <= n; ++i) {
            for(int j = 2; j <= m; ++j) {
                if(b[j] == a[i - 1]) up[i][j] = i - 1;
                else up[i][j] = up[i - 1][j];
            }
        }

        for(int i = 2; i <= n; ++i) {
            for(int j = 2; j <= m; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if(a[i] == b[j]) continue;
                int a = down[i][j], b = up[i][j];
                if(a && b) dp[i][j] = max(dp[i][j], dp[b - 1][a - 1] + 2);
            }
        }
        printf("%d\n", dp[n][m]);
    }
    return 0;
}
