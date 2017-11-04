//
//  Created by TaoSama on 2015-06-18
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, q, a[N], v[N], r[N], dp[N][20];

int RMQ(int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);
    return max(dp[l][k], dp[r - (1 << k) + 1][k]);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1 && n) {
        scanf("%d", &q);
        int last = -INF;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            if(i == 1 || a[i] != a[i - 1]) v[i] = 1;
            else v[i] = v[i - 1] + 1;
        }
//        for(int i = 1; i <= n; ++i) cout << v[i] << ' '; cout << endl;
        for(int i = n; i >= 1; --i) {
            dp[i][0] = v[i];
            if(i == n || a[i] != a[i + 1]) r[i] = i;
            else r[i] = r[i + 1];
        }
//      for(int i = 1; i <= n; ++i) cout << r[i] << ' '; cout << endl;
        for(int j = 1; 1 << j <= n; ++j)
            for(int i = 1; i + (1 << j - 1) <= n; ++i)
                dp[i][j] = max(dp[i][j - 1], dp[i + (1 << j - 1)][j - 1]);

        while(q--) {
            int x, y; scanf("%d%d", &x, &y);
            int ans;
            if(y > r[x]) ans = max(r[x] - x + 1, RMQ(r[x] + 1, y));
            else ans = y - x + 1;
            printf("%d\n", ans);
        }
    }
    return 0;
}
