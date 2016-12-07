//
//  Created by TaoSama on 2016-11-28
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
int n, n1, n2;
LL a[N], s[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> n1 >> n2) {
        for(int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + 1 + n);
        double ans = 0;
        {
            double s1 = 0, s2 = 0;
            int i, j;
            for(i = n, j = 1; i >= 1 && j <= n1; --i, ++j) s1 += a[i];
            for(j = 1; i >= 1 && j <= n2; --i, ++j) s2 += a[i];
            ans = max(ans, s1 / n1 + s2 / n2);
        }
        {
            double s1 = 0, s2 = 0;
            int i, j;
            for(i = n, j = 1; i >= 1 && j <= n2; --i, ++j) s1 += a[i];
            for(j = 1; i >= 1 && j <= n1; --i, ++j) s2 += a[i];
            ans = max(ans, s1 / n2 + s2 / n1);
        }
        printf("%.12f\n", ans);
    }

    return 0;
}
