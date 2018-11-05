
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
    
    int n, m;
    while(cin >> n >> m) {
        int lft = 0;
        for(int i = 0; i < n; ++i) {
            int x; cin >> x;
            lft += x;
            cout << lft / m << " \n"[i == n - 1];
            lft %= m;
        }
    }
    return 0;
}
