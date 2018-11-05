
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
    while(cin >> n) {
        vector<pair<int, int>> v;
        for(int i = 1; i <= n; ++i) {
            int sum = 0;
            for(int j = 0; j < 4; ++j) {
                int x; cin >> x;
                sum += x;
            }
            v.push_back({-sum, i});
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); ++i) {
            if(v[i].second == 1) {
                cout << i + 1 << endl;
            }
        }
    }
    return 0;
}
