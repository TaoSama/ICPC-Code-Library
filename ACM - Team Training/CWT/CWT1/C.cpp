//
//  Created by TaoSama on 2016-01-19
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

typedef long long LL;

int n, k, a[N];
LL f[15][N], b[15][N];

void add(LL *b, int i, LL v) {
    for(; i <= n; i += i & -i) b[i] += v;
}

LL sum(LL *b, int i) {
    LL ret = 0;
    for(; i; i -= i & -i) ret += b[i];
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &k);
    ++k;
    for(int i = 1; i <= n; ++i) scanf("%d", a + i);
    for(int i = 1; i <= n; ++i) {
        f[1][a[i]] = 1; add(b[1], a[i], 1);
        for(int j = 2; j <= k; ++j) {
            f[j][a[i]] = sum(b[j - 1], a[i] - 1);
            add(b[j], a[i], f[j][a[i]]);
//          printf("f[%d][%d]=%I64d\n", j, a[i], f[j][a[i]]);
        }
    }
    printf("%I64d\n", sum(b[k], n));
    return 0;
}
