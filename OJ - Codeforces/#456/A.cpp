
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
    
    long long a, b, x, y, z;
    while(cin >> a >> b >> x >> y >> z) {
        long long aa = 2 * x + y;
        long long bb = y + 3 * z;
        cout << max(0ll, aa - a) + max(0ll, bb - b) << endl;
    }
    return 0;
}
