//
//  Created by TaoSama on 2015-11-26
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

typedef long long LL;

int n, x;
LL dp[30][200];

void init() {
    for(int i = 1; i <= 6; ++i) dp[1][i] = 1;
    for(int i = 2; i <= 25; ++i)
        for(int j = i; j <= 6 * i; ++j)
            for(int k = 1; k <= 6; ++k)
                if(j >= k) dp[i][j] += dp[i - 1][j - k];
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    init();
    while(t--) {
        scanf("%d%d", &n, &x);
        LL up = 0, down = 0;
        for(int i = n; i <= 6 * n; ++i) {
            if(i >= x) up += dp[n][i];
            down += dp[n][i];
        }
        LL gcd = __gcd(up, down);
        up /= gcd; down /= gcd;
        printf("Case %d: ", ++kase);
        if(!up) puts("0");
        else if(up == down) puts("1");
        else printf("%lld/%lld\n", up, down);
    }
    return 0;
}
