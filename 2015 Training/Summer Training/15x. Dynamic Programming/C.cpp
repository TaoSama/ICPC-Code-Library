//
//  Created by TaoSama on 2015-08-10
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

int n, x[1005], y[1005];
double dp[1005][1005];

double getdis(int i, int j) {
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

//dp[x][y]:= 1~max(i, j) have visited & i > j need how long distance
double dfs(int i, int j) {
    double &ret = dp[i][j];
    if(ret >= 0) return ret;
    if(i == n) return ret = getdis(j, n);

    //i->i+1 or j->i+1  as defined dfs(i+1,j) & dfs(i+1,i)
    ret = min(dfs(i + 1, j) + getdis(i, i + 1), dfs(i + 1, i) + getdis(j, i + 1));
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d%d", x + i, y + i);

        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                dp[i][j] = -1;
        printf("%.2f\n", dfs(1, 1));
    }
    return 0;
}
