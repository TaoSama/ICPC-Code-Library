
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int a[N], b[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n;
    while(cin >> n) {

        long long gcd = -1;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i] >> b[i];
            if (gcd == -1) {
                gcd = 1ll * a[i] * b[i];
            } else {
                gcd = __gcd(gcd, 1ll * a[i] * b[i]);
            }
        }
        if (gcd == 1) {
            cout << -1 << endl;
        } else {
            int ans = -1;
            for(int i = 1; i <= n; ++i) {
                if(gcd % a[i] == 0) {
                    ans = a[i];
                    break;
                }
                if(gcd % b[i] == 0) {
                    ans = b[i];
                    break;
                }
            }
            if (ans == -1) {
                for(int x = 2; 1ll * x * x <= gcd; ++x) {
                    if (gcd % x == 0) {
                        ans = x;
                        break;
                    }
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
