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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 10056;

int c[1005][1005], f[1005];
void gao() {
    for(int i = 0; i <= 1000; ++i) {
        c[i][0] = 1;
        for(int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
    }

    f[0] = 1; f[1] = 1; f[2] = 3;
    for(int i = 3; i <= 1000; ++i) {
        for(int j = 1; j <= i; ++j)
            f[i] = (f[i] + c[i][j] * f[i - j] % MOD) % MOD;
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    gao();
    while(t--) {
        int n; scanf("%d", &n);
        printf("Case %d: %d\n", ++kase, f[n]);
    }
    return 0;
}
