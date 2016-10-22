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
const int N = 100 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int s[N], b[N];
//f[i] = min{ f[j] + (s[i]-s[j]+10)*b[i] }
// slope(k, j) = (f[j]-f[k])/(s[j]-s[k]) < b[i];

int f[N], q[N];

int up(int k, int j) {
    return f[j] - f[k];
}
int dw(int k, int j) {
    return s[j] - s[k];
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

    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d", s + i, b + i);
            s[i] += s[i - 1];
        }

        int L = 0, R = 0;
        q[R++] = 0;
        for(int i = 1; i <= n; ++i) {
            while(L + 1 < R && up(q[L], q[L + 1]) <= b[i] * dw(q[L], q[L + 1])) ++L;
            int j = q[L];
            f[i] = f[j] + (s[i] - s[j] + 10) * b[i];
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
