//
//  Created by TaoSama on 2017-04-22
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        int ans = INF, last = INF;
        for(int i = 1; i <= 2 * n - 2; ++i) {
            int x; scanf("%d", &x);
            if(i & 1) last = x;
            else {
                last += x;
                ans = min(ans, last);
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
