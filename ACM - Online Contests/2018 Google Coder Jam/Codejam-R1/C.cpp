
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int p;
int w[N], h[N];
double f[N];

const double EPS = 1e-8;
int sgn(double x) {
    return x < -EPS ? -1 : x > EPS;
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        cin >> n >> p;
        int sum = 0, maxv = 0;
        for(int i = 1; i <= n; ++i) {
            cin >> w[i] >> h[i];
            sum += (w[i] + h[i]) * 2;
            maxv += min(w[i], h[i]) * 2;
        }
        for(int i = 1; i < N; ++i) f[i] = -INF - 1;
        f[0] = 0;
        for(int i = 1; i <= n; ++i) {
            int W = min(w[i], h[i]) * 2;
            double v = sqrt(w[i] * w[i] + h[i] * h[i]) * 2;
            for(int j = maxv; j >= W; --j) {
                f[j] = max(f[j], f[j - W] + v);
            }
        }
        // for(int i = 0; i <= 10; ++i) cout << i << " = " << f[i] << endl;
        double ans = sum;
        for(int j = 0; j <= min(p - sum, maxv); ++j) {
            ans = max(ans, f[j] + sum);
        }
        static int kase = 0;
        cout << "Case #" << ++kase << ": " << fixed << setprecision(20) << min(1.0 * p, ans) << endl;
    }
    return 0;
}
