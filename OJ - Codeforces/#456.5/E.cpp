
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

string f[1 << 8], t[1 << 8], e[1 << 8];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    f[0b00001111] = "x";
    f[0b00110011] = "y";
    f[0b01010101] = "z";
    bool ok = true;
    while(ok) {
        ok = false;
        static auto cmp = [](string& x, const string& y) {
            if(x.empty() || x.size() > y.size() || (x.size() == y.size() && x > y)) {
                x = y;
                return true;
            }
            return false;
        };

        for(int i = 0; i < 1 << 8; ++i) if(f[i].size()) ok |= cmp(f[i ^ 255], string("!") + f[i]);
        for(int i = 0; i < 1 << 8; ++i) if(e[i].size()) ok |= cmp(f[i], string("(") + e[i] + ")");
        for(int i = 0; i < 1 << 8; ++i) if(f[i].size()) ok |= cmp(t[i], f[i]);
        for(int i = 0; i < 1 << 8; ++i) if(t[i].size()) ok |= cmp(e[i], t[i]);

        for(int i = 0; i < 1 << 8; ++i) {
            for(int j = 0; j < 1 << 8; ++j) {
                if(t[i].size() && f[j].size()) {
                    ok |= cmp(t[i & j], t[i] + "&" + f[j]);
                }
                if(e[i].size() && t[j].size()) {
                    ok |= cmp(e[i | j], e[i] + "|" + t[j]);
                }
            }
        }
    }
    for(int i = 0; i < 1 << 8; ++i) if(!e[i].size()) { cout << "fuck=" << i << endl; break;}

    int n; 
    while(cin >> n) {
        for(int i = 1; i <= n; ++i) {
            string s; cin >> s;
            int x = 0;
            for(int i = 0; i < 8; ++i) x |= (s[i] - '0') << (7 - i);
            cout << e[x] << '\n';
        }
    }
    return 0;
}
