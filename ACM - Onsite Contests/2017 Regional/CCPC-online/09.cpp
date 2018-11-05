//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int R1, R2;
typedef long double LDB;
LDB getFourth(LDB r1, LDB r2, LDB r3) {
    LDB k1 = r1, k2 = -r2, k3 = r3;
    LDB k4 = k1 + k2 + k3 + 2 * sqrt(abs(k1 * k2 + k2 * k3 + k1 * k3));
    return k4;
}
const LDB EPS = 5e-7;

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &R1, &R2, &n);
        if(R1 > R2) swap(R1, R2);
        if(R1 == R2) n = 0;
        LDB last = R2 - R1;
        LDB sum = last * last;

        --n;
        LDB r1 = 1.0 / R1;
        LDB r2 = 1.0 / R2;
        last = 1.0 / last;
        for(int i = 1; i <= n; i += 2) {
            last = getFourth(r1, r2, last);
            LDB r = 1.0 / last;
            // return 0;
            // printf("%d = %f\n", i, last);
            if(abs(r) < EPS) {
                // printf("%d\n", i);
                break;
            }
            sum += r * r;
            if(i + 1 <= n) sum += r * r;
        }
        printf("%.5f\n", double(acos(-1) * sum));
    }
    return 0;
}
