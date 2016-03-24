//
//  Created by TaoSama on 2015-08-08
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

int n, m;
int w[105], v[105], c[105];
int dp[105];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; ++i)
            scanf("%d%d%d", w + i, v + i, c + i);

        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= m; ++i) {
            for(int k = 1; c[i] > 0; c[i] -= k, k <<= 1) {
                int t = min(k, c[i]);
                for(int j = n; j >= t * w[i]; --j)
                    dp[j] = max(dp[j], dp[j - t * w[i]] + t * v[i]);
            }
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}
