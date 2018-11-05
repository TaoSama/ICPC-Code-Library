
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

bool isVowel(char c) {
    const string s = "aeiou";
    return s.find(c) != string::npos;
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    string s;
    while(cin >> s) {
        s += '.';
        bool ok = true;
        bool need = false;
        for(char c : s) {
            if (need) {
                ok &= isVowel(c);
            }
            need = !isVowel(c) && c != 'n';
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}
