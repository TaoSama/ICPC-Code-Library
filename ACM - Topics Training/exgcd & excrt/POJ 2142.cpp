//
//  Created by TaoSama on 2016-04-18
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

LL exgcd(LL a, LL b, LL& x, LL& y) {
    LL g = a;
    if(!b) x = 1, y = 0;
    else {
        g = exgcd(b, a % b, y, x);
        y -= a / b * x;
    }
    return g;
}

LL a, b, c;
template<typename T>
T abs(const T& x) {
    if(x < 0) return -x;
    return x;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> a >> b >> c && (a || b || c)) {
        bool flip = false;
        if(a < b) swap(a, b), flip = true;

        LL x, y, g = exgcd(a, b, x, y);
        x *= c / g;  y *= c / g;
        LL delta = y / (a / g);

        LL ansx = 1e18, ansy = 1e18;
        for(LL i = delta - 1; i <= delta + 1; ++i) {
            LL tx = abs(x + i * (b / g));
            LL ty = abs(y - i * (a / g));
            if(tx + ty < ansx + ansy || tx + ty == ansx + ansy &&
                    a * tx + b * ty < a * ansx + b * ansy)
                ansx = tx, ansy = ty;
        }

        if(!flip) cout << ansx << ' ' << ansy << '\n';
        else cout << ansy << ' ' << ansx << '\n';
    }
    return 0;
}

/*
assuming a > b
x = x0 + b/g*t, y = y0 - a/g*t
z = |x| + |y| = |x0 + b/g*t| + |y0 - a/g*t|
let k1 = b/g, k2 = a/g, z = |x0 + k1*t| + |y0 + k2*t|
k1 > 0, k2 > 0, k1 < k2

conclude from ax + by = c, a > 0, b > 0, c > 0:
1. x < 0, y > 0
==> t < -x0/k1, t < y0/k2 ,  z = -(k1+k2)t - x0 + y0 ↓
2. x > 0, y > 0
==> -x0/k1 < t < y0/k2    ,  z = (k1-k2)t + x0 + y0  ↓
3. x > 0, y < 0
==> t > -x0/k1, t > y0/k2 ,  z = (k1+k2)t + x0 - y0  ↑

minimum value in 2, check t = y0/k2 = y0/(a/g)
because of integer, check around
*/
