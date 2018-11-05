
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
LL a[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, l; 
    while(cin >> n >> l) {
        for(int i = 0; i <= 30; ++i) a[i] = 1ll * INF * INF;
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = n - 2; i >= 0; --i) a[i] = min(a[i], a[i + 1]);
        for(int i = 1; i <= 30; ++i) a[i] = min(a[i], a[i - 1] * 2);
        // for(int i = 0; i <= 30; ++i) cout << a[i] << ' '; cout << endl;
        LL ans = 1ll * INF * INF, cur = 0;
        for(int i = 30; i >= 0; --i) {
            if(1 << i >= l) ans = min(ans, a[i]);
            if(l >> i & 1) {
                cur += a[i];
                // cout << i << "=" << cur << ' ' << cur +a[i] << endl;
            }
            if(cur > 0) ans = min(ans, cur + a[i]);
        }
        // cout << cur << endl;
        ans = min(ans, cur);
        cout << ans << endl;
    }
    return 0;
}
