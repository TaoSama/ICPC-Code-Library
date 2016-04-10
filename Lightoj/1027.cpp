//
//  Created by TaoSama on 2015-11-02
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct Frac {
    int p, q;
    Frac(int a = 0, int b = 1): p(a), q(b) {
        int gcd = __gcd(p, q);
        p /= gcd; q /= gcd;
    }
    Frac operator* (const Frac& f) const {
        return Frac(p * f.p, q * f.q);
    }
    Frac operator+ (const Frac& f) const {
        return Frac(p * f.q + f.p * q, q * f.q);
    }
    bool operator< (const Frac& f) const {
        return p * f.q < f.p * q;
    }
    void print() {printf("%d/%d\n", p, q);}
};

int n, x;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d", &n);
        int sum = 0, cnt = 0;
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            if(x > 0) ++cnt, sum += x;
            else sum += -x;
        }
        if(!cnt) printf("Case %d: inf\n", ++kase);
        else {
            Frac ans = Frac(sum, cnt);
            printf("Case %d: %d/%d\n", ++kase, ans.p, ans.q);
        }
    }
    return 0;
}
