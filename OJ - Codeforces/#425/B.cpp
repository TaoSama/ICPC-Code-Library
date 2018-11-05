
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
    
    string g, s; 
    while(cin >> g >> s){
        vector<int> good(26, 0);
        for(char c : g) good[c - 'a'] = 1;
        int n; cin >> n;
        for(int i = 1; i <= n; ++i){
            string t; cin >> t;
            bool ok = true;
            size_t x = 0, y = 0;
            for( ; x < s.size() && ok; ++x, ++y){
                if(s[x] == '?') ok &= y < t.size() && good[t[y] - 'a'];
                else if(s[x] == '*'){
                    while(y < t.size() && t.size() - y >= s.size() - x && !good[t[y] - 'a']) ++ y;
                    --y;
                }
                else ok &= y < t.size() && s[x] == t[y];
            }
            ok &= x == s.size() && y == t.size();
            cout << (ok ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}
