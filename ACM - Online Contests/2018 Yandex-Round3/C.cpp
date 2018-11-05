
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
    
    int n, h;
    while(cin >> n >> h) {
        vector<int> up[2], dw[2];
        for(int i = 1; i <= n; ++i) {
            int x, y; cin >> x >> y;
            int u = x - y;
            int d = x - (h - 1 - y);
            int b = u & 1;
            up[b].emplace_back(u);
            dw[b].emplace_back(d);
        }
        for(int i = 0; i < 2; ++i) {
            sort(up[i].begin(), up[i].end());
            sort(dw[i].begin(), dw[i].end());
        }
        long long ans = 1ll * n * (2 * h - 1);
        auto get = [&](const vector<int>& u, vector<int>& d) {
            long long ret = 0;
            int l = 0, r = 0;
            for(int i = 0; i < d.size(); ++i) {
                while(r < u.size() && u[r] - d[i] <= h - 1) ++r;
                while(l < r && d[i] - u[l] > h - 1) ++l;
                ret += r - l;
            }
            return ret;
        };
        for(int i = 0; i < 2; ++i) ans -= get(up[i], dw[i]);
        cout << ans << endl;
    }
    return 0;
}
