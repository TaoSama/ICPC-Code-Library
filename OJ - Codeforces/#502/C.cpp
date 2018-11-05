
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
        pair<int, int> ans = {INF, INF};
        for(int i = 1; i <= n; ++i) {
            ans = min(ans, {i + n / i + (n % i ? 1 : 0), i});
        }
        int seg = ans.second;
        vector<vector<int>> v(n / seg + 1, vector<int>());
        for(int i = 1; i <= n; ++i) {
            v[(i - 1) / seg].emplace_back(i);
        }
        reverse(v.begin(), v.end());
        vector<int> t;
        for(const auto& v1 : v) {
            for(const auto& v2 : v1) {
                t.emplace_back(v2);
            }
        }
        for(int i = 0; i < n; ++i) {
            cout << t[i] << " \n"[i + 1 == n];
        }
    }
    return 0;
}
