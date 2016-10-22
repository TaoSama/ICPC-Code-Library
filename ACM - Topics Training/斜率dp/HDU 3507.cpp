//
//  Created by TaoSama on 2016-05-10
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

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 5e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int s[N], q[N];
int f[N];

int up(int k, int j) {
    return (f[j] + s[j] * s[j]) - (f[k] + s[k] * s[k]);
}

int dw(int k, int j) {
    return 2 * (s[j] - s[k]);
}

bool check(int k, int j, int i) {
    return up(k, j) * dw(j, i) >= up(j, i) * dw(k, j);
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

        int L = 0, R = 0;
        q[R++] = f[0] = 0;
        for(int i = 1; i <= n; ++i) {
            while(L + 1 < R && up(q[L], q[L + 1]) <= s[i] * dw(q[L], q[L + 1])) ++L;
            int j = q[L];
            f[i] = f[j] + m + (s[i] - s[j]) * (s[i] - s[j]);
            while(L + 1 < R && check(q[R - 2], q[R - 1], i)) --R;
            q[R++] = i;
        }

        printf("%d\n", f[n]);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
