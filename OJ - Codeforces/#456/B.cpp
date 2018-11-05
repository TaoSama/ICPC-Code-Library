
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;



int main(){
#ifdef LOCAL
//    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    unsigned long long n, k;
    while(cin >> n >> k) {
        unsigned long long ans = 0;
        if(k == 1) ans = n;
        else {
            int h = 63 - __builtin_clzll(n);
            for(int i = 0; i <= h; ++i) ans |= 1ll << i;
        }
        cout << ans << endl;
    }
    return 0;
}
