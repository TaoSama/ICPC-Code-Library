
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int w[N], h[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n; 
    while(cin >> n) {
        for(int i = 1; i <= n; ++i) cin >> w[i] >> h[i];
        bool ok = true;
        int last = 0;
        for(int i = n; i; --i) {
            int m1, m2; tie(m1, m2) = minmax(w[i], h[i]);
            if (m1 >= last) last = m1;
            else if(m2 >= last) last = m2;
            else ok = false;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}
