
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, p;
string s;

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> n >> p >> s) {
        vector<vector<int>> v(p, vector<int>()); 
        for(int i = 0; i < s.size(); ++i) {
            v[i % p].emplace_back(i); 
        }
        bool ok = false;
        for(int i = 0; i < p; ++i) {
            int a = 0, b = 0, c = 0;
            for(int x : v[i]) {
                a += s[x] == '1';
                b += s[x] == '0';
                c += s[x] == '.';
            }
            if(a == v[i].size() || b == v[i].size() || 
                    c == v[i].size() && c == 1) {
            }
            else {
                ok = true;
            }
            char go = '.';
            if(a) go = '0';
            else if(b) go = '1';
            for(int x : v[i]) {
                if(s[x] == '.') {
                    s[x] = go;
                    if(go == '.') {
                        s[x] = '1';
                        go = '0';
                    }
                }
            }
        }
        if(ok) {
           cout << s << endl; 
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}
