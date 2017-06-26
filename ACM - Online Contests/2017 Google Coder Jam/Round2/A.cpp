//
//  Created by TaoSama on 2017-05-13
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, p, g[N];

int main() {
#ifdef LOCAL
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &p);
        int cnt[5] = {};
        for(int i = 1; i <= n; ++i) scanf("%d", g + i), g[i] %= p, ++cnt[g[i]];
        int ans = 0;
        if(p == 2) {
            ans += cnt[0] + (cnt[1] + 1) / 2;
        } else if(p == 3) {
            int l = min(cnt[1], cnt[2]);
            ans += cnt[0] + l;
            cnt[1] -= l;
            cnt[2] -= l;
            ans += (cnt[1] + 2) / 3 + (cnt[2] + 2) / 3;
        } else {
            int l = min(cnt[1], cnt[3]);
            ans += cnt[0] + cnt[2] / 2 + l;
            cnt[2] %= 2;
            cnt[1] -= l;
            cnt[3] -= l;
            int o = cnt[1] ? 1 : 3;
            ans += cnt[o] / 4;
            cnt[o] %= 4;
            if(cnt[2]) {
                if(cnt[o] < 3) ++ans;
                else ans += 2;
            } else {
                ans += !!cnt[o];
            }

        }

        static int kase = 0;
        printf("Case #%d: %d\n", ++kase, ans);

    }

    return 0;
}
