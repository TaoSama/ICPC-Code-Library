
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q, c;
int cnt[20][200][200];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(scanf("%d%d%d", &n, &q, &c) == 3){
        memset(cnt, 0, sizeof cnt);
        for(int i = 1; i <= n; ++i){
            int x, y, z; scanf("%d%d%d", &x, &y, &z);
            ++cnt[z][x][y];
        }
        for(int i = 0; i <= c; ++i){
            for(int j = 1; j <= 100; ++j){
                for(int k = 1; k <= 100; ++k){
                    cnt[i][j][k] += cnt[i][j][k - 1];
                }
            }
        }
        for(int i = 0; i <= c; ++i){
            for(int j = 1; j <= 100; ++j){
                for(int k = 1; k <= 100; ++k){
                    cnt[i][j][k] += cnt[i][j - 1][k];

                }
            }
        }
        
        for(int i = 1; i <= q; ++i){
            int t, xa, ya, xb, yb; 
            scanf("%d%d%d%d%d", &t, &xa, &ya, &xb, &yb);
            t %= (c + 1);
            xa--; ya--;
            int ans = 0;
            for(int x = 1; x <= c; ++x){
                int l = (x - t) % (c + 1);
                l = (l + c + 1) % (c + 1);
                int sum = cnt[l][xb][yb] + cnt[l][xa][ya] - cnt[l][xb][ya] - cnt[l][xa][yb];
                // cout << x << " = " << sum << endl;
                ans += x * sum;
            }
            printf("%d\n", ans);
        }
    } 
    return 0;
}
