
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

long long n, k;

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(scanf("%lld%lld", &n, &k) == 2){
        n %= MOD;
        long long ret = 1;
        for(; k; k >>= 1){
            if(k & 1) ret = ret * n % MOD;
            n = n * n % MOD;
        }
        static int kase = 0;
        printf("Case #%d: %lld\n", ++kase, ret);
    } 
    return 0;
}
