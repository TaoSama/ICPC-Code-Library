
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> n >> m) {
        if(m < n - 1) {
            cout << "Impossible\n";
            continue;
        }
        vector<pair<int, int>> v;
        for(int i = 1; i <= n && m; ++i) {
            for(int j = i + 1; j <= n && m; ++j) {
                if(gcd(i, j) == 1) {
                    --m;
                    v.emplace_back(i, j);
                }
            }
        }
        if(m > 0) {
            cout << "Impossible\n";
        }
        else {
            cout << "Possible\n";
            for(const auto& p : v) cout << p.first << ' ' << p.second << '\n';
        }
    }
    return 0;
}
