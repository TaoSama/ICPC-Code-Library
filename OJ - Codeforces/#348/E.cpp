//
//  Created by TaoSama on 2016-04-25
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;

struct BIT {
    int n, cnt[N], b[N];
    int tim;
    void init(int _n) {
        n = _n;
        tim = 0;
        memset(cnt, 0, sizeof cnt);
    }
    void newOne() {
        ++tim;
    }
    void add(int i, int v) {
        for(; i <= n; i += i & -i) {
            if(cnt[i] != tim) cnt[i] = tim, b[i] = 0;
            b[i] += v;
        }
    }
    int sum(int i) {
        int ret = 0;
        for(; i; i -= i & -i)
            if(cnt[i] == tim) ret += b[i];
        return ret;
    }
} bit;


struct Query {
    int type, t, v, id;
    bool operator<(const Query& q) const {
        return t < q.t;
    }
} qs[N], tmp[N];

int ans[N];


void cdq(int l, int r) {
    if(l == r) return;
    int m = l + r >> 1;
    cdq(l, m);

    for(int i = l; i <= r; ++i) tmp[i] = qs[i];
    sort(tmp + l, tmp + m + 1);
    sort(tmp + m + 1, tmp + r + 1);

    bit.newOne();
    for(int i = m + 1, j = l; i <= r; ++i) {
        while(j <= m && tmp[j].t <= tmp[i].t) {
            if(tmp[j].type == 1) bit.add(tmp[j].v, 1);
            else if(tmp[j].type == 2) bit.add(tmp[j].v, -1);
            ++j;
        }
        ans[tmp[i].id] += bit.sum(tmp[i].v) - bit.sum(tmp[i].v - 1);
    }
    cdq(m + 1, r);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        vector<int> xs;
        for(int i = 1; i <= n; ++i) {
            int type, t, v; scanf("%d%d%d", &type, &t, &v);
            xs.push_back(v);
            qs[i] = {type, t, v, i};
        }
        sort(xs.begin(), xs.end());
        xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
        for(int i = 1; i <= n; ++i)
            qs[i].v = lower_bound(xs.begin(), xs.end(), qs[i].v) - xs.begin() + 1;

//        puts("here");
        memset(ans, 0, sizeof ans);
        bit.init(xs.size());
        cdq(1, n);
        for(int i = 1; i <= n; ++i)
            if(qs[i].type == 3) printf("%d\n", ans[i]);
    }
    return 0;
}