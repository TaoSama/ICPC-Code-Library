//
//  Created by TaoSama on 2015-10-11
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

int n;
typedef pair<double, double> P;
P a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%lf%lf", &a[i].first, &a[i].second);
        sort(a + 1, a + 1 + n);
        double ans = 0;
        for(int i = 2; i <= n; ++i) {
            ans = max(ans, abs(a[i].second - a[i - 1].second) / (a[i].first - a[i -
                      1].first));
        }
        printf("Case #%d: %.2f\n", ++kase, ans);
    }
    return 0;
}
