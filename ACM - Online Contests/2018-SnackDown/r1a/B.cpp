
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
    while (t--) {
        int n; cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; ++i) cin >> v[i];
        bool ok  = true;
        if (v[0] < v[n - 1]) {
            for(int i = 1; i < n; ++i) ok &= v[i - 1] <= v[i];
        } else {
            int k = 0;
            for ( ; k + 1 < n && v[k] <= v[k + 1]; ++k);
            ++k;
            for ( ; k + 1 < n && v[k] <= v[k + 1]; ++k);
            ok &= k + 1 >= n;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}
