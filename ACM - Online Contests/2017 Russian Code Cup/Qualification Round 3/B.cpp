//
//  Created by TaoSama on 2017-04-29
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int H, A, n, hp[N], atk[N];
typedef long long LL;
LL d[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &H, &A);
        vector<int> r(n);
        for(int i = 1; i <= n; ++i) r[i - 1] = i;
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d", hp + i, atk + i);
//            pr(hp[i]); prln(atk[i]);
            d[i] = 1LL * atk[i] * ((hp[i] + A - 1) / A);
//            prln(d[i]);
        }
        sort(r.begin(), r.end(), [](int x, int y) {
            return d[x] > d[y];
        });

        int ans = -1;
        for(int i = 1; i <= n && !~ans; ++i) {
//          prln(d[r[i-1]]);
//          pr(hp[r[i-1]]); prln(atk[r[i-1]]);
            if(H <= d[r[i - 1]]) {
                ans = i - 1;
            } else H -= d[r[i - 1]];
        }
        printf("%d\n", ans);
    }

    return 0;
}
