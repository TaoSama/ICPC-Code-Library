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
const int N = 5e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
pair<int, int> a[N];
int dp[N], g[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d%d", &a[i].first, &a[i].second);
        sort(a + 1, a + 1 + n);

        for(int i = 1; i <= n; ++i) g[i] = INF;
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            int k = lower_bound(g + 1, g + 1 + n, a[i].second) - g;
            dp[i] = k;
            ans = max(ans, dp[i]);
            g[k] = a[i].second;
        }
        printf("Case %d:\nMy king, at most %d road%scan be built.\n\n",
               ++kase, ans, ans > 1 ? "s " : " ");
    }
    return 0;
}
