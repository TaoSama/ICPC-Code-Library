
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

long long n, k;

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> n >> k){
        int ans = -1;
        if(k <= n){
            ans = k;
        }
        else{
            k -= n;
            k = (k - 1) % (2 * n - 2) + 1;
            if(k <= n - 1){
                ans = k;
            }
            else{
                k -= n - 1;
                if(k <= n - 2){
                    ans = k;
                }
                else ans = n;
            }
        }
        static int kase = 0;
        cout << "Case #" << ++kase << ": " << ans << '\n';
    } 
    return 0;
}
