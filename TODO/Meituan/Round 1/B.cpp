//
//  Created by TaoSama on 2017-06-11
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;



int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int n;
    while(scanf("%d", &n) == 1) {
        int c = 0, t = -1;
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            if(i == 1) t = x;
            else c += x <= t;
        }
        int ans = 0;
        int g = n - 1 - c;
        while(c > 0) {
            --c;
            if(c & 1) --g;
            c >>= 1;
            g >>= 1;
            ++ans;
        }
        printf("%d\n", ans);
    }

    return 0;
}
