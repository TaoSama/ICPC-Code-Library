
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, r;
int a[N];
double y[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> r;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        y[i] = r;
        for(int j = i - 1; j >= 1; --j) {
            if(a[i] >= a[j] - 2 * r && a[i] <= a[j] + 2 * r) {
                y[i] = max(y[i], sqrt(abs(4.0 * r * r - abs(a[j] - a[i]) * abs(a[j] - a[i]))) + y[j]);
            }
        }
    }
    for(int i = 1; i <= n; ++i) cout << fixed << setprecision(12) << y[i] << " \n"[i == n];
    return 0;
}
