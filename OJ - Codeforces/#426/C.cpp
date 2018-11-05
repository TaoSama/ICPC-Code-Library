
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;


int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int q; scanf("%d", &q);
    while(q--) {
        int x, y; scanf("%d%d", &x, &y);
        bool ok = true;
        long long ab = cbrt(1ll * x * y) + 0.5;
        long long a = x / ab;
        long long b = y / ab;
        long long nx = a * a * b, ny = a * b * b;
        if((nx == x && ny == y) || (nx == y && ny == x)) ok = true;
        else ok = false;
        puts(ok ? "Yes" : "No");
    }
    return 0;
}
