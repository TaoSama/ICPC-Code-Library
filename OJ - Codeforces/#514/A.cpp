
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
    
    int n, L, a;
    while(cin >> n >> L >> a) {
        int ans = 0;
        int last = 0;
        for(int i = 1; i <= n; ++i) {
            int t, l; cin >> t >> l;
            ans += (t - last) / a;
            last = t + l;
        }
        ans += (L - last) / a;
        cout << ans << endl;
    }
    return 0;
}
