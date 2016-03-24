//
//
//
//  Created by TaoSama on 2015-03-29
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

int n, x[205], y[205], dp[205][205], ans[205];

int cal(int i, int j) {
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d", &n) == 1 && n) {
        for(int i = 1; i <= n; ++i) scanf("%d%d", x + i, y + i);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                dp[i][j] = cal(i, j);

        memset(ans, 0x3f, sizeof ans);
        queue<int> q; ans[1] = 0; q.push(1);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v = 1; v <= n; ++v) {
                if(max(ans[u], dp[u][v]) < ans[v]) {
                    ans[v] = max(ans[u], dp[u][v]);
                    q.push(v);
                }
            }
        }
        printf("Scenario #%d\nFrog Distance = %.3f\n\n",
               ++kase, sqrt(ans[2]));
    }
    return 0;
}
