
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
    
    long long n, k;
    while(cin >> n >> k) {
        if(k >= 2 * n || n <= 2) {
            cout << 0 << endl;
            continue;
        }
        long long b = k - 1;
        long long a = k / 2 + 1;
        a = max(1ll, a);
        a = min(a, n);
        b = max(1ll, b);
        b = min(b, n);
        cout << max(0ll, b - a + 1) << endl;
    }
    return 0;
}
