//
//  Created by TaoSama on 2017-03-21
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k;
typedef long long LL;
LL f[N][10];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &k);
        for(int j = 0; j < k; ++j) f[0][j] = !j ? 0 : -1e18;
        for(int i = 0; i < n; ++i) {
            int x; scanf("%d", &x);
            for(int j = 0; j < k; ++j) f[i + 1][j] = -1e18;
            for(int j = 0; j < k; ++j) {
                f[i + 1][(j + 1) % k] = max(f[i + 1][(j + 1) % k], f[i][j] + x);
                f[i + 1][1 % k] = max(f[i + 1][1 % k], 0LL + x);
            }
        }
        LL ans = -1e18;
        for(int i = 1; i <= n; ++i) ans = max(ans, f[i][0]);
        printf("%lld\n", ans);
    }

    return 0;
}
