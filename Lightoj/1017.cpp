//
//  Created by TaoSama on 2015-10-28
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

int n, w, k, a[105], sum[105], cnt[105];
int dp[105][105];

void getMax(int &x, int y) {x = max(x, y);}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        map<int, int> mp;
        scanf("%d%d%d", &n, &w, &k);
        for(int i = 1; i <= n; ++i) {
            int x, y; scanf("%d%d", &x, &y);
            ++mp[y];
        }
        n = mp.size();
        map<int, int>::iterator iter = mp.begin();
        for(int i = 1; i <= n; ++i, ++iter) {
            a[i] = iter->first;
            sum[i] = sum[i - 1] + iter->second;
        }
        int ans = 0;
        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < k; ++j) {
                int p = upper_bound(a + 1, a + 1 + n, a[i] + w) - a - 1;
                getMax(dp[p][j + 1], dp[i - 1][j] + sum[p] - sum[i - 1]);
                getMax(dp[i][j], dp[i - 1][j]);
            }
            getMax(ans, dp[i][k]);
        }
        printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}
