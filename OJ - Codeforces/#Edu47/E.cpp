
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 998244353;

int n, a[N];
long long two[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);

    two[0] = 1;
    for(int i = 1; i < N; ++i) {
        two[i] = two[i - 1] << 1;
        two[i] %= MOD;
    }
    
    while(cin >> n) {
        for(int i = 1; i <= n; ++i) cin >> a[i];
        long long ans = 0, sum = 0;
        for(int i = 1; i <= n; ++i) {
            if(i <= 2) sum += a[i];
            else {
                sum = sum * 2 + a[i] - a[i - 1];
            }
            sum = (sum % MOD + MOD) % MOD;
            ans += sum * two[n - i] % MOD;
            ans %= MOD;
        }
        cout << ans << endl;
    }
    return 0;
}
