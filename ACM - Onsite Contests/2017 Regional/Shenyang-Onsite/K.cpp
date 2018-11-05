
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int a[N], f[N], g[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        f[1] = f[2] = 0;
        for(int i = 3, ok = 1; i <= n; ++i) {
            int diff = a[i] - a[i - 1] - 1;
            ok &= diff;
            f[i] = f[i - 1] + diff;
        }
        g[n - 1] = g[n] = 0;
        for(int i = n - 2, ok = 1; i >= 1; --i) {
            int diff = a[i + 1] - a[i] - 1;
            ok &= diff;
            g[i] = g[i + 1] + diff; 
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i) ans = max(ans, f[i] + g[i]);
        cout << ans << '\n';
    }
    return 0;
}
