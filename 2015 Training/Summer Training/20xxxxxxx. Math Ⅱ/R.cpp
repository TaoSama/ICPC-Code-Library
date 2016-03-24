//
//  Created by TaoSama on 2015-08-15
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

long long f[N];

void gao() {
    f[1] = 1;
    for(int i = 2; i <= 1000; ++i) {
        for(int j = 1; j < i; ++j)
            if((i - 1) % j == 0)
                f[i] = (f[i] + f[j]) % MOD;
    }
}

int n;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    gao();
    while(scanf("%d", &n) == 1) {
        printf("Case %d: %lld\n", ++kase, f[n]);
    }
    return 0;
}
