
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
    
    string s, t;
    int n, m;
    while(cin >> n >> m >> s >> t) {
        if (s == t) {
            cout << "YES\n";
        }
        else {
            int p = s.find("*");
            if(p == -1) {
                cout << "NO\n";
            }
            else {
                if(m >= n - 1) {
                    string a = s.substr(0, p);
                    string b = s.substr(p + 1);
                    if (t.find(a) == 0 && t.rfind(b) + b.size() == t.size()) {
                        cout << "YES\n";
                    }
                    else {
                        cout << "NO\n";
                    }
                }
                else {
                    cout << "NO\n";
                }
            }
        }
    }
    return 0;
}
