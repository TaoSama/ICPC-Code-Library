//
//  Created by TaoSama on 2016-10-05
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

int digit[20];
typedef long long LL;
LL f[20][10][3][2];

LL dfs(int i, int s, int c, bool first, bool e) {
    if(!i) return 1;
    if(!e && ~f[i][s][c][first]) return f[i][s][c][first];

    LL ret = 0;
    int to = e ? digit[i] : 9;
    for(int d = 0; d <= to; ++d) {
        if(!first) {
            if(c == 1 && d < s) continue;
            if(c == 2 && d > s) continue;
            if(c == 0 && d != s) continue;
        }
        ret += dfs(i - 1, d, c, first && !d, e && d == to);
    }
    return e ? ret : f[i][s][c][first] = ret;
}

LL calc(LL x) {
//    prln(x);
    int cnt = 0;
    for(; x; x /= 10) digit[++cnt] = x % 10;
    LL up = dfs(cnt, 0, 1, 1, 1), dw = dfs(cnt, 0, 2, 1, 1);
    LL equ = dfs(cnt, 0, 0, 1, 1);
//    pr(up); pr(dw); prln(equ);
    return up + dw - equ;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);


//    prln(calc(100));

//    int up = 0, dw = 0, equ = 0;
//    for(int i = 0; i <= 200; ++i) {
//        char buf[100]; sprintf(buf, "%d", i);
//        int ok = 1;
//        for(int j = 0; buf[j + 1]; ++j)
//            if(buf[j] != buf[j + 1]) ok = 0;
//        equ += ok;
//        ok = 1;
//        for(int j = 0; buf[j + 1]; ++j)
//            if(buf[j] > buf[j + 1]) ok = 0;
//        up += ok;
//        ok = 1;
//        for(int j = 0; buf[j + 1]; ++j)
//            if(buf[j] < buf[j + 1]) ok = 0;
//        dw += ok;
//    }
//    printf("%d %d %d %d\n", up, dw, equ, up + dw - equ);

    memset(f, -1, sizeof f);
    int t; scanf("%d", &t);
    while(t--) {
        LL l, r; scanf("%lld%lld", &l, &r);
        printf("%lld\n", calc(r) - calc(l - 1));
    }

    return 0;
}
