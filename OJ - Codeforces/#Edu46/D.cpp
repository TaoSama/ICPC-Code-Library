
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 998244353;

long long c[N][N], f[N], g[N];
int a[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n = 1000;
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= i; ++j) {
            if(j == 0 || j == i) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
    while(cin >> n) {
        for(int i = 1; i <= n; ++i) cin >> a[i];
        g[0] = 1;
        for(int i = 1; i <= n; ++i) {
            f[i] = 0;
            for(int j = 1; j <= i; ++j) {
               if(a[j] > 0 && a[j] <= i - j) {
                   // cout << "fuck" << ' ' << j << ' ' << i  << ' ' << i - j - 1 << ' ' << a[j] - 1 << ' ' << c[i-j-1][a[j]-1]<< endl;
                   f[i] = (f[i] + g[j - 1] * c[i - j - 1][a[j] - 1]) % MOD;            
               }
            }
            // cout << i << ' ' << f[i] << endl;
            g[i] = (g[i - 1] + f[i]) % MOD;
        }
        cout << (g[n] - 1 + MOD) % MOD << endl;
    }
    return 0;
}
