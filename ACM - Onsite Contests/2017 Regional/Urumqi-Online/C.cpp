
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, b;
int c[N], d[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &b);
        for(int i = 1; i <= n; ++i) scanf("%d", c + i);
        for(int i = 1; i < n; ++i) scanf("%d", d + i);
        int sum = 0;
        bool ok = true;
        for(int i = 1; i < n; ++i) {
            sum += c[i];
            ok &= sum >= b * d[i];
            sum -= b * d[i];
        }
        puts(ok ? "Yes" : "No");
    }
    return 0;
}
