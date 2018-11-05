
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

bool kmp(const string& s, const string& t){
     
        vector<int> nxt(t.size());
        nxt[0] = -1;
        for(int i = 0, j = -1; i < t.size(); ){
            while(~j && t[i] != t[j]) j = nxt[j];
            nxt[++i] = ++j;
        }
        bool ok = false;
        for(int i = 0, j = 0; i < s.size(); ){
            while(~j && s[i] != t[j]) j = nxt[j];
            ++i; ++j;
            if(j == t.size()) return true;
        }
        return false;
}


int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    while(t--){
        string s, t; cin >> s >> t;
        bool ok = t == "0" || kmp(s, t) || kmp(string(s.rbegin(), s.rend()), t);
        cout << (ok ? "Alice" : "Bob") << '\n';
    }
    return 0;
}
