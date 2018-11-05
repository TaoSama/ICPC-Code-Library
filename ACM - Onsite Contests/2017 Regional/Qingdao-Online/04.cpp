
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

struct Frac {
    LL p, q;
    Frac(LL p = 0, LL q = 1): p(p), q(q) {
        LL g = __gcd(p, q);
        this->p /= g;
        this->q /= g;
    }
    Frac operator+(const Frac& f) {
        return Frac(p * f.q + f.p * q, q * f.q); 
    }
    Frac operator-(const Frac& f) {
        return *this + Frac(-f.p, f.q);
    }
    Frac operator*(const Frac& f) {
        return Frac(p * f.p, q * f.q);
    }
    Frac operator/(const Frac& f) {
        return *this * Frac(f.q, f.p);
    }
    void see() {
        printf("%lld/%lld\n", p, q);
    }
};

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);

    // Frac a(1,2), b(1,3), c = a + b;
    // cout << c.p << ' ' << c.q << endl;
    
    int t; scanf("%d", &t);
    while(t--) {
        long long k; scanf("%lld", &k);
        if(k == 1) {
            puts("1/1");
            continue;
        }
        double rt = cbrt(k * k);
        // printf("rt = %.12f\n", rt);

        LL real = rt;
        rt = 1 / (rt - real);
        vector<LL> data; Frac ans;
        for(int i = 1; i <= 20; ++i) {
            LL r = rt;
            double dif = rt - r;
            data.insert(data.begin(), r);
            Frac cur;
            bool ok = true;
            for(LL x : data) {
                cur = Frac(1, 1) / (cur + Frac(x, 1));
                if(cur.q > 100000) ok = false;
            }
            // printf("...%lld\n", cur.q);
            if(ok) ans = cur;
            else break;
            if(abs(dif) < 1e-8) break;
            rt = 1 / (rt - r);
        }
        // printf("%.12f\n", real + 1.0 * ans.p/ans.q);
        (Frac(real, 1) + ans).see();
    }
    return 0;
}
