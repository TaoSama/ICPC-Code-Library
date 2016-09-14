//
//  Created by TaoSama on 2016-09-09
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

void fwtAnd(LL* a, int len) {
    if(len == 1) return;
    int h = len >> 1;
    fwtAnd(a, h);
    fwtAnd(a + h, h);
    for(int i = 0; i < h; ++i) {
        LL x1 = a[i];
        LL x2 = a[i + h];
        a[i] = (x1 + x2) % MOD;
        a[i + h] = x2 % MOD;
    }
}

void ifwtAnd(LL* a, int len) {
    if(len == 1) return;
    int h = len >> 1;
    for(int i = 0; i < h; ++i) {
        // y1=x1+x2
        // y2=x2
        LL y1 = a[i];
        LL y2 = a[i + h];
        a[i] = (y1 - y2 + MOD) % MOD;
        a[i + h] = y2 % MOD;
    }
    ifwtAnd(a, h);
    ifwtAnd(a + h, h);
}

int n;
const int C = 1 << 20;
LL cnt[C + 10], two[C + 10];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    two[0] = 1;
    for(int i = 1; i < C; ++i) two[i] = two[i - 1] * 2 % MOD;

    while(scanf("%d", &n) == 1) {
        memset(cnt, 0, sizeof cnt);
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            ++cnt[x];
        }

        fwtAnd(cnt, C);
        for(int i = 0; i < C; ++i) cnt[i] = two[cnt[i]];
        ifwtAnd(cnt, C);
        printf("%I64d\n", cnt[0]);
    }

    return 0;
}
