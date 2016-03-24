//
//  Created by TaoSama on 2015-08-13
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

int n, L, C;
int a[1005], sum[1005], f[1005], g[1005];

int get(int x) {
    if(x == 0) return 0;
    else if(x >= 1 && x <= 10) return -C;
    else return (x - 10) * (x - 10);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d", &n) == 1 && n) {
        scanf("%d%d", &L, &C);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            sum[i] = sum[i - 1] + a[i];
        }

        memset(f, 0x3f, sizeof f);
        memset(g, 0x3f, sizeof g);
        f[0] = g[0] = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(L >= sum[i] - sum[j]) {
                    if(f[i] > f[j] + 1) {
                        f[i] = f[j] + 1;
                        g[i] = g[j] + get(L - sum[i] + sum[j]);
                    } else if(f[i] == f[j] + 1)
                        if(g[i] > g[j] + get(L - sum[i] + sum[j]))
                            g[i] = g[j] + get(L - sum[i] + sum[j]);
                }
            }
        }

        if(kase) puts("");
        printf("Case %d:\n", ++kase);
        printf("Minimum number of lectures: %d\n", f[n]);
        printf("Total dissatisfaction index: %d\n", g[n]);
    }
    return 0;
}
