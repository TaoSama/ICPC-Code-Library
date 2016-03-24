//
//  Created by TaoSama on 2016-01-31
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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

int n, p, len[N];
typedef pair<int, int> P;
typedef long long LL;
P a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &p) == 2) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d", &a[i].first, &a[i].second);
            len[i] = (a[i].second - a[i].first + 1);
        }
        a[n + 1] = a[1]; len[n + 1] = len[1];
        double ans = 0;
        for(int i = 1; i <= n; ++i) {
            LL l = a[i].second / p - (a[i].first - 1) / p;
            LL r = a[i + 1].second / p - (a[i + 1].first - 1) / p;
            double tmp = l * len[i + 1] + r * len[i] - l * r;
            ans += tmp / len[i] / len[i + 1];
        }
        printf("%.20f\n", 2000 * ans);
    }
    return 0;
}
