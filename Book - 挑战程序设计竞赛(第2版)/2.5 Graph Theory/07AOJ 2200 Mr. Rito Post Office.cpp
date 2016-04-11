//
//  AOJ 2200 Mr. Rito Post Office
//
//  Created by TaoSama on 2015-03-20
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
#define CLR(x,y) memset(x, y, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int sea[205][205], land[205][205], dp[1005][205];
int n, m, r, a[1005];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m && (n + m)) {
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                sea[i][j] = land[i][j] = i == j ? 0 : INF;

        for(int i = 1; i <= m; ++i) {
            int x, y, t; char c;
            cin >> x >> y >> t >> c;
            if(c == 'S') sea[x][y] = sea[y][x] = min(sea[x][y], t);
            else land[x][y] = land[y][x] = min(land[x][y], t);
        }

        cin >> r;
        for(int i = 1; i <= r; ++i)  cin >> a[i];

        //Floyd
        for(int k = 1; k <= n; ++k) {
            for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= n; ++j) {
                    sea[i][j] = min(sea[i][j], sea[i][k] + sea[k][j]);
                    land[i][j] = min(land[i][j], land[i][k] + land[k][j]);
                }
            }
        }

        //dp[i][j]:= 到达i镇子 船停在j镇子的最小时间
        memset(dp, 0x3f, sizeof dp);
        dp[1][a[1]] = 0;
        for(int i = 1; i <= r; ++i) {
            for(int j = 1; j <= n; ++j) {
                //一定可以走陆路
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + land[a[i - 1]][a[i]]);
                for(int k = 1; k <= n; ++k) //枚举水路船停的位置
                    //从i-1镇子回到船在的j  开船到k镇子船丢在那里  陆路从k到i镇子
                    //三个INF 可能加爆。。。。。
                    dp[i][k] = min((long long)dp[i][k], (long long)dp[i - 1][j] +
                                   land[a[i - 1]][j] + sea[j][k] + land[k][a[i]]);
            }
        }
        cout << *min_element(dp[r], dp[r] + n + 1) << endl;
    }
    return 0;
}
