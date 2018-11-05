
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int a[N];
long long f[N][N][N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, L, R;
    while(cin >> n >> L >> R) {
        for(int i = 1; i <= n; ++i) cin >> a[i], a[i] += a[i - 1];
        const long long INFLL = 1ll * INF * INF;
        for(int i = 0; i <= n + 5; ++i) {
            for(int j = 0; j <= n + 5; ++j) {
                for(int k = 0; k <= n + 5; ++k) {
                    f[i][j][k] = INFLL;
                }
            }
        }
        for(int i = 1; i <= n; ++i) if(L <= 1 && 1 <= R) f[i][i][1] = a[i] - a[i - 1];

        for(int l = 2; l <= n; ++l) {
            for(int i = 1; i + l - 1 <= n; ++i) {
                int j = i + l - 1;
                for(int k = 
                if(L <= l && l <= R) f[i][j] = a[j] - a[i - 1];
                else {
                    for(int x = i; x <= j; ++x) {
                        // x - i + j - y + 1 <= R
                        for(int y = x; y <= j; ++y) {
                            if(x - i + j - y + 1 > R) continue;
                            if(x - i + j - y + 1 < L) break;
                            f[i][j] = min(f[i][j], a[i - 1] + a[j] + f[x][y]);
                            // cout << i << ' ' << j << " = " << "(" <<x << ","<<y<<") " << f[x][y] << ' ' << a[j]-a[i-1] + f[x][y] << endl;
                        }
                    }
                }
            }
        }
        long long ans = f[1][n];
        if(ans == INFLL) ans = 0;
        cout << ans << '\n';
    }
    return 0;
}
