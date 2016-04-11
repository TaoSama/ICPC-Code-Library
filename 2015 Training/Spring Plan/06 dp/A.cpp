//
//  Created by TaoSama on 2015-08-05
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

int n, a[1005], m;
int dp[20005];
const int OFF = 10000;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i)  scanf("%d", a + i);
        scanf("%d", &m);
        if(m < 5) {printf("%d\n", m); continue;}
        m -= 5;

        sort(a + 1, a + 1 + n);
        memset(dp, 0, sizeof dp);
        for(int i = 1; i < n; ++i) {
            for(int j = m; j >= a[i]; --j) {
                dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
            }
        }

        //can put one biggest more
        int ans = m + 5 - dp[m] - a[n];
        printf("%d\n", ans);
    }
    return 0;
}
