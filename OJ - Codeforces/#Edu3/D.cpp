//
//  Created by TaoSama on 2015-12-20
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
typedef pair<LL, int> P;

int n, m, k, s;
P a[N], b[N];
P one[N], two[N];
int cnt1, cnt2, ans, ans1, ans2;

bool check(int x) {
    LL dollar = a[x].first, pound = b[x].first;
    for(int i = 0; i <= k && i <= cnt1; ++i) {
        if(k - i > cnt2) continue;
        LL sum = one[i].first * dollar + two[k - i].first * pound;
        if(sum <= s) {
            ans = i;
            ans1 = a[x].second;
            ans2 = b[x].second;
            return true;
        }
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d%d", &n, &m, &k, &s) == 4) {
        a[0].first = b[0].first = INF;
        for(int i = 1; i <= n; ++i) {
            scanf("%I64d", &a[i].first);
            a[i].second = a[i - 1].second;
            if(a[i].first < a[i - 1].first)
                a[i].second = i;
            else a[i].first = a[i - 1].first;
        }
        for(int i = 1; i <= n; ++i) {
            scanf("%I64d", &b[i].first);
            b[i].second = b[i - 1].second;
            if(b[i].first < b[i - 1].first)
                b[i].second = i;
            else b[i].first = b[i - 1].first;
        }

        cnt1 = cnt2 = 0;
        for(int i = 1; i <= m; ++i) {
            int x, y; scanf("%d%d", &x, &y);
            if(x == 1) one[++cnt1] = P(y, i);
            else two[++cnt2] = P(y, i);
        }
        sort(one + 1, one + 1 + cnt1);
        sort(two + 1, two + 1 + cnt2);
        for(int i = 1; i <= cnt1; ++i)
            one[i].first += one[i - 1].first;
        for(int i = 1; i <= cnt2; ++i)
            two[i].first += two[i - 1].first;

        int l = 1, r = n;
        while(l <= r) {
            int m = l + r >> 1;
            if(check(m)) r = m - 1;
            else l = m + 1;
        }

        if(l == n + 1) puts("-1");
        else {
            printf("%d\n", l);
            for(int i = 1; i <= ans; ++i)
                printf("%d %d\n", one[i].second, ans1);
            for(int i = 1; i <= k - ans; ++i)
                printf("%d %d\n", two[i].second, ans2);
        }
    }
    return 0;
}
