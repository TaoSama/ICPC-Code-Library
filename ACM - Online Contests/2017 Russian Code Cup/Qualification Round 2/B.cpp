//
//  Created by TaoSama on 2017-04-16
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
struct Frac {
    LL p, q;
    void read() {
        scanf("%lld%lld", &p, &q);
    }
    void write() {
        printf("%lld %lld\n", &p, &q);
    }
    Frac() {}
    Frac(LL p, LL q) : p(p), q(q) {
        LL g = __gcd(p, q);
        this->p /= g;
        this->q /= g;
    }
    Frac operator+(const Frac& f) const {
        return Frac(p * f.q + q * f.p, q * f.q);
    }
    Frac operator-(const Frac& f) const {
        return Frac(p * f.q - q * f.p, q * f.q);
    }
    Frac operator*(const Frac& f) const {
        return Frac(p * f.p, q * f.q);
    }
    Frac operator/(const Frac& f) const {
        return *this * Frac(f.q, f.p);
    }
    Frac operator%(const Frac& f) const {
        return *this - *this / f * f;
    }
};

LL lcm(LL a, LL b) {
    return a / __gcd(a, b) * b;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        LL a, b, c, d; scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        LL up = a * c, dw = __gcd(a * d, b * c);
        LL g = __gcd(up, dw);
        printf("%lld %lld\n", up / g, dw / g);
    }

    return 0;
}
