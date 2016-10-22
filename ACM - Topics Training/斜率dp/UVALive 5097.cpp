//
//  Created by TaoSama on 2016-05-12
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
const int N = 5e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, q[N];
typedef long long LL;
LL f[105][N];
struct Rect {
    LL w, h;
    void read() {
        scanf("%lld%lld", &w, &h);
    }
    bool operator<(const Rect& r) const {
        return make_pair(w, h) > make_pair(r.w, r.h);
    }
} a[N];

//w↓ h↑

// f[j][i] = { f[j-1][k] + a[k+1].w*a[i].h } }
// slope(k, j) = (f[j] - f[k])/(a[k+1].w - a[j+1].w) < a[i].first

LL up(int p, int k, int j) {
    return f[p][j] - f[p][k];
}
LL dw(int k, int j) {
    return a[k + 1].w - a[j + 1].w;
}

bool check(int p, int k, int j, int i) {
    return up(p, k, j) * dw(j, i) >= up(p, j, i) * dw(k, j);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= n; ++i) a[i].read();
        sort(a + 1, a + 1 + n);

        int cnt = 1;
        for(int i = 2; i <= n; ++i)
            if(a[i].h > a[cnt].h) a[++cnt] = a[i];

        for(int i = 1; i <= n; ++i) f[1][i] = a[1].w * a[i].h;

        LL ans = f[1][n];
        for(int j = 2; j <= m; ++j) {
            int L = 0, R = 0;
            q[R++] = 0;
            for(int i = 1; i <= n; ++i) {
                while(L + 1 < R && up(j - 1, q[L], q[L + 1]) <=
                        a[i].h * dw(q[L], q[L + 1])) ++L;
                int k = q[L];
//                printf("%d: %d %d\n", j, i, k);
                f[j][i] = f[j - 1][k] + a[k + 1].w * a[i].h;
//                printf("f[%d][%d] = %lld\n", j, i, f[j][i]);
                while(L + 1 < R && check(j - 1, q[R - 2], q[R - 1], i)) --R;
                q[R++] = i;
            }
            ans = min(ans, f[j][n]);
        }
        printf("%lld\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
