//
//  Created by TaoSama on 2015-10-07
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
const int N = 5e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

int n, a[N], _and[N], _or[N], _xor[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        double ans1 = 0, ans2 = 0, ans3 = 0;
        for(int i = 0; i < 31; ++i) {
            int mul = 1 << i;
            for(int j = 1; j <= n; ++j) {
                if(a[j] & mul) {
                    _and[j] = _and[j - 1] + 1;
                    _or[j] = j;
                    _xor[j] = j - _xor[j - 1];
                } else {
                    _and[j] = 0;
                    _or[j] = _or[j - 1];
                    _xor[j] = _xor[j - 1];
                }
                ans1 += 1.0 * _and[j] * mul;
                ans2 += 1.0 * _or[j] * mul;
                ans3 += 1.0 * _xor[j] * mul;
            }
        }
        double tot = 1.0 * (n + 1) * n / 2;
        printf("Case #%d: %.6f %.6f %.6f\n", ++kase,
               ans1 / tot, ans2 / tot, ans3 / tot);
    }
    return 0;
}
