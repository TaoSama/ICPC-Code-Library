//
//
//
//  Created by TaoSama on 2015-04-12
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

int v1, v2, t, d, dp[105][1105];
int ans;

/*void dfs(int dep, int cur, int sum)
{
	if(cur - d * (t - dep + 1) > v2) return;
	if(cur + d * (t - dep + 1) < v2) return;
	if(sum + (cur + d) * (t - dep + 1) <= ans) return;
	if(dep == t){
		if(cur == v2 && sum > ans) ans = sum;
		return;
	}
	for(int i = -d; i <= d; ++i){
		dfs(dep + 1, cur + i, sum + cur + i);
	}
}*/

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> v1 >> v2 >> t >> d) {
        for(int i = 0; i <= t; ++i){
			for(int j = 0; j <= 1100; ++j)
				dp[i][j] = -2e7;
        }
        dp[1][v1] = v1;
        for(int i = 2; i <= t; ++i) {
            for(int j = 0; j <= 1100; ++j) {
                for(int k = -d; k <= d; ++k) {
                    if(j - k >= 0) {
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + j);
                    }
                }
            }
        }
        /*ans = -INF;
        dfs(1, v1, v1);*/
        cout << dp[t][v2] << endl;
    }
    return 0;
}
