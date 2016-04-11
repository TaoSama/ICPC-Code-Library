//
//  Created by TaoSama on 2015-09-13
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
const int M = 1e5 + 10;

typedef long long ll;

ll n, m, k;
ll a[12], mm[12];

ll quick_mod(ll a, ll b, ll p) {
    ll ans = 1;
    a %= p;
    while(b) {
        if(b & 1) ans = ans * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return ans;
}

ll C(ll n, ll m, ll p) {
    if(m > n) return 0;
    ll ans = 1;
    for(int i = 1; i <= m; i++) {
        ll a = (n + i - m) % p;
        ll b = i % p;
        ans = ans * (a * quick_mod(b, p - 2, p) % p) % p;
    }
    return ans;
}

ll Lucas(ll n, ll m, ll p) {
    if(m == 0) return 1;
    return C(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;
}

ll Extended_Euclid(ll a, ll b, ll &x, ll &y) {
    ll d;
    if(b == 0) {
        x = 1; y = 0;
        return a;
    }
    d = Extended_Euclid(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
ll mod_mul(ll a, ll b, ll mod) {
    ll ret = 0;
    while(b) {
        if(b & 1)    ret = (ret + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return ret;
}
ll CRT() {
    ll d, x, y, tmp, M, ret;
    ret = 0;
    M = 1;
    for(int i = 0; i < k; i++)
        M *= mm[i];
    for(int i = 0; i < k; i++) {
        tmp = M / mm[i];
        d = Extended_Euclid(mm[i], tmp, x, y);
        ll temp = mod_mul(y, tmp, M);
        temp = mod_mul(temp, a[i], M);
        ret = (ret + temp) % M;
        //ret=(ret+y*tmp*a[i])%M;
    }
    return (M + ret) % M;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while(T--) {
        cin >> n >> m >> k;
        for(int i = 0; i < k; i++) {
            cin >> mm[i];
            a[i] = Lucas(n, m, mm[i]);
        }
        cout << CRT() << endl;
    }
    return 0;
}
