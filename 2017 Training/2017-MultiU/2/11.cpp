
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int x[N], y[N];
int dd[N][N];

inline int sq(int x) {return x * x;}
inline int disxxx(int i, int j){
    return sq(x[i] - x[j]) + sq(y[i] - y[j]);
}
inline int dis(int i, int j){ return dd[i][j]; }

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(scanf("%d", &n) == 1){
        map<pair<int, int>, int> mp;
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d", x + i, y + i);
            ++mp[{x[i], y[i]}];
        }
        long long ans = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = i + 1; j <= n; ++j){
                int x3 = (x[i]+x[j]+y[i]-y[j]);//另两个点的坐标
                int x4 = (x[i]+x[j]+y[j]-y[i]);
                int y3 = (y[i]+y[j]+x[j]-x[i]);
                int y4 = (y[i]+y[j]+x[i]-x[j]);
                if(x3 & 1) continue;
                if(x4 & 1) continue;
                if(y3 & 1) continue;
                if(y4 & 1) continue;
                x3 /= 2; y3 /= 2;
                x4 /= 2; y4 /= 2;
                ans += mp.count({x3, y3}) && mp.count({x4, y4});
            }
        }
        printf("%lld\n", ans / 2);
    } 
    return 0;
}
