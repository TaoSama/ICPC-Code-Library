
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, q;
int w[N];
int val[1 << 12][200];
int cnt[1 << 12];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> n >> m >> q) {
        for(int i = 0; i < n; ++i) {
            cin >> w[i];
        }
        vector<int> v;
        for(int i = 1; i <= m; ++i) {
            string t; cin >> t;
            int x = 0;
            for(int j = 0; j < n; ++j) {
                x |= (t[j] - '0') << j;
            }
            ++cnt[x];
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        for(int s = 0; s < 1 << n; ++s) {
            for(int j = 0; j < v.size(); ++j) {
                int t = v[j];
                int x = s ^ t;
                int sum = 0;
                for(int i = 0; i < n; ++i) {
                    sum += (~x >> i & 1) * w[i];            
                }
                if(sum <= 100) val[s][sum] += cnt[t];
            }
        }
        for(int s = 0; s < 1 << n; ++s) {
            for(int i = 1; i <= 100; ++i) val[s][i] += val[s][i - 1];
        }
        for(int i = 1; i <= q; ++i) {
            string s; int k; cin >> s >> k;
            int x = 0;
            for(int j = 0; j < n; ++j) {
                x |= (s[j] - '0') << j;
            }
            cout << val[x][k] << '\n';
        }

    }
    return 0;
}
