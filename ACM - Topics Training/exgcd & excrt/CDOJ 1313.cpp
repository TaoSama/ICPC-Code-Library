//
//  Created by TaoSama on 2016-04-19
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

LL n, s, t, a, b;

int main() {
    while(cin >> n >> s >> t >> a >> b) {
        if((t - s + b * n) % (a + b) == 0) {
            LL x = (t - s + b * n) / (a + b);
            LL y = n - x;
            if(x >= 0 && y >= 0) {
                for(int i = 1; i <= x; ++i) cout << 'O';
                for(int i = 1; i <= y; ++i) cout << 'X';
                cout << '\n';
                continue;
            }
        }

        LL x, y, g = exgcd(a, b, x, y);
        if(t % g) {
            cout << "CHEATED\n";
            continue;
        }
        x *= t / g; y *= t / g;
        LL delta = y / (a / g);
        LL ansx = 1e18, ansy = 1e18;
        for(LL i = delta - 1; i <= delta + 1; ++i) {
            LL tx = x + i * (b / g);
            LL ty = y - i * (a / g);
            if(!(tx >= 0 && ty <= 0)) continue;
            if(abs(tx) + abs(ty) < abs(ansx) + abs(ansy))
                ansx = tx, ansy = ty;
        }
        LL lft = n - abs(ansx) - abs(ansy);
        if(ansx >= 0 && ansy <= 0 && lft * b >= s) {
            for(int i = 1; i <= lft; ++i) cout << 'X';
            for(int i = 1; i <= ansx; ++i) cout << 'O';
            for(int i = 1; i <= -ansy; ++i) cout << 'X';
            cout << '\n';
        } else cout << "CHEATED\n";
    }
    return 0;
}
