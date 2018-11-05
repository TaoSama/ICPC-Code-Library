
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];
int mu[N];
int cnt[N * 2];
typedef long long LL;

LL quick(LL x, LL n){
    LL ret = 1;
    for(; n; n >>= 1){
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
    }
    return ret;
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    mu[1] = 1;
    for(int i = 1; i < N; ++i){
        for(int j = i + i; j < N; j += i){
            mu[j] -= mu[i];
        }
    }
    
    int t; scanf("%d", &t);
    while(t--){
        memset(cnt, 0, sizeof cnt);
        int minv = N;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            int x; scanf("%d", &x);
            ++cnt[x];
            minv = min(minv, x);
        }
        for(int i = 1; i < N * 2; ++i) cnt[i] += cnt[i - 1];
        
        long long ans = 0;
        for(int i = 2; i <= minv; ++i) {
            long long cur = 1;
            for(int j = 1; i * j <= 100000; ++j){
                cur = cur * quick(j, cnt[i * j + i - 1] - cnt[i * j - 1]) % MOD;
            }
            ans -= mu[i] * cur;
            ans %= MOD;
        }
        ans = (ans + MOD) % MOD;
        static int kase = 0;
        printf("Case #%d: %lld\n", ++kase, ans);
    }
    return 0;
}
