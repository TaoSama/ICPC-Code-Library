//
//  Created by TaoSama on 2016-04-08
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
pair<int, int> p[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d%d", &p[i].first, &p[i].second);
    map<pair<int, int>, int> mp;
    for(int i = 1; i <= n; ++i)
        for(int j = i + 1; j <= n; ++j)
            ++mp[ {p[i].first + p[j].first, p[i].second + p[j].second}];

    long long ans = 0;
    for(auto p : mp) ans += 1LL * (p.second) * (p.second - 1) / 2;
    printf("%I64d\n", ans);
    return 0;
}
