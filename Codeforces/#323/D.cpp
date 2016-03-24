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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, T, a[N], f[N], g[N], h[N], cnt[305];
//f: end i g: start i

int r[N];
bool cmp(int x, int y) {
    return a[x] > a[y];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &T) == 2) {
        memset(cnt, 0, sizeof cnt);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            ++cnt[a[i]];
        }
        int t = min(T, n << 1);
        for(int i = 1; i < t; ++i)
            for(int j = 1; j <= n; ++j)
                a[j + i * n] = a[j];

        int ans = 0;
        if(T <= n << 1) {
            memset(h, 0x3f, sizeof h);
            for(int i = 1; i <= n * t; ++i) {
                int k = upper_bound(h + 1, h + n * t + 1, a[i]) - h;
                ans = max(ans, k);
                h[k] = a[i];
            }
        } else {
            memset(h, 0x3f, sizeof h);
            for(int i = 1; i <= n * n; ++i) {
                int k = upper_bound(h + 1, h + n * n + 1, a[i]) - h;
                f[i] = k;
                h[k] = a[i];
            }

            memset(h, 0x3f, sizeof h);
            for(int i = n * n; i; --i) {
                int k = upper_bound(h + 1, h + n * n + 1, -a[i]) - h;
                g[i] = k;
                h[k] = -a[i];
            }

            for(int i = 1; i <= n * n; ++i) r[i] = i;
            sort(r + 1, r + n * n + 1, cmp);
            set<int> s;
            for(int i = 1, j = 1; i <= n * n; ++i) {
                int x = r[i];
                while(j <= n * n && a[r[j]] >= a[r[i]]) s.insert(g[r[j++]]);
                int tmp = f[x] + (T - 2 * n) * cnt[a[x]] + (*s.rbegin());
                ans = max(ans, tmp);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
