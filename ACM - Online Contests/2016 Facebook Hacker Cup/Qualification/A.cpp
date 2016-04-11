//
//  Created by TaoSama on 2016-01-10
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int N = 2e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int x[N], y[N], d[N][N];

int get(int i, int j) {
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

int main() {
    freopen("boomerang_constellations.txt", "r", stdin);
    freopen("boomerang_constellations_out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d%d", x + i, y + i);
        for(int i = 1; i <= n; ++i)
            for(int j = i; j <= n; ++j)
                d[i][j] = d[j][i] = get(i, j);

        long long ans = 0;
        for(int i = 1; i <= n; ++i) {
            sort(d[i] + 1, d[i] + 1 + n);
            for(int j = 1; j <= n; ++j) {
                int last = d[i][j], cnt = 1;
                while(j + 1 <= n && d[i][j + 1] == last) ++cnt, ++j;
//                printf("%d: %d cnt: %d last: %d\n", i, j, cnt, last);
                ans += cnt * (cnt - 1) >> 1;
            }
        }

        static int kase = 0;
        printf("Case #%d: %lld\n", ++kase, ans);
    }
    return 0;
}
