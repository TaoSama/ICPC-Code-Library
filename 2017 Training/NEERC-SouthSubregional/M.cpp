
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
    
    int a[4];
    for(int i = 0; i < 4; ++i) cin >> a[i];
    int ans = 2 * (abs(a[2] - a[0]) + abs(a[3] - a[1])) + 4;
    if(a[2] == a[0] || a[3] == a[1]) ans += 2;
    cout << ans << endl;
    return 0;
}
