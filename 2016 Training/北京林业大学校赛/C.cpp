//
//  Created by TaoSama on 2016-04-24
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

int n, a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        vector<int> v(n + 1, 1);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        for(int i = 1; i <= n; ++i) {
            if(i > 1 && a[i] > a[i - 1]) v[i] = max(v[i], v[i - 1] + 1);
            if(i < n && a[i] > a[i + 1]) v[i] = max(v[i], v[i + 1] + 1);
        }
        for(int i = n; i; --i) {
            if(i > 1 && a[i] > a[i - 1]) v[i] = max(v[i], v[i - 1] + 1);
            if(i < n && a[i] > a[i + 1]) v[i] = max(v[i], v[i + 1] + 1);
        }
//        for(int x : v) printf("%d ", x); puts("");
        int ans = accumulate(v.begin() + 1, v.end(), 0);
        printf("%d\n", ans);
    }
    return 0;
}
