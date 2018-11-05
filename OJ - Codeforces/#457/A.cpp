
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
    
    int x, h, m;
    while(cin >> x >> h >> m ) {
        int ans = 0;
        auto isOk = [](int x) {
            return x / 10 == 7 || x % 10 == 7;
        };
        for(; !isOk(h) && !isOk(m); ) {
            int t = m < x;
            m = (m - x + 60) % 60;
            h = (h - t + 24) % 24;
            ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}
