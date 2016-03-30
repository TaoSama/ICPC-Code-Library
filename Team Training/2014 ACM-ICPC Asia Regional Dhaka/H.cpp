//
//  Created by TaoSama on 2015-12-09
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

int n;
double dp[165][5];
int pre[165][5], cnt[165], sum[165];

void printDp(int i, int j) {
    printf("dp[%d][%d] = %.5f\n", i, j, dp[i][j]);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d", &n);
        memset(cnt, 0, sizeof cnt);
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            ++cnt[x];
        }
        sum[0] = cnt[0];
        for(int i = 1; i <= 160; ++i) sum[i] = sum[i - 1] + cnt[i];

        double avg = n / 4.0;
        for(int i = 0; i <= 160; ++i) {
            dp[i][1] = abs(sum[i] - avg);
            for(int j = 2; j <= 4; ++j) {
                dp[i][j] = INF;
                for(int k = 0; k < i; ++k) {
                    double dif = abs(sum[i] - sum[k] - avg);
                    if(dp[i][j] > dp[k][j - 1] + dif) {
                        dp[i][j] = dp[k][j - 1] + dif;
                        pre[i][j] = k;
                    }
                }
            }
        }

        vector<int> ans;
        int cur = 160, k = 4;
        while(ans.size() != 3) {
            ans.push_back(pre[cur][k]);
            cur = pre[cur][k];
            --k;
        }
        printf("Case %d: %d %d %d\n", ++kase, ans[2], ans[1], ans[0]);
    }
    return 0;
}
