
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 3e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k, p;
int a[N], b[N];
long long f[N][N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> n >> k >> p){
        for(int i = 1; i <= n; ++i) cin >> a[i];
        for(int i = 1; i <= k; ++i) cin >> b[i];
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + k);
        memset(f, 0x3f, sizeof f); 
        for(int i = 0; i <= k; ++i) f[0][i] = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= k; ++j){
                long long dis = abs(a[i] - b[j]) + abs(b[j] - p);
                f[i][j] = f[i][j - 1];
                f[i][j] = min(f[i][j], max(f[i - 1][j - 1], dis));
            }
        }
        cout << f[n][k] << endl;
    }
    return 0;
}
