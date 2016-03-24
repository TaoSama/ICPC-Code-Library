//
//  Created by TaoSama on 2015-08-14
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

typedef unsigned long long ull;
ull a, b, n;
int f[N];

ull ksm(ull x, ull n, ull mod) {
    ull ret = 1;
    while(n) {
        if(n & 1) ret = ret * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%llu%llu%llu", &a, &b, &n);
        if(n == 1) {puts("0"); continue;}

        f[1] = 1 % n, f[2] = 1 % n;
        ull cycle;
        for(int i = 3; i <= n * n; ++i) {
            f[i] = (f[i - 1] + f[i - 2]) % n;
            if(f[i - 1] == f[0] && f[i] == f[1]) {
                cycle = i - 1;
                break;
            }
        }
//      printf("cycle = %d\n", cycle);
        int x = ksm(a % cycle, b, cycle);
        printf("%d\n", f[x]);
    }
    return 0;
}
