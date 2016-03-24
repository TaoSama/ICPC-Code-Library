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

int n, a[16][16];
int dp[1 << 16];

//i-th boy s:= paired girls' set
int dfs(int i, int s) {
    int &ret = dp[s];
    if(ret >= 0) return ret;
    if(i == n) return 0;

    for(int j = 0; j < n; ++j) { //choose girl
        if(s >> j & 1) continue;
        ret = max(ret, dfs(i + 1, s | 1 << j) + a[i][j]);
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                scanf("%d", &a[i][j]);

        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n", ++kase, dfs(0, 0));
    }
    return 0;
}
