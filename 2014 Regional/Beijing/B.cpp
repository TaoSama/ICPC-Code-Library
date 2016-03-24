//
//  Created by TaoSama on 2015-10-11
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

int n, m, k, lef;
int c[30], ans[8][8];
int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};

bool check(int x, int y, int c) {
    for(int i = 0; i < 4; ++i) {
        int nx = x + d[i][0], ny = y + d[i][1];
        if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if(ans[nx][ny] == c) return false;
    }
    return true;
}

bool dfs(int x, int y) {
    if(*max_element(c + 1, c + 1 + k) > (lef + 1 >> 1)) return false;
    for(int i = 1; i <= k; ++i) {
        if(!c[i] || !check(x, y, i)) continue;
        ans[x][y] = i; --c[i];
        if(--lef == 0) {
            puts("YES");
            for(int i = 1; i <= n; ++i)
                for(int j = 1; j <= m; ++j)
                    printf("%d%c", ans[i][j], " \n"[j == m]);
            return true;
        }
        for(int j = 0; j < 4; ++j) {
            int nx = x + d[j][0], ny = y + d[j][1];
            if(nx < 1 || nx > n || ny < 1 || ny > m || ans[nx][ny]) continue;
            if(dfs(nx, ny)) return true;
        }
        ans[x][y] = 0; ++c[i]; ++lef;
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= k; ++i) scanf("%d", c + i);
        printf("Case #%d:\n", ++kase);
        lef = n * m;
        memset(ans, 0, sizeof ans);
        if(!dfs(1, 1)) puts("NO");
    }
    return 0;
}
