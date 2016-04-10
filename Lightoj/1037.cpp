//
//  Created by TaoSama on 2015-11-13
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

int n, a[15], dp[1 << 15];
char b[15][15];

int dfs(int s) {
    int& ret = dp[s];
    if(!s) return 0;
    if(~ret) return ret;
    ret = INF;
    for(int i = 0; i < n; ++i) {
        if(s >> i & 1) {
            int maxv = 1;
            for(int j = 0; j < n; ++j)
                maxv = max(maxv, s >> j & 1 ? 0 : b[j][i] - '0');
            ret = min(ret, dfs(s ^ (1 << i)) + (a[i] + maxv - 1) / maxv);
        }
    }
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
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) scanf("%d", a + i);
        for(int i = 0; i < n; ++i) scanf("%s", b[i]);
        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n", ++kase, dfs((1 << n) - 1));
    }
    return 0;
}
