//
//  Created by TaoSama on 2017-01-19
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

int n, l, r;

typedef long long LL;

LL quick(LL x, LL n) {
    LL ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x;
        x = x * x;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> l >> r) {
        LL len = r - l + 1;
        if(n == 1) cout << len << endl;
        else if(n == 2) cout << len * (len - 1) << endl;
        else if(n > 30) cout << 0 << endl;
        else {
            LL ans = 0;
            for(int p = 1; ; ++p) {
                LL tp = quick(p, n - 1);
                if(tp > r) break;
                for(int q = p + 1; ; ++q) {
                    LL tq = quick(q, n - 1);
                    if(tq > r) break;
                    if(__gcd(tp, tq) != 1) continue;
                    int minv = (l + tp - 1) / tp, maxv = r / tq;
//                    pr(tp); pr(tq); pr(minv); prln(maxv);
                    ans += max(0, maxv - minv + 1);
                }
            }
            cout << 2 * ans << endl;
        }
    }

    return 0;
}
