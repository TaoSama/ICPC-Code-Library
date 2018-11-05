
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

long long l[N], r[N];

long long sum[N << 2], ans[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n; 
    while(cin >> n) {
        vector<long long> xs;
        memset(sum, 0, sizeof sum);
        memset(ans, 0, sizeof ans);
        for(int i = 1; i <= n; ++i) {
            cin >> l[i] >> r[i];
            xs.push_back(l[i]);
            xs.push_back(l[i] + 1);
            xs.push_back(r[i]);
            xs.push_back(r[i] + 1);
        }
        sort(xs.begin(), xs.end());
        xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
        // for(int x : xs ) cout << x << ' '; cout << endl;
        for(int i = 1; i <= n; ++i) {
            int x = lower_bound(xs.begin(), xs.end(), l[i]) - xs.begin();
            int y = lower_bound(xs.begin(), xs.end(), r[i] + 1) - xs.begin();
            // cout << x << ' ' << y << endl;
            sum[x]++; sum[y]--;
        }
        for(int i = 0; i < xs.size(); ++i) {
            sum[i + 1] += sum[i];
            if(sum[i]) ans[sum[i]] += xs[i + 1] - xs[i];
        }
        for(int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
    }
    return 0;
}
