//
//  Created by TaoSama on 2016-03-06
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

int n, m, k, t, q;
int a[105], b[105];
typedef long long LL;

LL f[10005];
const LL INFLL = 0x3f3f3f3f3f3f3f3fLL;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &q);
    while(q--) {
        scanf("%d%d%d%d", &n, &m, &k, &t);
        for(int i = 1; i <= m; ++i) scanf("%d", a + i);
        for(int i = 1; i <= m; ++i) scanf("%d", b + i);
        LL ans = 0;
        bool can = true;
        while(n--) {
            memset(f, 0x3f, sizeof f);
            f[0] = 0;
            LL cur = INFLL;
            for(int i = 1; i <= m; ++i)
                for(int j = 0; j <= k; ++j)
                    if(j + b[i] > k) cur = min(cur, f[j] + a[i]);
                    else f[j + b[i]] = min(f[j + b[i]], f[j] + a[i]);
            cur = min(cur, f[k]);
            if(cur == INFLL) {can = false; break;}
            ans += cur;
            for(int i = 1; i <= m; ++i) b[i] /= t;
        }
        if(can) printf("%lld\n", ans);
        else puts("No Answer");
    }
    return 0;
}
