
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 700 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];
int g[N][N];

bool f[N][N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> n) {
        for(int i = 1; i <= n; ++i) cin >> a[i];
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
               g[i][j] = __gcd(a[i], a[j]); 
            }
        }

        memset(f, false, sizeof f);
        for (int i = 1; i <= n; ++i) f[i][i] = 1;
        for (int l = 2; l <= n; ++l)
        {
            for (int L = 1; L + l - 1 <= n; ++L)
            {
                int R = L + l - 1;
                if (g[L][R] == 1) continue;
                if (f[L][R - 1]) {
                    for (int j = L; j >= 1; --j) {
                        f[R][j] |= f[L][j];
                    }
                }
                if (f[R][L + 1]) {
                    for (int j = R; j <= n; ++j) {
                        f[L][j] |= f[R][j];
                    }
                }
            }
        }
        bool ok = false;
        for (int i = 1; i <= n; i++) {
            ok |= f[i][1] & f[i][n];
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}
