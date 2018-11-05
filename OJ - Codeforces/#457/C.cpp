
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

bool isPrime(int x) {
    for(int i = 2; i * i <= x; ++i) {
        if(x % i == 0) return false;
    }
    return x != 1;
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    while(cin >> n >> m) {
        int p = n;
        while(!isPrime(p)) ++p;
        cout << p << ' ' << p << '\n';
        for(int i = 1; i < n - 1; ++i) cout << i << ' ' << i + 1 << ' ' << 1 << '\n';
        cout << n - 1 << ' ' << n << ' ' << p - (n - 2) << '\n';
        
        m -= n - 1;
        int u = 1, v = u + 2;
        while(m --) {
            cout << u << ' ' << v << ' ' << 1000000000 << '\n';
            if(v == n) {
                ++u;
                v = u + 2;
            }
            else ++v;
        }
    }
    return 0;
}
