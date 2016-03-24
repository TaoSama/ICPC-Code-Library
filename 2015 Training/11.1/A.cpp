//
//  Created by TaoSama on 2015-11-04
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

/*
 3:   0   0 0*1
 4:   1   1 1*1
 5:   3   2 1*2
 6:   7   4 2*2
 7:  13   6 2*3
 8:  22   9 3*3
 9:  34  12
10:  50  16
11:  70  20
12:  95  25
13: 125  30
14: 161  36
15: 203  42
*/

typedef long long LL;
LL n, dp[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    for(LL i = 4; i <= 1e6; ++i)
        if(i & 1) dp[i] = dp[i - 1] + (i / 2 - 1) * (i / 2);
        else dp[i] = dp[i - 1] + (i / 2 - 1) * (i / 2 - 1);
    while(scanf("%lld", &n) == 1 && n > 2) {
        printf("%lld\n", dp[n]);
    }
    return 0;
}
