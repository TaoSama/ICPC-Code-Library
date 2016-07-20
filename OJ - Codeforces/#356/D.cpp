//
//  Created by TaoSama on 2016-06-09
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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
LL m;
vector<LL> c;
map<LL, pair<LL, LL> > f;

pair<LL, LL> dfs(LL x) {
    if(!x) return {0, 0};
    if(f.count(x)) return f[x];

    auto& ret = f[x];
    LL cur = *(--upper_bound(c.begin(), c.end(), x));
    ret = dfs(cur - 1);

    LL p, q; tie(p, q) = dfs(x - cur);
    ret = max(ret, {p + 1, q + cur});
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    for(int i = 1; i <= 1e5; ++i) c.push_back(1LL * i * i * i);
    while(scanf("%I64d", &m) == 1) {
        LL x, y; tie(x, y) = dfs(m);
        printf("%I64d %I64d\n", x, y);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
