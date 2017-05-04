//
//  Created by TaoSama on 2017-04-30
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
int n, k;

LL quick(LL x, LL n) {
    LL ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    multiset<LL> s;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i) {
        LL x; scanf("%lld", &x);
        s.insert(x);
    }

    LL maxv = 0;
    vector<LL> toDel; toDel.reserve(n);
    for(int i = 59; ~i; --i) {
        int one = 0;
        for(auto& x : s) one += x >> i & 1;
        if(one >= k) {
            maxv |= 1LL << i;
            toDel.clear();
            for(auto& x : s) if(~x >> i & 1) toDel.push_back(x);
            for(auto& x : toDel) s.erase(x);
        }
    }

    LL cnt = 1;
    n = s.size();
    for(int i = 0; i < k; ++i) {
        cnt = cnt * (n - i) % MOD;
        cnt = cnt * quick(i + 1, MOD - 2) % MOD;
    }
    printf("%lld\n%lld\n", maxv, cnt);


    return 0;
}
