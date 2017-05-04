//
//  Created by TaoSama on 2017-04-09
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
typedef long long LL;
int f[50005];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        memset(f, 0, sizeof f);
        for(int i = 1; i <= n; ++i) {
            int h, c; scanf("%d%d", &h, &c);
            for(int j = 50000; j >= c; --j)
                f[j] = max(f[j], f[j - c] + h);
        }
        LL ans = 0;
        for(LL c = 0; c <= 50000; ++c) {
            LL h = f[c];
            ans = max(ans, h * h - h * c - c * c);
        }
        printf("%lld\n", ans);
    }

    return 0;
}
