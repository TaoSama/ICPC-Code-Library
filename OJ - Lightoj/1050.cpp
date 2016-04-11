//
//  Created by TaoSama on 2015-11-20
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

int r, b;
double dp[505][505];

double dfs(int r, int b) {
    double &ret = dp[r][b];
    if(ret >= 0) return ret;
    if(r == 0) return ret = 1;
    if(b == 0) return ret = 0;
    int sum = r + b;
    ret = 1.0 * r / sum * dfs(r - 1, b - 1); //I take red
    if(b > 1) ret += 1.0 * b / sum * dfs(r, b - 2); //I take blue
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    fill(dp[0], dp[0] + 505 * 505, -1.0);
    while(t--) {
        scanf("%d%d", &r, &b);
        printf("Case %d: %.10f\n", ++kase, dfs(r, b));
    }
    return 0;
}
