//
//  Created by TaoSama on 2016-12-17
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
typedef long long LL;
const LL LLINF = 0x3f3f3f3f3f3f3f3fLL;
LL s[N], cof[10];
LL f[N][N];
int p[N][N];

LL calc(LL x) {
    LL ret = 0;
    for(int i = m; ~i; --i) ret = ret * x + cof[i];
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", s + i);
            s[i] += s[i - 1];
        }
        scanf("%d", &m);
        for(int i = 0; i <= m; ++i) scanf("%lld", cof + i);

        for(int i = 1; i <= n; ++i) f[i][i] = 0, p[i][i] = i;
        for(int l = 1; l < n; ++l) {
            for(int i = 1; i + l <= n; ++i) {
                int j = i + l;
                LL tmp = LLINF;
                int pos = 0;
                LL cost = calc(s[j] - s[i - 1]);
                for(int k = p[i][j - 1]; k <= p[i + 1][j]; ++k) {
                    if(f[i][k] + f[k + 1][j] + cost < tmp) {
                        tmp = f[i][k] + f[k + 1][j] + cost;
                        pos = k;
                    }
                }
                f[i][j] = tmp;
                p[i][j] = pos;
            }
        }
        printf("%lld\n", f[1][n]);
    }
    return 0;
}
