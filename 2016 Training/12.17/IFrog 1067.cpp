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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
LL f[20][20][20];
int a, b, p, digit[20];

LL dfs(int i, int s, int c, int e) {
    if(!i) return c;
    if(!e && ~f[i][s][c]) return f[i][s][c];
    int to = e ? digit[i] : 9;
    LL ret = 0;
    for(int d = 0; d <= to; ++d) {
        ret += dfs(i - 1, d, c + (d == p), e && d == to);
    }
    return e ? ret : f[i][s][c] = ret;
}

LL calc(int x) {
    int cnt = 0;
    for(; x; x /= 10) digit[++cnt] = x % 10;
    return dfs(cnt, 0, 0, 1);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    memset(f, -1, sizeof f);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &a, &b, &p);
        printf("%lld\n", calc(b) - calc(a - 1));
    }

    return 0;
}
