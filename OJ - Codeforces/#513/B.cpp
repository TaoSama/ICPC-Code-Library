
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

long long n;
long long ten[100];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    ten[0] = 1;
    for(int i = 1; i <= 15; ++i) ten[i] = ten[i - 1] * 10;
    while(cin >> n) {
        long long ans = 0;
        for(int i = 0; i <= 15; ++i) {
            long long lft = n - ten[i] + 1; 
            if(lft < 0) continue;
            string o = to_string(ten[i] - 1);
            long long tmp = 0;
            for(char c : o) tmp += c - '0';
            o = to_string(lft);
            for(char c : o) tmp += c - '0';
            ans = max(ans, tmp);
        }
        cout << ans << endl;
    }
    return 0;
}
