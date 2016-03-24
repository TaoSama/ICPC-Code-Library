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
long long f[2][3]; //0->removed array, not started, 1->removing, 2->finished

inline void getMin(long long &x, long long y) {
    if(x > y) x = y;
}

int getCost(int i, int p) {
    if(a[i] % p == 0) return 0;
    else if((a[i] + 1) % p == 0 || (a[i] - 1) % p == 0) return B;
    return INF;
}

void see(int i, int s) {
    for(int j = 0; j < 3; ++j)
        printf("f[%d][%d]=%I64d\n", i, j, f[s][j]);
}

long long gao(int p) {
    int s = 0;
    memset(f[s], 0, sizeof f[s]);
    for(int i = 1; i <= n; ++i) {
        memset(f[!s], 0x3f, sizeof f[!s]);
        int cost = getCost(i, p);
        if(cost != INF) {
            getMin(f[!s][0], f[s][0] + cost);
            getMin(f[!s][2], f[s][2] + cost);
        }
        getMin(f[!s][1], f[s][0] + A); //start removing
        getMin(f[!s][1], f[s][1] + A); //removing
        getMin(f[!s][2], f[s][0] + A); //finish right away
        getMin(f[!s][2], f[s][1] + A); //finish removing
        s = !s;
//      if(p == 2) see(i, s);
    }
    return min(f[s][0], f[s][2]);
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
        //        return 0;
    }
    return 0;
}
