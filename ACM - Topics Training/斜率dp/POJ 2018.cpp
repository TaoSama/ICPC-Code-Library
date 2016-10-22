//
//  Created by TaoSama on 2016-05-11
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
#include <ctime>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int s[N], q[N];
//f[i] = max { (s[i]-s[j]) / (i - j) }

typedef long long LL;
LL up(int k, int j) {
    return s[j] - s[k];
}

LL dw(int k, int j) {
    return j - k;
}

LL cross(int k, int j, int i) {
    return up(k, j) * dw(j, i) - up(j, i) * dw(k, j);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", s + i);
            s[i] += s[i - 1];
        }
        LL ans = 0;
        int L = 0, R = 0;
        for(int i = m; i <= n; ++i) {
            //(j, i)在(k, j)右侧 删q[R-1]
            while(L + 1 < R && cross(q[R - 2], q[R - 1], i) >= 0) --R;
            q[R++] = i - m;
            //(j, i)在(k, j)左侧 删q[L]
            while(L + 1 < R && cross(q[L], q[L + 1], i) <= 0) ++L;
            int j = q[L];
//            printf("choose %d ans[%d] = %lld\n", j, i, 1000 * up(j, i) / dw(j, i));
            ans = max(ans, 1000 * up(j, i) / dw(j, i));
        }
        printf("%lld\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
