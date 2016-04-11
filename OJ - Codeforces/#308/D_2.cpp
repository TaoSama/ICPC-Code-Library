//
//  Created by TaoSama on 2015-06-19
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, x[2005], y[2005], a[405][405];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d%d", x + i, y + i);

        int ans = 1LL * n * (n - 1) * (n - 2) / 6;
        for(int i = 1; i <= n; ++i) {
            memset(a, 0, sizeof a);
            for(int j = i + 1; j <= n; ++j) {
                int tx = x[i] - x[j], ty = y[i] - y[j];
                int g = __gcd(tx, ty);
                tx = tx / g + 200; ty = ty / g + 200;
                ans -= a[tx][ty];
                a[tx][ty]++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
