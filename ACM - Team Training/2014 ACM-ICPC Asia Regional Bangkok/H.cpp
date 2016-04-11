//
//  Created by TaoSama on 2015-12-19
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

int n, m, a[35][35], vis[35][35];

typedef pair<int, int> P;

int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};

set<P> sign;

bool isLegal(int x, int y) {
    if(x < 1 || x > n || y < 1 || y > m) return false;
    return !sign.count(P(x, y)) && a[x][y];
}

int getLength(int x, int y) {
    int ret = INF;
    for(int i = 0; i < 4; ++i) {
        int dx = d[i][0], dy = d[i][1];
        int tx = x + dx, ty = y + dy, length = 0;
        for(; isLegal(tx, ty); tx += dx, ty += dy) ++length;
        ret = min(ret, length);
    }
    return ret;
}

void update(int x, int y, int length, int v) {
    a[x][y] += v;
    for(int i = 0; i < 4; ++i) {
        int dx = d[i][0], dy = d[i][1];
        int tx = x + dx, ty = y + dy;
        for(int j = 1; j <= length; ++j, tx += dx, ty += dy)
            a[tx][ty] += v;
    }
}

void dfs(int x, int y, int cnt, int lft) {
    if(!lft && cnt >= 2 && cnt <= 9) {
        printf("%d\n", cnt);
        P lst = *sign.rbegin();
        printf("%d %d\n", lst.first, lst.second);
        throw 1;
    }
    if(y == m + 1) ++x, y = 1;
    if(x == n + 1) return;

    if(!vis[x][y] && a[x][y]) {
        int length = getLength(x, y);
        for(int i = length; i; --i) {
            update(x, y, i, -1);
            sign.insert(P(x, y));
            dfs(x, y + 1, cnt + 1, lft - 4 * i - 1);
            sign.erase(P(x, y));
            update(x, y, i, 1);
        }
    }
    dfs(x, y + 1, cnt, lft);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        int sum = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                scanf("%d", &a[i][j]), sum += a[i][j];

        try {
            sign.clear();
            memset(vis, 0, sizeof vis);
            dfs(1, 1, 0, sum);
        } catch(int) {}
    }
    return 0;
}
