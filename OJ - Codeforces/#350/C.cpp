//
//  Created by TaoSama on 2016-05-05
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int b[N], c[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        map<int, int> mp;
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            ++mp[x];
        }
        scanf("%d", &m);
        pair<pair<int, int>, int> ans = {{ -1, -1}, -1};
        for(int i = 1; i <= m; ++i) scanf("%d", b + i);
        for(int i = 1; i <= m; ++i) scanf("%d", c + i);

        for(int i = 1; i <= m; ++i)
            ans = max(ans, {{mp[b[i]], mp[c[i]]}, i});
        printf("%d\n", ans.second);
    }
    return 0;
}
