
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

long long n, m;

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> n >> m) {
        if(n > m) swap(n, m);
        if(n >= 3) {
            cout << n * m / 2 * 2 << endl;
        }
        else {
            if(n == 1) {
                m -= 1;
                if(m % 6 < 3) {
                    cout << m / 6 * 6 << endl;
                }
                else {
                    cout << m / 6 * 6 + (m % 6 - 2) * 2 << endl;;
                }
            }
            else if(n == 2) {
                if(m == 2) cout << 0 << endl;
                else if(m == 3) cout << 4 << endl;
                else if(m == 7) cout << 12 << endl;
                else {
                    cout << n * m << endl;
                }
            }
        }
    }
    return 0;
}
