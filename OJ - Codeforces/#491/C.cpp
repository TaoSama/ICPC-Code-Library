
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

long long n;

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> n) {
        long long l = 1, r = n, ans = -1;
        while(l <= r) {
            long long m = (l + r) / 2;
            long long a = 0, sum = n;
            while(sum > 0) {
                a += min(sum, m);
                sum -= min(sum, m);
                sum -= sum / 10;
            }
            if (a * 2 >= n) ans = m, r = m - 1;
            else l = m + 1;
        }
        cout << ans << endl;
    }
    return 0;
}
