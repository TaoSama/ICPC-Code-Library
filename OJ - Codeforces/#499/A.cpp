
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int a[N], b[N];
int n, m;

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> n >> m) {
        for(int i = 1; i <= n; ++i) cin >> a[i];
        for(int i = 1; i <= n; ++i) cin >> b[i];
        a[n + 1] = a[1]; b[n + 1] = b[1];
        double lft = m;
        bool ok = true;
        for(int i = n; i >= 1; --i) {
            lft *= b[i + 1];
            lft /= b[i + 1] - 1;
            ok &= b[i + 1] - 1 > 0;
            lft *= a[i];
            lft /= a[i] - 1;
            ok &= a[i] - 1 > 0;
        }
        if(ok) {
            cout << fixed << setprecision(20) << lft - m << endl;
        }
        else cout << -1 << endl;
    }
    return 0;
}
