//
//  Created by TaoSama on 2015-09-16
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
const int N = 1e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, ans;
int row[6 * N * 3];
int x1[N], x2[N];
bool vis[N];

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

void push_down(int rt) {
    if(row[rt]) {
        row[rt << 1] = row[rt << 1 | 1] = row[rt];
        row[rt] = 0;
    }
}

void update(int L, int R, int c, int l, int r, int rt) {
    if(L <= l && r <= R) {
        row[rt] = c;
        return;
    }
    int m = l + r >> 1;
    push_down(rt);
    if(L <= m) update(L, R, c, lson);
    if(R > m) update(L, R, c, rson);
}

void query(int l, int r, int rt) {
    if(row[rt]) {
        if(!vis[row[rt]]) ++ans;
        vis[row[rt]] = true;
        return;
    }
    if(l == r) return;
    int m = l + r >> 1;
    query(lson);
    query(rson);
}

int compress(int *x1, int *x2, int w) {
    vector<int> xs;
    for(int i = 1; i <= n; ++i) {
        for(int d = -1; d <= 1; ++d) {
            int tx1 = x1[i] + d, tx2 = x2[i] + d;
            if(tx1 >= 1 && tx1 <= w) xs.push_back(tx1);
            if(tx2 >= 1 && tx2 <= w) xs.push_back(tx2);
        }
    }
    sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
    for(int i = 1; i <= n; ++i) {
        x1[i] = lower_bound(xs.begin(), xs.end(), x1[i]) - xs.begin() + 1;
        x2[i] = lower_bound(xs.begin(), xs.end(), x2[i]) - xs.begin() + 1;
    }
    return xs.size();
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d%d", x1 + i, x2 + i);
        int w = compress(x1, x2, 1e7);
        memset(row, 0, sizeof row);
        memset(vis, false, sizeof vis);
        for(int i = 1; i <= n; ++i) update(x1[i], x2[i], i, 1, w, 1);

        ans = 0;
        query(1, w, 1);
        printf("%d\n", ans);
    }
    return 0;
}
