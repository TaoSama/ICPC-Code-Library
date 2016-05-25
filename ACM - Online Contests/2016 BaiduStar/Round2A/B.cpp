//
//  Created by TaoSama on 2016-05-21
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
const int N = 16, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N], b[N], p[N];
typedef long long LL;
LL f[1 << N][N];

void getMax(LL& x, LL y) {
    if(x < y) x = y;
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
        scanf("%d", &n);
        memset(b, -1, sizeof b);
        for(int i = 0; i < n; ++i) {
            scanf("%d%d", a + i, p + i);
            if(~p[i]) b[p[i]] = i;
        }
        memset(f, 0xc0, sizeof f);
        //放了哪些数 最后一个数是谁
        if(b[0] != -1) f[1 << b[0]][b[0]] = 0;
        else {
            for(int i = 0; i < n; ++i)
                if(p[i] == -1) f[1 << i][i] = 0;
        }
        for(int i = 1; i < 1 << n; ++i) {
            int s = 0;
            for(int j = 0; j < n; ++j) if(i >> j & 1) ++s;

            if(b[s] != -1) { //这个位置限定了
                if(i >> b[s] & 1) continue;
                if(b[s - 1] != -1) //前面那个
                    getMax(f[i | 1 << b[s]][b[s]], f[i][b[s - 1]] + a[b[s - 1]] * a[b[s]]);
                else {
                    for(int j = 0; j < n; ++j)
                        if((i >> j & 1) && p[j] == -1)
                            getMax(f[i | 1 << b[s]][b[s]], f[i][j] + a[j] * a[b[s]]);
                }
            } else {
                for(int j = 0; j < n; ++j) {
                    if(!(i >> j & 1) && p[j] == -1) {
                        if(b[s - 1] != -1) {
                            getMax(f[i | 1 << j][j], f[i][b[s - 1]] + a[b[s - 1]] * a[j]);
                        } else {
                            for(int k = 0; k < n; ++k)
                                if((i >> k & 1) && p[k] == -1)
                                    getMax(f[i | 1 << j][j], f[i][k] + a[k] * a[j]);
                        }
                    }
                }
            }
        }


        long long ans = -1e18;
        if(b[n - 1] != -1) ans = f[(1 << n) - 1][b[n - 1]];
        else {
            for(int i = 0; i < n; ++i) getMax(ans, f[(1 << n) - 1][i]);
        }
        static int kase = 0;
        printf("Case #%d:\n", ++kase);
        printf("%I64d\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
