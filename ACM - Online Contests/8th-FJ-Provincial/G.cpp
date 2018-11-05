
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int f[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    f[0] = 1;
    for(int i = 1; i < N; ++i) f[i] = f[i - 1] * i;
    double sum = 0;
    for(int i = 1; i <= 3000; ++i) sum += log10(i);
    cout << sum << endl;
    for(int i= 1; i <= 10; ++i){
        double ans = 0;
        for(int j = 1; j <= i; ++j) ans += 1. * i / j;
        ans *= f[i - 1];
        printf("%d = %.1f\n", i, ans);
    }
    return 0;
}
