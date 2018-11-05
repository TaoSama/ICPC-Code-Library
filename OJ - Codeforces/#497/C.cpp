
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int a[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n;
    while(cin >> n) {
        for(int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + 1 + n);
        int ans = 0;
        for(int i = 1, j = 1; i <= n; ++i) {
            while(j <= n && a[j] <= a[i]) ++j;
            if(j <= n) {
                ++ans;
                ++j;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
