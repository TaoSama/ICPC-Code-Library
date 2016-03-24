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

int phi[2005];
void gao() {
    phi[1] = 1;
    for(int i = 2; i <= 2000; ++i) {
        if(phi[i]) continue;
        for(int j = i; j <= 2000; j += i) {
            if(!phi[j]) phi[j] = j;
            phi[j] = phi[j] / i * (i - 1);
        }
    }
}

long long a, b;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
//  ios_base::sync_with_stdio(0);

    gao();
    //gcd(j, i) = gcd(j + i, i) = gcd(j + x*i, i)
    while(scanf("%lld%lld", &a, &b) == 2 && (a || b)) {
        long long ans = 0;
        for(int i = 1; i <= a; ++i) {
            ans += b / i * phi[i];
            int  to = b % i;
            for(int j = 1; j <= to; ++j)
                ans += __gcd(j, i) == 1;
        }
        printf("%.7f\n", 1.0 * (4 * ans + 4) / ((2 * a + 1) * (2 * b + 1) - 1));
    }
    return 0;
}
