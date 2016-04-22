//
//  Created by TaoSama on 2016-04-17
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

LL A, B, a, b;

LL exgcd(LL a, LL b, LL& x, LL& y) {
    LL g = a;
    if(!b) x = 1, y = 0;
    else {
        g = exgcd(b, a % b, y, x);
        y -= a / b * x;
    }
    return g;
}

LL solve(LL a, LL b, LL c) {
    if(a < b) swap(a, b);
    LL x, y, g = exgcd(a, b, x, y);
    if(c % g) return -1;

    x *= c / g; y *= c / g;
    LL delta = y / (a / g), ret = 1e18;
    for(LL i = delta - 1; i <= delta + 1; ++i) {
        LL tx = x + i * (b / g);
        LL ty = y - i * (a / g);
        ret = min(ret, abs(tx) + abs(ty));
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> A >> B >> a >> b;
        LL c = abs(A - B);
        LL ans = solve(a, b, c);
        ans = min(ans, solve(a, a + b, c));
        ans = min(ans, solve(b, a + b, c));
        cout << ans << '\n';
    }
    return 0;
}
