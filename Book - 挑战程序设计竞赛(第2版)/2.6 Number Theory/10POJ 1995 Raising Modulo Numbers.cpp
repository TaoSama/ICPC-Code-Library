//
//  POJ 1995 Raising Modulo Numbers
//
//  Created by TaoSama on 2015-03-23
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
#define CLR(x,y) memset(x, y, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

long long n, m;
long long ksm(long long x, long long n, long long m) {
    long long ret = 1;
    while(n) {
        if(n & 1) ret = ret * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        int mod, n; cin >> mod >> n;
        long long ans = 0;
        for(int i = 1; i <= n; ++i) {
            long long a, b; cin >> a >> b;
            ans = (ans + ksm(a, b, mod)) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}
