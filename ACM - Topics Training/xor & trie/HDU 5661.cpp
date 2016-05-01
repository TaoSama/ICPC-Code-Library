//
//  Created by TaoSama on 2016-04-25
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
LL a, b, c, d;

bool ok(LL x, LL y, int i) {
    LL lft = (1LL << i) - 1;
    LL xr = x + lft, yr = y + lft;
    if(x > b || xr < a) return false;
    if(y > d || yr < c) return false;
    return true;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%I64d%I64d%I64d%I64d", &a, &b, &c, &d);
        LL x = 0, y = 0;
        for(int i = 62; ~i; --i) {
            LL delta = 1LL << i;
            if(ok(x + delta, y, i)) x += delta;
            else if(ok(x, y + delta, i)) y += delta;
            else if(ok(x + delta, y + delta, i)) {
                x += delta;
                y += delta;
            }
        }
        printf("%I64d\n", x ^ y);
    }
    return 0;
}
