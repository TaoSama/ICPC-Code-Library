
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
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        map<string, double> mp;
        double ans = 0;
        for(int i = 1; i <= n; ++i) {
            string s; cin >> s;
            if (mp.count(s)) {
                ans += mp[s] / 2;
                continue;
            }
            int last = -1;
            double tmp = 0;
            for (char c : s) {
                if (c == 'd' || c == 'f') {
                    tmp += last == 1 ? 0.4 : 0.2;
                    last = 1;
                } else {
                    tmp += last == 2 ? 0.4 : 0.2;
                    last = 2;
                }
            }
            ans += (mp[s] = tmp);
        }
        cout << (int)(ans*10 + 0.5) << endl;
    }
    return 0;
}
