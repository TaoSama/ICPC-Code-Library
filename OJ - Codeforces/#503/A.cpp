
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int v[N], c[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> n >> m) {
        for(int i = 1; i <= n; ++i) {
            cin >> v[i] >> c[i];
        }
        map<int, vector<int>> mp;
        for(int j = 1; j <= n; ++j) {
            mp[v[j]].push_back(c[j]);
        }
        for(auto& p : mp) sort(p.second.begin(), p.second.end());
        long long ans = 1e18;
        for(int i = 1; i <= n; ++i) {
            long long cur = 0, cnt = mp[1].size();
            vector<int> lft;
            for(auto& p : mp) {
                if(p.first == 1) continue;
                auto& v = p.second;
                for(int j = 0; j < v.size(); ++j) {
                    if(v.size() - j >= i) {
                        cur += v[j];
                        ++cnt;
                    }
                    else {
                        lft.push_back(v[j]);
                    }
                }
            }
            if(cnt < i) {
                sort(lft.begin(), lft.end(), greater<int>());
                while(cnt < i) {
                    cur += lft.back();
                    lft.pop_back();
                    ++cnt;
                }
            }
            ans = min(ans, cur);
        }
        cout << ans << endl;
    }
    return 0;
}
