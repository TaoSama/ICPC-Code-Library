//
//  Created by TaoSama on 2017-04-23
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        int g = 0;
        for(int i = 1; i <= n; ++i) scanf("%d", a + i), g = __gcd(g, a[i]);
        if(g > 1) {printf("YES\n%d\n", 0); continue; }

        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            if(a[i] & 1) {
                if(i + 1 <= n)
                    ans += (a[i + 1] & 1) ? 1 : 2;
                else ans += 2;
                ++i;
            }
        }
        printf("YES\n%d\n", ans);
    }

    return 0;
}
