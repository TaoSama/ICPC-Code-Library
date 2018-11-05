
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
    
    int n;
    while(cin >> n) {
        vector<int> a(n), b(n);
        map<int, int> have;
        for(auto& x : a) cin >> x, have[x] = 1;
        for(auto& x : b) cin >> x, have[x] = 1;
        int ans = 0;
        for(int x : a) for(int y : b) ans ^= have.count(x ^ y); 
        cout << (!ans ? "Karen" : "Koyomi") << endl;
    }
    return 0;
}
