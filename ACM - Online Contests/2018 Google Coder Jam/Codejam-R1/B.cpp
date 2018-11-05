
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int R, b, c;
int m[N], s[N], p[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        cin >> R >> b >> c;
        for(int i = 1; i <= c; ++i) cin >> m[i] >> s[i] >> p[i];
        long long l = 0, r = 9e18, ans = -1;
        while(l <= r) {
            long long o = l + (r - l) / 2;
            long long sum = 0;
            vector<long long> v; v.reserve(c);
            for(int i = 1; i <= c; ++i) {
                long long x = min(1ll * m[i], (o - p[i]) / s[i]);
                v.emplace_back(x);
            }
            sort(v.begin(), v.end());
            reverse(v.begin(), v.end());
            for(int i = 0; i < R; ++i) {
                sum += v[i];
                if(sum >= b) break;
            }
            if(sum >= b) ans = o, r = o - 1;
            else l = o + 1;
        }
        static int kase = 0;
        cout << "Case #" << ++kase << ": " << ans << '\n';
    }
    return 0;
}
