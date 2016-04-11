//
//
//  Created by TaoSama on 2016-02-22
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

int n, f[400], m[400];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        memset(f, 0, sizeof f);
        memset(m, 0, sizeof m);
        for(int i = 1; i <= n; ++i) {
            char g[2]; int a, b;
            scanf("%s%d%d", g, &a, &b);
            if(*g == 'M') ++m[a], --m[b + 1];
            else ++f[a], --f[b + 1];
        }
        int ans = 0;
        for(int i = 1; i <= 366; ++i) {
            f[i] += f[i - 1];
            m[i] += m[i - 1];
            ans = max(ans, min(f[i], m[i]) << 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}
