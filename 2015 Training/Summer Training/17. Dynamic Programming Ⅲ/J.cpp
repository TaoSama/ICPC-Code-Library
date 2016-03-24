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

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k;
struct P {
    int x, y;
    bool operator < (const P& rhs) const {
        return y * rhs.x > x * rhs.y; //height is wrong
    }
} a[55];
int dp[55][2505];
//dp[i][j]:= choose i vectors, cur max height is j

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; ++i) scanf("%d%d", &a[i].x, &a[i].y);
        sort(a + 1, a + 1 + n);

        memset(dp, 0xc0, sizeof dp);
        dp[0][0] = 0;
        for(int i = 1; i <= n; ++i) { //both reversing order!!
            for(int j = k; j >= 1; --j) {
                for(int z = 2500; z >= a[i].y; --z)
                    dp[j][z] = max(dp[j][z], dp[j - 1][z - a[i].y] +
                                   (2 * z - a[i].y) * a[i].x);
            }
        }
        int ans = *max_element(dp[k], dp[k] + 2501);
        printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}
