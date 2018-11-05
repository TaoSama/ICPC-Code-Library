
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
    
    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d", &n);
        vector<int> bad(N * 10), a(n), b;
        for(int& x : a) scanf("%d", &x);
        for(size_t i = 1; i < bad.size(); ++i) {
            if(bad[i]) continue;
            b.push_back(i);
            if(b.size() == n) break;
            for(int x : a) {
                for(int y : a) {
                    int z = i + x - y;
                    if(z >= 1 && z < bad.size()) bad[z] = true;
                }
            }
        }
        puts("YES");
        for(int i = 0; i < n; ++i) printf("%d%c", b[i], " \n"[i + 1 == n]);
    }
    return 0;
}
