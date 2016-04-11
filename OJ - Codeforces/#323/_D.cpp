//
//  Created by TaoSama on 2015-10-04
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

int n, T, a[N], g[N];
int cnt[305];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &T) == 2) {
        memset(cnt, 0, sizeof cnt);
        int maxv = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            maxv = max(maxv, ++cnt[a[i]]);
        }
        int t = min(T, n);
        for(int i = 1; i < t; ++i)
            for(int j = 1; j <= n; ++j)
                a[j + i * n] = a[j];

        memset(g, 0x3f, sizeof g);
        int ans = 0;
        for(int i = 1; i <= n * t; ++i) {
            int k = upper_bound(g + 1, g + n * t + 1, a[i]) - g;
            ans = max(ans, k);
            g[k] = a[i];
        }

        ans += maxv * (T - t);
        printf("%d\n", ans);
    }
    return 0;
}
