
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int k;
char s[10][10], pattern[20];
map<pair<pair<int, int>, string>, long long> mp;

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> k >> (pattern + 1); 
    for(int i = 1; i <= 8; ++i) cin >> (s[i] + 1);
    for(int i = 1; i <= 8; ++i) {
        for(int j = 1; j <= 8; ++j) {
            dfs(i, j) 
        }
    }
    return 0;
}
