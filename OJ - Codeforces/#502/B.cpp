
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
    string s, t;
    while(cin >> n >> s >> t) {
        long long cnt[2] = {};
        for(int i = 0; i < s.size(); ++i) {
            int x = s[i] - '0';
            int y = t[i] - '0';
            cnt[x]++;
        }
        long long ans = 0, c[2] = {};
        for(int i = 0; i < s.size(); ++i) {
            int x = s[i] - '0';
            int y = t[i] - '0';
            int cur = x | y;
            int nxt = (x ^ 1) | y;
            if(cur != nxt) {
                ans += cnt[x ^ 1];
                ++c[x];
            }
        }
        ans -= 1ll * c[0] * c[1];
        cout << ans << endl;
    }
    return 0;
}
