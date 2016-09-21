//
//  Created by TaoSama on 2016-09-21
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

void fwtXor(LL* a, int len) {
    if(len == 1) return;
    int h = len >> 1;
    fwtXor(a, h);
    fwtXor(a + h, h);
    for(int i = 0; i < h; ++i) {
        LL x1 = a[i];
        LL x2 = a[i + h];
        a[i] = (x1 + x2);
        a[i + h] = (x1 - x2);
    }
}

void ifwtXor(LL* a, int len) {
    if(len == 1) return;
    int h = len >> 1;
    for(int i = 0; i < h; ++i) {
        // y1=x1+x2
        // y2=x1-x2
        LL y1 = a[i];
        LL y2 = a[i + h];
        a[i] = (y1 + y2) / 2;
        a[i + h] = (y1 - y2) / 2;
    }
    ifwtXor(a, h);
    ifwtXor(a + h, h);
}

const int C = 1 << 20;
int n, m, a[N];
char buf[N];
LL cnt[C], f[C];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%s", buf);
        for(int j = 0; j < m; ++j)
            a[j] |= (buf[j] - '0') << i;
    }
    for(int i = 0; i < m; ++i) ++cnt[a[i]];
    for(int i = 0; i < 1 << n; ++i) {
        int b = __builtin_popcount(i);
        f[i] = min(b, n - b);
    }
    fwtXor(cnt, 1 << n);
    fwtXor(f, 1 << n);
    for(int i = 0; i < C; ++i) f[i] *= cnt[i];
    ifwtXor(f, 1 << n);

    LL ans = INF;
    for(int i = 0; i < 1 << n; ++i) ans = min(ans, f[i]);
    printf("%I64d\n", ans);

    return 0;
}
