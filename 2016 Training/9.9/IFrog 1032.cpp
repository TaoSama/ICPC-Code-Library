//
//  Created by TaoSama on 2016-09-11
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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
const int N = 500 + 10, INF = 0x3f3f3f3f, MOD = 998244353;

int n, m;
int f[N], sum[N];

inline int getSum(int l, int r) {
    int ret = sum[r] - (l ? sum[l - 1] : 0);
    if(ret < 0) ret += MOD;
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        int ans = 0;
        for(int x = 1; x <= n; ++x) {
            sum[0] = f[0] = 1;
            for(int i = 1; i <= n; ++i) sum[i] = sum[i - 1];
            for(int i = 1; i < m; ++i) {
                for(int j = 0; j <= n; ++j)
                    f[j] = getSum(j - x + 1, j);
                sum[0] = f[0];
                for(int j = 1; j <= n; ++j) {
                    sum[j] = sum[j - 1] + f[j];
                    if(sum[j] >= MOD) sum[j] -= MOD;
                }
            }
            ans += f[n - x];
            if(ans >= MOD) ans -= MOD;
        }
        ans = 1LL * ans * m % MOD;
        printf("%d\n", ans);
    }

    return 0;
}
