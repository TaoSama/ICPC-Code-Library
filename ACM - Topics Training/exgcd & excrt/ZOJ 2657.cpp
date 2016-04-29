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

LL sx, sy, vx, vy, L;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> sx >> sy >> vx >> vy >> L) {
        //sx + vx*x = sy + vy*x + Ly
        //(vx-vy)x + Ly = sy-sx

        LL a = vx - vy, b = L, c = sy - sx;
        LL x, y, g = exgcd(a, b, x, y);
        if(c % g) {
            cout << "Pat\n";
            continue;
        }
        x *= c / g;
        x = (x % b + b) % (b / g);
        cout << x << '\n';
    }
    return 0;
}