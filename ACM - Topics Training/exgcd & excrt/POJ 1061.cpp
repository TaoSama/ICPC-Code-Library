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
LL x0, y0, vx, vy, L;

LL exgcd(LL a, LL b, LL& x, LL& y) {
    LL d = a;
    if(!b) x = 1, y = 0;
    else {
        d = exgcd(b, a % b, y, x);
        y -= a / b * x;
    }
    return d;
}

// x0 + vx * x = y0 + vy * x mod L
// (vx - vy) * x = y0 - x0 + Ly
// (vx - vy) * x - Ly = y0 - x0
// (vx - vy) * x + Ly = y0 - x0
// solve the minimum positive x

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> x0 >> y0 >> vx >> vy >> L) {
        LL a = vx - vy, b = L, c = y0 - x0;
        LL x, y;
        LL d = exgcd(a, b, x, y);
        if(c % d) {
            puts("Impossible");
            continue;
        }
        x *= c / d;
        x = (x % L + L) % L;
        cout << x << '\n';
    }
    return 0;
}
