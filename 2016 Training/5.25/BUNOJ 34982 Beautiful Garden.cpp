//
//  Created by TaoSama on 2015-09-25
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

int n, a[N];

int cal(int l, int r) {
    int d = a[r] - a[l];
    if(d == 0) return  n - (r - l + 1); //左右重合
    int ret = INF;
    for(int k = 2; k < n; ++k) { //枚举k个间距
        int cnt = 2;
        for(int i = l + 1; i < r; ++i) { //不重合
            if(a[i] != a[i - 1] && a[i] != a[r] && (a[i] - a[l]) * k % d == 0)
                ++cnt;
        }
        ret = min(ret, n - cnt);
    }
    return ret;
}

int main() {
#ifdef LOCAL
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        printf("Case #%d: ", ++kase);
        if(n <= 2) {
            puts("0");
            continue;
        }
        int ans = INF;
        sort(a + 1, a + 1 + n);
        for(int i = 1; i <= n; ++i)
            for(int j = i + 1; j <= n; ++j)
                ans = min(ans, cal(i, j));
        printf("%d\n", ans);
    }
    return 0;
}
