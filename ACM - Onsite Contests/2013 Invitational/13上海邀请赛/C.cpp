//
//  Created by TaoSama on 2015-04-25
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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

int n, m, a[105][105], dp[105][105], pre[105][105];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d%d", &n, &m);
        printf("Case %d\n", ++kase);

        memset(dp, 0x3f, sizeof dp);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                scanf("%d", &a[i][j]);
                if(i == n) dp[i][j] = a[i][j];
            }
        }

        for(int i = n - 1; i >= 1; --i){
            for(int j = 1; j <= m; ++j){
                for(int k = j - 1; k <= j + 1; ++k){
                    if(dp[i][j] >= dp[i + 1][k] + a[i][j]){
                        dp[i][j] = dp[i + 1][k] + a[i][j];
                        pre[i][j] = k;
                    }
                }
            }
        }

        int Min = INF, p;
        for(int i = 1; i <= m; ++i){
            if(dp[1][i] <= Min){
                Min = dp[1][i];
                p = i;
            }
        }
        vector<int> ans;
        ans.push_back(p);
        for(int i = 1; i < n; ++i){
            ans.push_back(pre[i][p]);
            p = pre[i][p];
        }
        for(int i = 0; i < n; ++i){
            if(i != n - 1) printf("%d ", ans[i]);
            else printf("%d\n", ans[i]);
        }
    }
    return 0;
}
