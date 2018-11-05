
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, x[N], y[N];

double check(double m) {
    double r = 0;    
    for(int i = 1; i <= n; ++i) {
        double tr = 1. * (x[i] - m) * (x[i] - m) + 1. * y[i] * y[i];
        tr /= 2. * y[i];
        r = max(r, tr);
    }
    return r;
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> n) {
        bool c1 = false;
        bool c2 = false;
        for(int i = 1; i <= n; ++i) {
            cin >> x[i] >> y[i];
            if(y[i] > 0) c1 = true;
            if(y[i] < 0) c2 = true;
        }
        if(c1 && c2) {
            cout << -1 << endl;
            continue;
        }
        if(c2) {
            for(int i = 1; i <= n; ++i) y[i] *= -1;
        }

        double l = -1e9, r = 1e9;
        for(int i = 1; i <= 100; ++i) {
            double ll = (2 * l + r) / 3;
            double rr = (2 * r + l) / 3;
            if(check(ll) > check(rr)) l = ll;
            else r = rr;
        }
        cout << fixed << setprecision(20) << check(l) << endl;
    }
    return 0;
}
