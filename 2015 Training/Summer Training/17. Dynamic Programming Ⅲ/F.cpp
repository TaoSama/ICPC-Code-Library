//
//  Created by TaoSama on 2015-08-12
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
#include <cassert>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

char s[1010], t[1010];
int n, dp[1010][10][10];
//dp[i][j][k]:= 0~i digits j->i-th k->(i+1)-th

int dfs(int d, int d1, int d2) {
    int &ret = dp[d][d1][d2];
    if(ret >= 0) return ret;
    if(d == n) return 0;
    assert(d < n);

    ret = INF;
    int up = (t[d] - d1 + 10) % 10; //d1 turn rightly at once
    for(int i = 0; i <= up; ++i)
        for(int j = 0; j <= i; ++j) //move one step & last digit turn less
            ret = min(ret, dfs(d + 1, (d2 + i) % 10, (s[d + 2] + j) % 10) + up);

    int down = (d1 - t[d] + 10) % 10;
    for(int i = 0; i <= down; ++i)
        for(int j = 0; j <= i; ++j)
            ret = min(ret, dfs(d + 1, (d2 - i + 10) % 10, (s[d + 2] - j + 10) % 10) + down);
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s%s", s, t) == 2) {
        n = strlen(s);
        for(int i = 0; i < n; ++i) s[i] -= '0';
        for(int i = 0; i < n; ++i) t[i] -= '0';

        memset(dp, -1, sizeof dp);
        printf("%d\n", dfs(0, s[0], s[1]));
    }
    return 0;
}
