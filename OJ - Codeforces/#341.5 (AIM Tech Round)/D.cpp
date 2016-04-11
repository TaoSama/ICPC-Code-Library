//
//  Created by TaoSama on 2016-02-05
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, A, B;
int a[N];
long long f[N], g[N];

long long gao(int p) {
    int pos = -1;
    for(int i = 1; i <= n; ++i) {
        if(a[i] % p == 0) g[i] = g[i - 1];
        else if((a[i] + 1) % p == 0 || (a[i] - 1) % p == 0)
            g[i] = g[i - 1] + B;
        else break;
        pos = i;
    }
    for(int i = 1; i <= n; ++i) {
        f[i] = f[i - 1] + A;
        if(i <= pos) f[i] = min(f[i], g[i]);
    }
    g[n + 1] = 0;
    long long ret = f[n];
    for(int i = n; i; --i) {
        if(a[i] % p == 0) g[i] = g[i + 1];
        else if((a[i] + 1) % p == 0 || (a[i] - 1) % p == 0)
            g[i] = g[i + 1] + B;
        else break;
        ret = min(ret, f[i - 1] + g[i]);
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &A, &B) == 3) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        int leave[] = {a[1], a[n]};
        long long ans = 1e18;
        for(int i = 0; i < 2; ++i) {
            for(int d = -1; d <= 1; ++d) {
                int x = leave[i] + d;
                for(int j = 2; j * j <= x; ++j) {
                    if(x % j == 0) {
                        ans = min(ans, gao(j));
                        while(x % j == 0) x /= j;
                    }
                }
                if(x > 1) ans = min(ans, gao(x));
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
