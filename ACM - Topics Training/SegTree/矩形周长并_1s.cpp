//
//  Created by TaoSama on 2015-07-15
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
const int N = 2e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int sum[N << 2], cnt[N << 2], vtl[N << 2];
bool lbd[N << 2], rbd[N << 2];
struct Seg {
    int l, r, h, d;
    Seg() {}
    Seg(int l, int r, int h, int d): l(l), r(r), h(h), d(d) {}
    bool operator< (const Seg& rhs) const {return h < rhs.h;}
} a[N];

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

void push_up(int l, int r, int rt) {
    if(cnt[rt]) {
        lbd[rt] = rbd[rt] = true;
        sum[rt] = r + 1 - l;
        vtl[rt] = 2;
    }
//叶子节点的下面的节点也是0 不这样也可以(那就要数组开大 小心RE)
    else if(l == r) sum[rt] = vtl[rt] = lbd[rt] = rbd[rt] = 0;
    else {
        lbd[rt] = lbd[rt << 1];
        rbd[rt] = rbd[rt << 1 | 1];
        sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
        vtl[rt] = vtl[rt << 1] + vtl[rt << 1 | 1];
        if(rbd[rt << 1] && lbd[rt << 1 | 1]) vtl[rt] -= 2; //两条线重合
    }
}

void update(int L, int R, int v, int l, int r, int rt) {
    if(L <= l && r <= R) {
        cnt[rt] += v;
        push_up(l, r, rt);
        return;
    }
    int m = l + r >> 1;
    if(L <= m) update(L, R, v, lson);
    if(R > m) update(L, R, v, rson);
    push_up(l, r, rt);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        int Min = 1e4, Max = -1e4;
        for(int i = 1; i <= n; ++i) {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            Min = min(Min, x1);
            Max = max(Max, x2);
            a[i] = Seg(x1, x2, y1, 1);
            a[i + n] = Seg(x1, x2, y2, -1);
        }
        n <<= 1;
        sort(a + 1, a + 1 + n);

//      memset(sum, 0, sizeof sum); 所有覆盖最后都被清除了 不需要初始化了
//      memset(cnt, 0, sizeof cnt);
//      memset(lbd, false, sizeof lbd);
//      memset(rbd, false, sizeof rbd);

        int ans = 0, last = 0;
        for(int i = 1; i <= n; ++i) {
            if(a[i].l < a[i].r) update(a[i].l, a[i].r - 1, a[i].d, Min, Max - 1, 1);
            ans += vtl[1] * (a[i + 1].h - a[i].h);
            ans += abs(sum[1] - last);
            last = sum[1];
        }
        printf("%d\n", ans);
    }
    return 0;
}
