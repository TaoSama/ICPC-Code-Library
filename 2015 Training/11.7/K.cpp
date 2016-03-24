//
//  Created by TaoSama on 2015-11-07
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

int n, m, w[105], dp[20005];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &m, &n);
        for(int i = 1; i <= n; ++i) scanf("%d", w + i);
        memset(dp, 0x3f, sizeof dp);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = 20000; j >= w[i]; --j)
                dp[j] = min(dp[j], dp[j - w[i]] + 1);
        int ans;
        for(int i = m; i <= 20000; ++i)
            if(dp[i] != INF) {ans = i; break;}
        printf("%d %d\n", ans, dp[ans]);
    }
    return 0;
}
