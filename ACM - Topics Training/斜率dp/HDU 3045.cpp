//
//  Created by TaoSama on 2016-05-13
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
const int N = 4e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, q[N];
typedef long long LL;
LL a[N], s[N], f[N];

//f[i] = { f[j]+s[i]-s[j]-(i-j)*a[j+1] }
//slope(k, j) = { (f[j]-s[j]+j*a[j+1]) - () } / (a[j+1]-a[k+1]) < i

LL up(int k, int j) {
    return (f[j] - s[j] + j * a[j + 1]) -
           (f[k] - s[k] + k * a[k + 1]);
}

LL dw(int k, int j) {
    return a[j + 1] - a[k + 1];
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
        for(int i = 1; i <= n; ++i) scanf("%I64d", a + i);
        sort(a + 1, a + 1 + n);
        for(int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];

        int L = 0, R = 0;
        q[R++] = 0;
        for(int i = 1; i <= n; ++i) {
            while(L + 1 < R && up(q[L], q[L + 1]) <= i * dw(q[L], q[L + 1])) ++L;
            int j = q[L];
            f[i] = f[j] + s[i] - s[j] - (i - j) * a[j + 1];
            if(i - m + 1 < m) continue;
            while(L + 1 < R && check(q[R - 2], q[R - 1], i - m + 1)) --R;
            q[R++] = i - m + 1;
        }
        printf("%I64d\n", f[n]);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
