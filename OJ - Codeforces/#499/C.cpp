
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
    
    int n, k;
    while(cin >> n >> k) {
        int g; cin >> g;
        g %= k;
        for(int i = 2; i <= n; ++i) {
            int x; cin >> x;
            g = __gcd(g, x % k);
        }

        vector<int> ans;
        ans.push_back(0);
        for(int i = 1; g; ++i) {
            if(i * g < k) {
                ans.push_back(i * g);
            }
            else {
                break;
            }
        }
        cout << ans.size() << endl;
        for(int x : ans) cout << x << ' ';
        cout << endl;
    }
    return 0;
}
