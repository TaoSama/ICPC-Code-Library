//
//  Created by TaoSama on 2015-12-14
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
const int N = 1e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

int n;
int bus[N], train[N];
LL dp[N];

inline int get(int p) {return max(0, p);}
inline void getMin(LL &x, LL y) {x = min(x, y);}

inline LL daily(int p) {
    LL x = bus[p] - bus[p - 1], y = train[p] - train[p - 1];
    return min(6LL, min(x + 2 * y, 3 + 2 * y));
}

inline LL weekly(int p) {
    int s = get(p - 7) + 1;
    LL trainCost = 0;
    for(int i = s; i <= p; ++i) {
        LL y = train[i] - train[i - 1];
        trainCost += min(6LL, 2 * y);
    }
    return min(36LL, 18 + trainCost);
}

inline LL monthly(int p) {
    int s = get(p - 30) + 1;
    LL dp[35]; memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for(int i = s; i <= p; ++i) {
        int cur = i - s + 1;
        LL y = train[i] - train[i - 1];
        getMin(dp[cur], dp[cur - 1] + min(6LL, 2 * y));
        getMin(dp[cur], dp[get(cur - 7)] + 36);
    }
    return min(90LL, 45 + dp[p - s + 1]);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d", bus + i, train + i);
            bus[i] += bus[i - 1];
            train[i] += train[i - 1];
        }

        memset(dp, 0x3f, sizeof dp);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i) {
            getMin(dp[i], dp[i - 1] + daily(i));
            getMin(dp[i], dp[get(i - 7)] + weekly(i));
            getMin(dp[i], dp[get(i - 30)] + monthly(i));
        }
        printf("%lld\n", dp[n]);
    }
    return 0;
}
