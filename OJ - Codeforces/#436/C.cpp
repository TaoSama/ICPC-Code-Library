
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
    
    long long a, b, f, k;
    while(cin >> a >> b >> f >> k) {
        long long ans = 0;
        long long fuel = 0;
        bool ok = true;
        vector<long long> ps; ps.push_back(0);
        for(int i = 1; i <= k; ++i) {
            if(i & 1) ps.push_back(i / 2 * 2 * a + f);
            else ps.push_back(i / 2 * 2 * a - f);
        }
        ps.push_back(k * a);
        for(int i = 0; i + 1 < static_cast<int>(ps.size()) && ok; ++i) {
            long long dif = ps[i + 1] - ps[i];
            if(dif > fuel) {
                if(dif > b) ok = false;
                else {
                    ++ans;
                    fuel = b - dif;
                }
            }
            else fuel -= dif;
        }
        if(!ok) ans = 0;
        cout << ans - 1 << endl;
    }
    return 0;
}
