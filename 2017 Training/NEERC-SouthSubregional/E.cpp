
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
    
    int n; string s;
    cin >> n >> s;
    int m; cin >> m;
    vector<string> v(m);
    for(auto& s : v) cin >> s;
    vector<int> shadowed(n, false);
    vector<int> used(26, false);
    for(int i = 0; i < n; ++i) {
        if(s[i] == '*') shadowed[i] = true;
        else used[s[i] - 'a'] = true;
    }
    vector<int> can(m, true);

    for(int i = 0; i < m; ++i) {
        const auto& ss = v[i];
        for(int j = 0; j < n; ++j) {
            if(s[j] == '*') {
                if(used[ss[j] - 'a']) {can[i] = false; break;}
            }
            else {
                if(s[j] != ss[j]) {can[i] = false; break;}
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i < 26; ++i) {
        if(used[i]) continue;
        bool ok = true;
        for(int k = 0; k < m; ++k) {
            if(!can[k]) continue;
            const auto& ss = v[k];
            ok = false;
            for(int j = 0; j < n && !ok; ++j) if(shadowed[j] && ss[j] == i + 'a') ok = true;
            if(!ok) break;
        }
        ans += ok;
    }
    cout << ans << endl;
    return 0;
}
