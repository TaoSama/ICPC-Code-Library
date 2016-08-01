//
//  Created by TaoSama on 2016-07-19
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];
int f[N][3];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d", &n) == 1) {
        memset(f, 0xc0, sizeof f);
        f[0][0] = 0;
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            for(int j = 0; j < 3; ++j) //rest
                f[i][0] = max(f[i][0], f[i - 1][j]);
            if(x >= 2) { //gym
                f[i][1] = max(f[i][1], f[i - 1][0] + 1);
                f[i][1] = max(f[i][1], f[i - 1][2] + 1);
            }
            if(x == 1 || x == 3) { //contest
                f[i][2] = max(f[i][2], f[i - 1][0] + 1);
                f[i][2] = max(f[i][2], f[i - 1][1] + 1);
            }
        }
        int ans = -INF;
        for(int i = 0; i < 3; ++i) ans = max(ans, f[n][i]);
        printf("%d\n", n - ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
