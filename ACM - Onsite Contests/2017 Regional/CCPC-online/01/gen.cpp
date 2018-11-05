
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <cstdio>
#include <iostream>
#include <string>
#include <set>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;



int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    srand(reinterpret_cast<long long>(new int));
    int n = rand() % 400 + 30, m = rand() % 10000  + 500;
    printf("%d %d\n", n, m);
    set<pair<int,int>> s;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        do {
            u = rand() % 30 + 1;
            v = rand() % n + 1;
            if(u > v) swap(u, v);
        }while(s.count({u, v}));
        s.insert({u, v});
        printf("%d %d\n", u, v);
    }
    return 0;
}
