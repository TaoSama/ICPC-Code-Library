//
//  Created by TaoSama on 2016-08-21
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

map<pair<int, int>, int> mp;
int n, m;
int f[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        int p, w; scanf("%d%d", &p, &w);
        ++mp[ {p, w}];
    }

    vector<pair<pair<int, int>, int> > v(mp.begin(), mp.end());
    for(int i = 0; i < v.size(); ++i) {
        int num = v[i].second;
        int p, w; tie(p, w) = v[i].first;
        for(int k = 1; num > 0; k <<= 1) {
            int mul = min(k, num);
            for(int j = m; mul * p <= j; --j) {
                f[j] = max(f[j], f[j - mul * p] + mul * w);
            }
            num -= mul;
        }
    }
    int ans = *max_element(f, f + m + 1);
    printf("%d\n", ans);

    return 0;
}
