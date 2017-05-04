//
//  Created by TaoSama on 2017-04-28
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int f[1 << 20];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &m);
    for(int s = 1; s < 1 << n; ++s) f[s] = -INF;
    for(int i = 1; i <= m; ++i) {
        int x; scanf("%d", &x); --x;
        for(int s = 0; s < 1 << n; ++s) {
            if(s >> x & 1) continue;
            int small = 0;
            for(int j = x + 1; j < n; ++j) small += s >> j & 1;
            f[s | 1 << x] = max(f[s | 1 << x], f[s] + small);
        }
    }
    printf("%d\n", f[(1 << n) - 1]);

    return 0;
}
