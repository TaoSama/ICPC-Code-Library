//
//  Created by TaoSama on 2015-08-13
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

int n, a[N];
int f[N], g[N], t[N];

void print(int *f) {
    for(int i = 1; i <= n; ++i) printf("%d ", a[i]); printf("\n");
    for(int i = 1; i <= n; ++i) printf("%d ", f[i]); printf("\n");
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);

        memset(f, 0, sizeof f);
        memset(t, 0x3f, sizeof t);
        for(int i = 1; i <= n; ++i) {
            int k = lower_bound(t + 1, t + 1 + n, a[i]) - t;
            f[i] = k;
            t[k] = a[i];
        }
//        print(f);

        reverse(a + 1, a + 1 + n);
        memset(g, 0, sizeof g);
        memset(t, 0x3f, sizeof t);
        for(int i = 1; i <= n; ++i) {
            int k = lower_bound(t + 1, t + 1 + n, a[i]) - t;
            g[i] = k;
            t[k] = a[i];
        }
        reverse(g + 1, g + 1 + n);
//      reverse(a + 1, a + 1 + n);
//      print(g);

        int ans = -INF;
        for(int i = 1; i <= n; ++i) ans = max(ans, 2 * min(f[i], g[i]) - 1);
        printf("%d\n", ans);
    }
    return 0;
}
