
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
    
    int t; cin >> t;
    while(t--) {
        unsigned long long s = 0;
        bool ok = true;
        for(int i = 0; i < 4; ++i) {
            unsigned long long x; cin >> x;
            ok &= x == 0;
            s += x;
        }
        if(!ok && s == 0) {
            cout << "18446744073709551616\n";
        }
        else cout << s << endl;
    }
    return 0;
}
