//
//  Created by TaoSama on 2016-02-16
//  Copyright (c) 2016 TaoSama. All rights reserved.
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

int n;
int f[N], g[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    memset(g, 0x3f, sizeof g);
    for(int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        int k = lower_bound(g + 1, g + 1 + n, x) - g;
        g[k] = x;
        f[i] = k;
    }
    int ans = *max_element(f + 1, f + 1 + n);
    printf("%d\n", ans);
    return 0;
}
