//
//  Created by TaoSama on 2017-06-10
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int cnt[300][300];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
        int dx = c - a, dy = d - b;
        int g = __gcd(abs(dx), abs(dy));
        dx /= g; dy /= g;
        for(int j = a, k = b; ; j += dx, k += dy) {
            cnt[j][k] = i;
//            printf("%d %d = %d\n", j, k, i);
            if(j == c) break;
        }
    }
    int q; scanf("%d", &q);
    while(q--) {
        int x, y; scanf("%d%d", &x, &y);
        printf("%d\n", cnt[x][y]);
    }

    return 0;
}
