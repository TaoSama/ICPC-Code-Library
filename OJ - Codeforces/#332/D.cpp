//
//  Created by TaoSama on 2015-11-21
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

typedef long long LL;
typedef pair<LL, LL> P;

LL x;

LL f(LL n, LL m) {
    LL ret = n * n * m - (n - 1) * n / 2 * (n + m);
    ret += n * (n - 1) * (2 * n - 1) / 6;
    return ret;
}

LL getM(LL n) {
    LL t = x;
    t -= n * (n - 1) * (2 * n - 1) / 6 - (n - 1) * n * n / 2;
    LL m = t / (n * n - ((n - 1) * n / 2));
    return m;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

//  cout << f()
    while(scanf("%I64d", &x) == 1) {
        set<P> ans;
        LL to = x;
        for(LL n = 1; n <= to; ++n) {
            LL m = getM(n);
            to = m;
            if(f(n, m) != x) continue;
            if(ans.count(P(n, m))) break;
            ans.insert(P(n, m));
            ans.insert(P(m, n));
        }
        printf("%I64d\n", (LL)ans.size());
        for(auto &i : ans) printf("%I64d %I64d\n", i.first, i.second);
    }
    return 0;
}
