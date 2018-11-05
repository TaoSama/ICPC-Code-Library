
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
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        long long ans = 0;
        vector<int> v1, v2;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '#') {
                v1.emplace_back(i);
            }
        }
        if (v1.size() != n) {
            int last = -INF;
            for (int i = 0; i < v1.size(); ++i) {
                if (v1[i] == i) {
                    v2.emplace_back(v1[i]);
                    continue;
                }
                last = max(last, v1[i]);
                if (last >= n - 1) {
                    ans = -1;
                    break;
                }
                v2.emplace_back(last);
                last += 2;
            }
            if (ans != -1) {
                for (int i = 0; i < v1.size(); ++i) {
                    ans += v2[i] - v1[i] + (v2[i] - i);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
