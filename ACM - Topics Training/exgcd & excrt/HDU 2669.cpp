//
//  Created by TaoSama on 2016-04-13
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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

typedef long long LL;
LL a, b;
LL exgcd(LL a, LL b, LL& x, LL& y) {
    LL d = a;
    if(!b) x = 1, y = 0;
    else {
        d = exgcd(b, a % b, y, x);
        y -= a / b * x;
    }
    return d;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%I64d%I64d", &a, &b) == 2) {
        LL x, y;
        LL d = exgcd(a, b, x, y);
        if(d != 1) {
            puts("sorry");
            continue;
        }
        if(x > 0) {
            LL delta = x / b;
            x -= delta * b;
            y += delta * a;
        }
        if(x < 0) {
            LL delta = (-x + b - 1) / b;
            x += delta * b;
            y -= delta * a;
        }
        printf("%I64d %I64d\n", x, y);
    }
    return 0;
}
