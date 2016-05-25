//
//  Created by TaoSama on 2016-05-14
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 9973;

int n;
char s[N];
int pre[N];

int ksm(int x, int n) {
    int ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%s", &n, s + 1) == 2) {
        int m = strlen(s + 1);
        pre[0] = 1;
        for(int i = 1; i <= m; ++i)
            pre[i] = pre[i - 1] * (s[i] - 28 + MOD) % MOD;
        for(int i = 1; i <= n; ++i) {
            int a, b; scanf("%d%d", &a, &b);
            int ans = pre[b] * ksm(pre[a - 1], MOD - 2) % MOD;
            printf("%d\n", ans);
        }
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
