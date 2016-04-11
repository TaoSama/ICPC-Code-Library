//
//  Created by TaoSama on 2015-09-24
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

vector<LL> all;
LL l, r;

int getLen(LL x) {
    int ret = 0;
    for(; x; x /= 10) ++ret;
    return ret;
}

void dfs(LL x) {
    for(int i = 2; i < 20; ++i) {
        if(1.0 * x * i > 1e18) break;
        LL y = x * i;
        if(i == getLen(y)) {
            all.push_back(y);
            dfs(y);
        }
    }
}

void gao() {
    for(int i = 0; i < 10; ++i) {
        all.push_back(i);
        if(i >= 5) dfs(i);
    }
    sort(all.begin(), all.end());
//  for(auto v : all) printf("%lld ", v); puts("");
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    gao();
    while(scanf("%lld%lld", &l, &r) == 2) {
        int ans = upper_bound(all.begin(), all.end(), r) -
                  lower_bound(all.begin(), all.end(), l);
        printf("%d\n", ans);
    }
    return 0;
}
