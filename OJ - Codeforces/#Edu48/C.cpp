
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
long long a[N], b[N];
long long sa[N], sia[N], fia[N];
long long sb[N], sib[N], fib[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> n) {
        for(int i = 1; i <= n; ++i) cin >> a[i];
        for(int i = 1; i <= n; ++i) cin >> b[i];
        for(int i = 1; i <= n; ++i) {
            sa[i] = sa[i - 1] + a[i];
            sb[i] = sb[i - 1] + b[i];
            sia[i] = sia[i - 1] + 1ll * (i - 1) * a[i];
            sib[i] = sib[i - 1] + 1ll * (i - 1) * b[i];
        }
        sib[n + 1] = 0;
        for(int i = n; i >= 1; --i) {
            fia[i] = fia[i + 1] + 1ll * (n - i) * a[i];
            fib[i] = fib[i + 1] + 1ll * (n - i) * b[i];
        }
        long long ans = 0, cur = 0;
        long long t = 0;
        for(int i = 1; i <= n; ++i) {
            if(i & 1) {
                long long aa = sia[n] - sia[i - 1] + (t - i + 1) * (sa[n] - sa[i - 1]);
                long long bb = fib[i] + (t + n - i + 1) * (sb[n] - sb[i - 1]);
                // cout << aa << ' ' << bb << endl;
                ans = max(ans, cur + aa + bb);
                cur += t * a[i];
                t += 1;
                cur += t * b[i];
                t += 1;
            }
            else {
                long long bb = sib[n] - sib[i - 1] + (t - i + 1) * (sb[n] - sb[i - 1]);
                long long aa = fia[i] + (t + n - i + 1) * (sa[n] - sa[i - 1]);
                // cout << aa << ' ' << bb << endl;
                ans = max(ans, cur + aa + bb);
                cur += t * b[i];
                t += 1;
                cur += t * a[i];
                t += 1;
            }
            ans = max(ans, cur);
        }
        cout << ans << endl;
    }
    return 0;
}
