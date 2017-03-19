//
//  Created by TaoSama on 2017-03-19
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
int n, a[N], cnt[N];
LL k;

bool check(LL x) {
    for(int i = 1; i <= n; ++i) cnt[i] = 0;
    LL val = 0, sum = 0;
    for(int l = 1, r = 1; l <= n; ++l) {
        for(; r <= n && val + cnt[a[r]] < x; ++r) {
            val += cnt[a[r]];
            ++cnt[a[r]];
        }
        sum += r - l;
        if(sum >= k) break;
        val -= cnt[a[l]] - 1;
        --cnt[a[l]];
    }
    return sum < k;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%lld", &n, &k);
        vector<int> xs;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            xs.push_back(a[i]);
        }
        sort(xs.begin(), xs.end());
        xs.resize(unique(xs.begin(), xs.end()) - xs.begin());

        for(int i = 1; i <= n; ++i)
            a[i] = lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin() + 1;

        LL l = 0, r = 1LL * n * (n - 1) / 2, ans = -1;
        while(l <= r) {
            LL m = l + r >> 1;
            if(check(m)) ans = m, l = m + 1;
            else r = m - 1;
        }
        printf("%lld\n", ans);
    }

    return 0;
}
