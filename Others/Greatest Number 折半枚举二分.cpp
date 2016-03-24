//
//
//
//  Created by TaoSama on 2015-02-06
//  Copyright (c) 2014 TaoSama. All rights reserved.
//
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
#define CLR(x) memset(x, 0, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, m, ans, a[1005], b[1000 * 1000 + 5];


int main() {
#ifdef LOCAL
    freopen("ACM_in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(~scanf("%d%d", &n, &m) && (n + m)) {
        for(int i = 0; i < n; ++i) scanf("%d", a + i);

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                b[i * n + j] = a[i] + a[j];
        sort(b, b + n * n);

        ans = - INF;
        for(int i = 0; i < n * n && b[i] <= m; ++i) {
            int idx = upper_bound(b, b + n * n, m - b[i]) - b - 1;
            ans = max(ans, b[i] + b[idx]);
        }

        printf("Case %d: %d\n\n", ++kase, ans);
    }
    return 0;
}
