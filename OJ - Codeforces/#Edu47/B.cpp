
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
    
    string s;
    while(cin >> s) {
        string ans, one;
        for(char c : s) {
            if(c == '1') one += c;
            else ans += c;
        }
        for(char c : ans) {
            if(c == '2') {
                cout << one;
                one.clear();
            }
            cout << c;
        }
        cout << one << endl;
    }
    return 0;
}
