
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

long long two[N], a[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, k;
    scanf("%d%d", &n, &k);
    two[0] = 1;
    for(int i = 1; i < N; ++i) two[i] = two[i - 1] * 2 % MOD;
    for(int i = 1; i <= n; ++i){
        scanf("%lld", a + i);
    }
    sort(a + 1, a + 1 + n);
    long long ans = 0;
    for(int i = 1; i <= n; ++i){
        int r = upper_bound(a + 1, a + 1 + n, k - a[i]) - a - 1;
        if(r >= i) ans = (ans + two[r - i]) % MOD;
    }
    printf("%lld\n", ans);;
    return 0;
}

