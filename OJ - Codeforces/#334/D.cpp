//
//  Created by TaoSama on 2015-12-02
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
int p, k;
bool vis[N];

LL ksm(LL x, int n) {
    LL ret = 1;
    for(; n; n >>= 1, (x *= x) %= MOD)
        if(n & 1)(ret *= x) %= MOD;
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &p, &k) == 2) {
        if(k == 0) printf("%lld\n", ksm(p, p - 1));
        else if(k == 1) printf("%lld\n", ksm(p, p));
        else {
            int cnt = 0;
            for(int i = 1; i < p; ++i) {
                if(vis[i]) continue;
                for(LL j = i; !vis[j]; j = k * j % p) vis[j] = true;
                ++cnt;
            }
            printf("%lld\n", ksm(p, cnt));
        }
    }
    return 0;
}
