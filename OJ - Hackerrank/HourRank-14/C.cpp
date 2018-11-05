
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
        int a, b, x; cin >> a >> b >> x;
        vector<int> ch(b + 1);
        vector<int> ans;
        for(int i = b; i >= a; --i) {
            if(ch[i]) continue;
            ans.push_back(i);
            for(int j = 1; j * j <= i; ++j) ch[j] = ch[i / j] = true;
        }
        if(ans.size() >= x) {
            for(int i = 0; i < x; ++i) cout << ans[i] << " \n"[i + 1 == x];
        }
        else cout << -1 << endl;
    }
    return 0;
}
