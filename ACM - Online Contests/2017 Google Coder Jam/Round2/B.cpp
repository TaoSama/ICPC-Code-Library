//
//  Created by TaoSama on 2017-05-13
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, c, m;
int p[N], b[N];

int check(int k) {
    vector<int> cnt(n + 1, 0);
    for(int i = 1; i <= m; ++i) ++cnt[p[i]];
    vector<int> bk = cnt;
    int promotion = 0;
    for(int i = n; i; --i) {
        if(cnt[i] > k) {
            if(i == 1) return -1;
            cnt[i - 1] += cnt[i] - k;
            cnt[i] = k;
        }
    }
    for(int i = 1; i <= n; ++i) promotion += abs(cnt[i] - bk[i]);
    return promotion / 2;
}

int main() {
#ifdef LOCAL
    freopen("B-large-practice.in", "r", stdin);
    freopen("B-large-practice.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &c, &m);
        vector<int> buy(c + 1, 0);
        for(int i = 1; i <= m; ++i) {
            scanf("%d%d", p + i, b + i);
            ++buy[b[i]];
        }
        int l = 1, r = m, ans = -1;
        for(int i = 1; i <= c; ++i) l = max(l, buy[i]);
        while(l <= r) {
            int m = l + r >> 1;
            if(check(m) != -1) ans = m, r = m - 1;
            else l = m + 1;
        }
        static int kase = 0;
        printf("Case #%d: %d %d\n", ++kase, ans, check(ans));
    }

    return 0;
}
