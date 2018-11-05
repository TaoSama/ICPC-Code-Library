
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int quick(int x, int n, int mod) {
    int ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = 1ll * ret * x % mod;
        x = 1ll * x * x % mod;
    }
    return ret;
}

int dw[] = {1, 4, 5, 6};
int co[] = {4, -2, -1, -1};

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d", &n);
        // \sum_{k=0}^n {16^{n-k} \mod (8k+1) \over 8k+1} + \sum_{k=n+1}^{\infinity} {16^{n-k} \over 8k+1}
        // 16 * 1/16 = 1, 1/16/9, so abandon the second term
        
        --n;
        double ans = 0;
        for(int i = 0; i < 4; ++i) {
            double cur = 0;
            for(int k = 0; k <= n; ++k) {
                int mod = 8 * k + dw[i];
                int numerator = quick(16, n - k, mod);
                cur += 1.0 * numerator / mod;
            }
            ans += co[i] * cur;
        }
        ans = fmod(ans, 1);
        if(ans < 0) ans += 1;
        int digit = ans * 16;
        static int kase = 0;
        printf("Case #%d: %d %X\n", ++kase, n + 1, digit);
    }
    return 0;
}
