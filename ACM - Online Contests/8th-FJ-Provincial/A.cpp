
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;



int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; scanf("%d", &t);
    while(t--){
        int n, m; scanf("%d%d", &n, &m);
        int a = (m - 2 * n) / 2, b = n - a;
        printf("%d %d\n", a, b);
    }
    return 0;
}