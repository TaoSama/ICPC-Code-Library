
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> n) {
        for(int i = 1; i <= 2 * n; ++i) cin >> a[i];
        sort(a + 1, a + 1 + 2 * n);
        long long ans = 1ll * (a[n] - a[1]) * (a[2 * n] - a[n + 1]);
        for(int i = 2; i <= n; ++i) {
            ans = min(ans, 1ll * (a[n + i - 1] - a[i]) * (a[2 * n] - a[1]));
        }
        cout << ans << endl;
    }
    return 0;
}
