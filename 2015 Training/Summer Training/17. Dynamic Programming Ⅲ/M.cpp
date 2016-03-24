//
//  Created by TaoSama on 2015-08-13
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

int n, a[205];
int dp[205][205][205];
//dp[i][j][k]:= [i,j] + k same color blocks

// ????||||????||||
// i      q    p  j

int dfs(int l, int r, int k) {
    int &ret = dp[l][r][k];
    if(ret >= 0) return ret;
    if(l > r) return 0;

    ret = -INF;
    int p = r;
    //leftmost position that j's color extends to
    while(p >= l && a[p] == a[r]) --p;
    p++;
    int num = r - p + 1 + k;
    ret = max(ret, dfs(l, p - 1, 0) + num * num); //click it

    for(int q = l; q < p; ++q) { //remove [q+1, p-1] first & join
        if(a[q] == a[r] && a[q + 1] != a[r])
            ret = max(ret, dfs(q + 1, p - 1, 0) + dfs(l, q, num));
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
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);

        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n", ++kase, dfs(1, n, 0));
    }
    return 0;
}
