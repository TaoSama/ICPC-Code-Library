//
//  Created by TaoSama on 2016-01-15
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
LL n, A, cf, cm, m;
LL a[N], b[N], r[N], pre[N], suf[N];

bool cmp(int x, int y) {
    return a[x] > a[y];
}

bool check(LL x, int i) {
	LL lft = m - pre[i];
    int idx = upper_bound(b + 1, b + 1 + n - i, x) - b - 1;
//    pr(x); pr(lft); printf("suf[%d] = %I64d\n", idx, suf[idx]);
    return lft >= x * idx - suf[idx];
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
//    ios_base::sync_with_stdio(0);

    while(scanf("%I64d%I64d%I64d%I64d%I64d", &n, &A, &cf, &cm, &m) == 5) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i), b[i] = a[i], r[i] = i;
        sort(r + 1, r + 1 + n, cmp);
        sort(b + 1, b + 1 + n);
        for(int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1] + (A - b[n - i + 1]);
            suf[i] = suf[i - 1] + b[i];
//            printf("%d: %I64d %I64d\n", i, pre[i], suf[i]);
        }
//        check(5, 4);

        LL ans = -INF, ans1, ans2;
        for(int i = 0; i <= n; ++i) {
            if(pre[i] > m) break;
            int l = 0, r = A;
            while(l <= r) {
                int mid = l + r >> 1;
                if(check(mid, i)) l = mid + 1;
                else r = mid - 1;
            }
            --l;
//            pr(i); pr(m - pre[i]); prln(l);
//            if(i >= n - idx + 1) l = A;
            LL cur = i * cf + l * cm;
            if(cur > ans) {
                ans = cur;
                ans1 = i;
                ans2 = l;
            }
        }
        for(int i = 1; i <= ans1; ++i) a[r[i]] = A;
        printf("%I64d\n", ans);
        for(int i = 1; i <= n; ++i) {
            if(a[i] < ans2) a[i] = ans2;
            printf("%I64d%c", a[i], " \n"[i == n]);
        }
    }
    return 0;
}
