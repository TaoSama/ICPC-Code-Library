
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> n) {
        int cur = 1;
        vector<int> ans;
        ans.reserve(n);
        for( ; n > 1; ) {
            int maxv = 0, k = 0;
            for(int i = 2; ; ++i) {
                if(k <= i && maxv <= n / i) {
                    k = i;
                    maxv = n / i;
                } else {
                    break;
                }
            }
            for(int i = maxv + 1; i <= n; ++i) ans.emplace_back(cur);
            cur *= k;
            n = maxv;
        }
        ans.emplace_back(cur);
        for(int x : ans) cout << x << ' '; cout << endl;
    }
    return 0;
}
