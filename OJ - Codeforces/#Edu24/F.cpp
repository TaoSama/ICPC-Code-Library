
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;



int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        long long l = 0, r = 1ll * n * (n - 1) / 2, ans = 0;
        
        auto check = [&](long long m){
            long long hf = (m + 1) / 2;
            long long lf = n - hf;
            if(lf < 0) return false;
            return lf * (lf - 1) / 2 >= m - hf;
        };
        while(l <= r){
            long long m = l + (r - l) / 2;
            if(check(m)) ans = m, l = m + 1;
            else r = m - 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
