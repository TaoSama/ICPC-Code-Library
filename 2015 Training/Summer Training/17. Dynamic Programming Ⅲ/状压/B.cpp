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

int n, m;
long long dp[1 << 16], sum[16][16], cnt[16];
//sum[i][j]:= put all the j to the front of all the i.

long long dfs(int s) {
    long long &ret = dp[s];
    if(ret >= 0) return ret;
    if(s == (1 << m) - 1) return 0;

    ret = 0x3f3f3f3f3f3f3f3fLL;
    for(int i = 0; i < m; ++i) { //put them in order
        if(s >> i & 1) continue;
        long long cost = 0;
        for(int j = 0; j < m; ++j) {
            if(s >> j & 1) continue;
            cost += sum[i][j];
        }
        ret = min(ret, dfs(s | 1 << i) + cost);
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
        scanf("%d%d", &n, &m);

        memset(cnt, 0, sizeof cnt);
        memset(sum, 0, sizeof sum);
        for(int i = 0; i < n; ++i) {
            int x; scanf("%d", &x); --x;
            for(int j = 0; j < m; ++j) {
                if(j == x) continue;
                sum[j][x] += cnt[j];
            }
            cnt[x]++;
        }

        memset(dp, -1, sizeof dp);
        printf("Case %d: %lld\n", ++kase, dfs(0));
    }
    return 0;
}
