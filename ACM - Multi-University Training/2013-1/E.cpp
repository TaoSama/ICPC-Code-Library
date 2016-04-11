//
//  Created by TaoSama on 2016-02-26
//  Copyright (c) 2016 TaoSama. All rights reserved.
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];
int f[2][N], h[N];
//start from i, 0 for longest non-increasing, 1 for non-decreasing
int same[2][N]; //start from i, in LIS sequence, same as a[i]

void gao(int *f, int *same) {
    memset(h, 0x3f, sizeof h);
    for(int i = n; i; --i) {
        f[i] = upper_bound(h + 1, h + 1 + n, a[i]) - h;
        h[f[i]] = a[i];
        auto range = equal_range(h + 1, h + 1 + n, a[i]);
        same[i] = range.second - range.first;
    }
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
        for(int i = 1; i <= n; ++i)  scanf("%d", a + i);

        gao(f[0], same[0]);
        for(int i = 1; i <= n; ++i) a[i] = -a[i];
        gao(f[1], same[1]);

        int ans = 0;
        for(int i = 1; i <= n; ++i)
            ans = max(ans, f[0][i] + f[1][i] - min(same[0][i], same[1][i]));

        printf("%d\n", ans);
    }
    return 0;
}
