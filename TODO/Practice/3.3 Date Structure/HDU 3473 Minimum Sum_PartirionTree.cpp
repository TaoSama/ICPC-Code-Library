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

int n, q, s[N];
int dat[20][N], tolef[20][N];
long long lef, sum[N], lsum[20][N];  //i层划入到i+1层的左子树和

#define root 1, n, 1
#define lson l, m, d + 1
#define rson m + 1, r, d + 1

void push_down(int l, int r, int d) {
    int m = l + r >> 1, lsame = m - l + 1;
    for(int i = l; i <= r; ++i)
        if(dat[d][i] < s[m]) --lsame;

    int lpos = l, rpos = m + 1;
    for(int i = l; i <= r; ++i) {
        if(dat[d][i] < s[m] || dat[d][i] == s[m] && lsame) {
            dat[d + 1][lpos++] = dat[d][i];
            if(dat[d][i] == s[m]) --lsame;
            lsum[d][i] = lsum[d][i - 1] + dat[d][i];
        } else {
            dat[d + 1][rpos++] = dat[d][i];
            lsum[d][i] = lsum[d][i - 1];
        }

        tolef[d][i] = tolef[d][l - 1] + lpos - l;
    }
}

void build(int l, int r, int d) {
    if(l == r) return;

    int m = l + r >> 1;
    push_down(l, r, d);
    build(lson);
    build(rson);
}

int query(int L, int R, int k, int l, int r, int d) {
    if(l == r) return dat[d][l];
    int m = l + r >> 1;
    int cnt = tolef[d][R] - tolef[d][L - 1];
    if(cnt >= k) {
        int LL = l + tolef[d][L - 1] - tolef[d][l - 1];
        int RR = LL + cnt - 1;
        return query(LL, RR, k, lson);
    } else {
        int RR = R + tolef[d][r] - tolef[d][R];
        int LL = RR - (R - L - cnt);
        lef += lsum[d][R] - lsum[d][L - 1];
        return query(LL, RR, k - cnt, rson);
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
            scanf("%d", s + i);
            dat[1][i] = s[i];
            sum[i] = sum[i - 1] + s[i];
        }
        sort(s + 1, s + 1 + n);
        build(root);
        scanf("%d", &q);
        printf("Case #%d:\n", ++kase);
        while(q--) {
            int l, r; scanf("%d%d", &l, &r);
            ++l, ++r;
            lef = 0;
            int k = (r - l) / 2 + 1, m = query(l, r, k, root);
            long long rig = sum[r] - sum[l - 1] - lef - m;
//          pr(lef); prln(rig);
            long long ans = rig - lef;
            if(r - l & 1) ans -= m;   //偶数-一个中位数
            printf("%I64d\n", ans);
        }
        putchar('\n');
    }
    return 0;
}
