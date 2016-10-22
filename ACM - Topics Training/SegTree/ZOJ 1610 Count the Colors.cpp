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
const int N = 8e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, lastColor;
int row[N << 2];
map<int, int> mp;

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

void push_down(int rt) {
    if(~row[rt]) {
        row[rt << 1] = row[rt << 1 | 1] = row[rt];
        row[rt] = -1;
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
    if(l == r) {
        if(row[rt] != lastColor) ++mp[row[rt]];
        lastColor = row[rt];
        return;
    }
    int m = l + r >> 1;
    push_down(rt);
    query(lson);
    query(rson);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        memset(row, -1, sizeof row);
        for(int i = 1; i <= n; ++i) {
            int x, y, c; scanf("%d%d%d", &x, &y, &c);
            update(x, y - 1, c, 0, 8000, 1);
        }

        lastColor = -1; mp.clear();
        query(0, 8000, 1);

        for(map<int, int>::iterator iter = mp.begin(); iter != mp.end(); ++iter) {
            if(iter->first == -1) continue;
            printf("%d %d\n", iter->first, iter->second);
        }
        puts("");
    }
    return 0;
}
