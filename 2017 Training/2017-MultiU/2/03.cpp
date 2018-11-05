
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int a[N], b[N];
int sufMax[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(scanf("%d", &n) == 1){
        int maxv = 0;
        for(int i = 1; i <= n; ++i){
            scanf("%d", a + i);
            a[i] -= i;
            maxv = max(maxv, a[i]);
        }
        for(int i = n; i >= 1; --i) {
            if(i == n) sufMax[i] = a[i];
            else sufMax[i] = max(sufMax[i + 1], a[i]);
        }
        int p = 0;
        for(int i = 1; i <= n; ++i) if(a[i] == maxv) p = i;
        for(int i = 1; i <= n; ++i) scanf("%d", b + i);
        sort(b + 1, b + 1 + n, [&](int x, int y){
            return sufMax[x] > sufMax[y];
        });

        int rightMax = 0;
        long long ans = 0;
        for(int i = 1; i <= n; ++i) {
            int cur = max(sufMax[b[i]], rightMax);
            rightMax = max(rightMax, cur - n - i);
            ans += cur;
        }
        printf("%lld\n", (ans % MOD + MOD) % MOD);
    }      
    return 0;
}
