
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        sort(a + 1, a + 1 + n);
        int ans = -1;
        for(int i = 1; i + 2 <= n; ++i) {
           if(a[i] + a[i + 1] > a[i + 2]) {
                ans = max(ans, a[i] + a[i + 1] + a[i + 2]);
           }
        }
        printf("%d\n", ans);
    }
    return 0;
}
