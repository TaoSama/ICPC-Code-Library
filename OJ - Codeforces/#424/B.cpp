
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <cstdio>
#include <iostream>
#include <string>
#include <cctype>
#include <map>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;



int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    string s, t;
    while(cin >> s >> t){
        map<char, char> mp;
        string x; cin >> x;
        for(size_t i = 0; i < s.size(); ++i){
            char c1 = s[i], c2 = t[i];
            mp[c1] = c2;
        }
        for(char& c : x){
            if(isupper(c)){
                c = toupper(mp[tolower(c)]);
            }
            else if(islower(c)){
                c = mp[c];
            }
        }
        cout << x << endl;
    }
    return 0;
}
