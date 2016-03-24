//
//  Created by TaoSama on 2015-07-29
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <algorithm>
#include <cassert>
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
const int N = 1e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

int maxd;
LL a, b, k, no[8], v[N], ans[N];

bool better(int d) {
    for(int i = d; i >= 0; --i)
        if(v[i] != ans[i])
            return ans[i] == -1 || v[i] < ans[i]; //minimize the largest
}

LL getFirst(LL a, LL b) {return b / a + (b % a != 0);}

bool isLegal(LL x) {
    for(int i = 1; i <= k; ++i)
        if(x == no[i]) return false;
    return true;
}

bool dfs(LL from, LL a, LL b, int dep) {
    if(dep == maxd) {
        if(b % a || !isLegal(b / a)) return false;
        v[dep] = b / a;
        if(better(dep)) memcpy(ans, v, sizeof(LL) * (dep + 1));
        return true;
    }
    bool ok = false;
    from = max(from, getFirst(a, b));
    for(LL i = from; ; ++i) {
        if(!isLegal(i)) continue;
        //left * 1 / i <= a / b -> pruning
        if(b * (maxd - dep + 1) <= i * a) break;
        v[dep] = i;
        //compute a / b - 1 / i
        LL b2 = b * i, a2 = a * i - b;
        LL gcd = __gcd(a2, b2);

        if(dfs(i + 1, a2 / gcd, b2 / gcd, dep + 1)) ok = true;
    }
    return ok;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%lld%lld%lld", &a, &b, &k);
        for(int i = 1; i <= k; ++i) scanf("%lld", no + i);
        for(int i = 1; i <= k; ++i) assert(no[i] <= 1000);
        for(maxd = 1; ; maxd++) {
            memset(ans, -1, sizeof ans);
            if(dfs(getFirst(a, b), a, b, 0)) break;
        }
        printf("Case %d: %lld/%lld=", ++kase, a, b);
        for(int i = 0; i <= maxd; ++i)
            printf("1/%lld%c", ans[i], i == maxd ? '\n' : '+');
    }
    return 0;
}
