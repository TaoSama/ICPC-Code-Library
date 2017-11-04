//
//  Created by TaoSama on 2015-06-27
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = N * 16;

int n, q, a[N], s[N], root[N], tim;
int lson[M], rson[M], cnt[M];
long long lef, num, tot[N], sum[M];

void insert(int o, int v, int l, int r, int pre, int &rt) {
    rt = ++tim;
    cnt[rt] = cnt[pre] + 1; sum[rt] = sum[pre] + v;
    if(l == r) return;
    lson[rt] = lson[pre], rson[rt] = rson[pre];
    int m = l + r >> 1;
    if(o <= m) insert(o, v, l, m, lson[pre], lson[rt]);
    else insert(o, v, m + 1, r, rson[pre], rson[rt]);
}

int query(int L, int R, int k, int l, int r) {
    if(l == r) return l;
    int lcnt = cnt[lson[R]] - cnt[lson[L]];
    int m = l + r >> 1;
    if(lcnt >= k) return query(lson[L], lson[R], k, l, m);
    else {
        lef += sum[lson[R]] - sum[lson[L]];
        num += lcnt;
        return query(rson[L], rson[R], k - lcnt, m + 1, r);
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            s[i] = a[i];
            tot[i] = tot[i - 1] + a[i];
        }
        sort(s + 1, s + 1 + n);
        int h = unique(s + 1, s + 1 + n) - s - 1;

        tim = 0; root[0] = 0;
        for(int i = 1; i <= n; ++i) {
            int o = lower_bound(s + 1, s + 1 + h, a[i]) - s;
            insert(o, a[i], 1, h, root[i - 1], root[i]);
        }
        scanf("%d", &q);
        printf("Case #%d:\n", ++kase);
        while(q--) {
            int l, r; scanf("%d%d", &l, &r);
            ++l, ++r;
            lef = num = 0;
            int k = (r - l) / 2 + 1, m = s[query(root[l - 1], root[r], k, 1, h)];
//          pr(num); prln(lef);
            if(k - 1 > num) lef += (k - 1 - num) * m;
            else lef -= (num - (k - 1)) * m;
            long long rig = tot[r] - tot[l - 1] - lef - m;
            long long ans = rig - lef - (r - l & 1 ? m : 0);
//          pr(m); pr(lef); prln(rig);
            printf("%I64d\n", ans);
        }
        putchar('\n');
    }
    return 0;
}
