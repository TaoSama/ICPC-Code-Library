
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
bool bad[N][N];
int x[N], y[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; scanf("%d", &t);
    while(t--) {
        LL n, k; scanf("%lld%lld", &n, &k);
        LL total = 5 * n * n - 4 * (n - 2) - 2 * 4; 
        LL safe = (total - 5 * (n - 2) - 3 * 2) / 2 + 5 * (n - 2) + 3 * 2;
        // cout << total << ' ' << safe << endl;

        for(int i = 1; i <= k; ++i) {
            scanf("%d%d", x + i, y + i);
            bad[x[i]][y[i]] = 1;
        }

        for(int i = 1; i <= k; ++i) {
            static const int d[][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
            int cnt = 0;
            for(int j = 0; j < 4; ++j) {
                int nx = x[i] + d[j][0], ny = y[i] + d[j][1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                ++cnt;
                if(!bad[nx][ny]) {
                    --total;
                    if(nx + ny >= n - 1) --safe;
                }
            }
            total -= cnt + 1;
            if(x[i] + y[i] >= n - 1) safe -= cnt + 1;
        }
        // cout << total << ' ' << safe << endl;
        
        LL g = __gcd(total, safe);
        static int kase = 0;
        printf("Case #%d: %lld/%lld\n", ++kase, safe / g, total /g);
        for(int i = 1; i <= k; ++i) {
            bad[x[i]][y[i]] = 0;
        }
    }
    return 0;
}
