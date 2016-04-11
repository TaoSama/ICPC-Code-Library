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

int w, b;
double dp[1005][1005]; //dp[w][b]

double dfs(int w, int b) {
    if(dp[w][b] >= 0) return dp[w][b];
    if(!w) return dp[w][b] = 0; // no white
    if(!b) return dp[w][b] = 1; // no black

    double ret = 1.0 * w / (w + b); //wxx
    ret += 1.0 * b / (w + b) * (b - 1) / (w + b - 1) * (b - 2) / (w + b - 2)
           * dfs(w, b - 3);     //bbb*subproblem
    ret += 1.0 * b / (w + b) * (b - 1) / (w + b - 1) * w / (w + b - 2)
           * dfs(w - 1, b - 2); //bbw*subproblem
    return dp[w][b] = ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &w, &b);

    for(int i = 0; i <= w; ++i)
        for(int j = 0; j <= b; ++j)
            dp[i][j] = -1;

    for(int i = 1; i <= w; ++i) {
        dp[i][1] = 1.0 * i / (i + 1); //one black can take white only
        dp[i][2] = 1.0 * i / (i + 2) + 1.0 / (i + 2) * 1.0 / (i + 1) * 1.0 / i;
    }
    dp[1][2] = 1.0 / 3; //even two black but can take white only

    printf("%.9f\n", dfs(w, b));
    return 0;
}
