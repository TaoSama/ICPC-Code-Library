//
//  Created by TaoSama on 2016-04-28
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
int n, L;
int cnt[N << 2];
LL sum[N << 2][5];
vector<int> xs;

void build(int l, int r, int rt) {
    cnt[rt] = 0;
    for(int i = 0; i < L; ++i) sum[rt][i] = 0;
    if(l == r) return;
    int m = l + r >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
}

void up(int rt) {
    int ls = rt << 1, rs = ls | 1;
    cnt[rt] = cnt[ls] + cnt[rs];

    int offset = cnt[ls];
    for(int i = 0; i < L; ++i) sum[rt][i] = sum[ls][i];
    for(int i = 0; i < L; ++i) sum[rt][(i + offset) % L] += sum[rs][i];
}

void update(int o, int v, int l, int r, int rt) {
    if(l == r) {
        cnt[rt] = v;
        sum[rt][0] = v * xs[l - 1];
        return;
    }
    int m = l + r >> 1;
    if(o <= m) update(o, v, l, m, rt << 1);
    else update(o, v, m + 1, r, rt << 1 | 1);
    up(rt);
}

int op[N], a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &L) == 2) {
        xs.clear();
        for(int i = 1; i <= n; ++i) {
            char cmd[10]; scanf("%s%d", cmd, a + i);
            if(*cmd == 's') op[i] = 2;
            else {
                xs.push_back(a[i]);
                op[i] = *cmd == 'a';
            }
        }
        sort(xs.begin(), xs.end());
        xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
        build(1, xs.size(), 1);

        static int kase = 0;
        printf("Case %d:\n", ++kase);
        for(int i = 1; i <= n; ++i) {
            if(op[i] != 2) {
                int o = lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin() + 1;
                update(o, op[i], 1, xs.size(), 1);
            } else printf("%lld\n", sum[1][a[i] - 1]);
        }
    }
    return 0;
}
