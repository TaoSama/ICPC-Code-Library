
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
    
    int n; 
    while(cin >> n) {
        multiset<string> s;
        for(int i = 1; i <= n; ++i) {
            string x; cin >> x;
            s.insert(x);
        }
        for(int i = 1; i <= n; ++i) {
            string x; cin >> x;
            auto iter = s.find(x);
            if(iter != s.end()) s.erase(iter);
        }
        cout << s.size() << endl;
    }
    return 0;
}
