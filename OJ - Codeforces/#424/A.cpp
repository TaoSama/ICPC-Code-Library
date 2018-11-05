
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;



int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n;
    while(cin >> n){
        int ok = 1, t = 0;
        int last = -1;
        for(int i = 1; i <= n; ++i){
            int x; cin >> x;
            if(i > 1){
                int tt = x < last ? 2 : x == last;
                if(tt < t) ok = 0;
                t = tt;
            }
            last = x;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}
