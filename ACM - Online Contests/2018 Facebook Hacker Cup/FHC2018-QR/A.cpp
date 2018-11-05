
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
        long long n, k, v; cin >> n >> k >> v;
        vector<string> vs(n);
        for(auto& s : vs) cin >> s;
        int r = (v * k - k) % n;
        static int kase = 0;
        cout << "Case #" << ++kase << ": ";
        vector<int> ans;
        for(int i = r; i < r + k; ++i) {
            ans.emplace_back(i % n);
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < k; ++i) {
            cout << vs[ans[i]] << " \n"[i == k - 1];
        }
    }
    return 0;
}
