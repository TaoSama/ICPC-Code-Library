
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
    
    int s, v1, v2, t1, t2;
    while(cin >> s >> v1 >> v2 >> t1 >> t2){
        int a1 = s * v1 + 2 * t1;
        int a2 = s * v2 + 2 * t2;
        if(a1 == a2) cout << "Friendship\n";
        else cout << (a1 < a2 ? "First" : "Second") << '\n';
    }
    return 0;
}
