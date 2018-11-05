
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

char ts1[N], ts2[N];
int s1[N], s2[N];
int f[N][N];
const int D = 256;

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%s%s", ts1 + 1, ts2 + 1);
        int n = 0, m = 0;
        for(int i = 1; ts1[i]; ++i) {
            if(ts1[i + 1] == '*') {
                s1[++n] = ts1[i] + D;
            }
            else s1[++n] = ts1[i];
        }
        for(int i = 1; ts2[i]; ++i) {
            if(ts2[i + 1] == '*') {
                s2[++m] = ts2[i] + D;
            }
            else s2[++m] = ts2[i];
        }

        memset(f, 0, sizeof f);
        f[0][0] = 1;
        const int INOT = INF;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(s2[j] >= D) {
                    if(f[i - 1][j - 1]) {
                        f[i][j] = INOT; 
                    }
                    
                } 
            }
        }
    }
    return 0;
}
