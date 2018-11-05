
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
    while(cin >> n >> s) {
        map<char, int> mp;
        for(char c : s) mp[c]++;
        bool ok = false;
        for(auto p : mp) {
            if(p.second > 1) ok = true;
        }
        cout << (ok || (n == 1) ? "YES" : "NO") << endl;
    }
    return 0;
}
