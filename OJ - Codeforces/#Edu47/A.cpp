
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int c[N], a[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> n >> m) {
        for(int i = 1; i <= n; ++i) cin >> c[i];
        for(int i = 1; i <= m; ++i) cin >> a[i];

        int ans = 0;
        for(int i = 1, j = 1; i <= m; ++i) {
            while(j <= n && a[i] < c[j]) ++j; 
            if(j <= n) {
                ++ans;
                ++j;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
