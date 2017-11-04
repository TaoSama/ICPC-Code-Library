//
//  Created by TaoSama on 2015-07-16
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

int n, m, wall[N], bird[N], dis[N];
int x0[N], y0[N], x1[N], y1[N], x2[N], y2[N];
int w, h;
vector<int> xs, ys;

struct Seg {
    int l, r, id;
};
vector<Seg> seg[N * 3];

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

int row[N * 3 << 2];

void push_down(int rt) {
    if(row[rt]) {
        row[rt << 1] = row[rt << 1 | 1] = row[rt];
        row[rt] = 0;
    }
}

void update(int L, int R, int v, int l, int r, int rt) {
    if(L <= l && r <= R) {
        row[rt] = v;
        return;
    }
    push_down(rt);
    int m = l + r >> 1;
    if(L <= m) update(L, R, v, lson);
    if(R > m) update(L, R, v, rson);
}

int query(int o, int l, int r, int rt) {
    if(l == r) return row[rt];
    push_down(rt);
    int m = l + r >> 1;
    if(o <= m) return query(o, lson);
    else return query(o, rson);
}

int compress(vector<int>& xs, int *x0, int *x1, int *x2) {
    xs.clear();
    for(int i = 1; i <= m; ++i) xs.push_back(x0[i]);
    for(int i = 1; i <= n; ++i) {
        xs.push_back(x1[i]);
        xs.push_back(x2[i]);
    }
    sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
    for(int i = 1; i <= m; ++i)
        x0[i] = lower_bound(xs.begin(), xs.end(), x0[i]) - xs.begin() + 1;
    for(int i = 1; i <= n; ++i) {
        x1[i] = lower_bound(xs.begin(), xs.end(), x1[i]) - xs.begin() + 1;
        x2[i] = lower_bound(xs.begin(), xs.end(), x2[i]) - xs.begin() + 1;
    }
    return xs.size();
}

int getdis(int pb, int pw, bool vtl) {
    int ret;
    if(vtl) {
        pb = ys[y0[pb] - 1];
        ret = min(abs(pb - ys[y1[pw] - 1]), abs(pb - ys[y2[pw] - 1]));
    } else {
        pb = xs[x0[pb] - 1];
        ret = min(abs(pb - xs[x1[pw] - 1]), abs(pb - xs[x2[pw] - 1]));
    }

//    pr(pb);
    return ret;
}

void sweep(vector<Seg>& seg, bool vtl) {
    for(int i = 0; i < seg.size(); ++i) {
        Seg& s = seg[i];
        if(s.r != -1)  {
//            pr(s.l), pr(s.r), prln(s.id);
            update(s.l, s.r, s.id, 1, w, 1);
        } else {
            int id = query(s.l, 1, w, 1);
//            pr(s.id); prln(id);
            if(!id) continue;  //撞不上
            int d = getdis(s.id, id, vtl);
//            prln(d);
            if(d < dis[s.id]) dis[s.id] = d, bird[s.id] = id;
        }
    }
}

//horizontal sweeping line
void fly(int *x0, int *y0, int *x1, int *y1, int *x2, int *y2, bool vtl) {
    for(int i = 1; i <= h; ++i) seg[i].clear();
    for(int i = 1; i <= m; ++i) seg[y0[i]].push_back((Seg) {x0[i], -1, i}); //小鸟
    for(int i = 1; i <= n; ++i) {
        int l = min(x1[i], x2[i]), r = max(x1[i], x2[i]);
        seg[y1[i]].push_back((Seg) {l, r, i});  //横向的
        if(y1[i] != y2[i]) seg[y2[i]].push_back((Seg) {l, r, i}); //竖向两个点
    }

    memset(row, 0, sizeof row);
    for(int i = 1; i <= h; ++i) sweep(seg[i], vtl);
//    cout << endl;
    memset(row, 0, sizeof row);
    for(int i = h; i; --i) sweep(seg[i], vtl);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= n; ++i)
            scanf("%d%d%d%d", x1 + i, y1 + i, x2 + i, y2 + i);
        for(int i = 1; i <= m; ++i)
            scanf("%d%d", x0 + i, y0 + i);

        w = compress(xs, x0, x1, x2);
        h = compress(ys, y0, y1, y2);

        fill(dis, dis + m + 1, 0x7fffffff);
        memset(wall, 0, sizeof wall);

        fly(x0, y0, x1, y1, x2, y2, true);
        swap(w, h);
        fly(y0, x0, y1, x1, y2, x2, false);

        for(int i = 1; i <= m; ++i) wall[bird[i]]++;
        for(int i = 1; i <= n; ++i) printf("%d\n", wall[i]);
    }
    return 0;
}
