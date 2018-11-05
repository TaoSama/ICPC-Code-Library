
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int a[N];
long long odd[N], even[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, m; 
    while(cin >> n >> m) {
        a[n + 1] = m;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            odd[i] = odd[i - 1];
            even[i] = even[i - 1];
            if(i & 1) odd[i] += a[i];
            else even[i] += a[i];
        }
        long long ans = odd[n] - even[n];
        if(n % 2 == 0) ans += m, m = 0;
        for(int i = 0; i <= n; ++i) {
            if (a[i] + 1 == a[i + 1]) continue;
            if (i & 1) {
                int x = a[i] + 1;
                ans = max(ans, odd[i] - even[i] - x + m + even[n] - even[i] - odd[n] + odd[i]);
            }
            else {
                int x = a[i + 1] - 1;
                ans = max(ans, odd[i] - even[i] + x + m + even[n] - even[i] - odd[n] + odd[i]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
