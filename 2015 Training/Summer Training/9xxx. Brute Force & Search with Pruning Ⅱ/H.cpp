//
//  Created by TaoSama on 2015-07-29
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

int cnt, all;
int a[10][10], g[7][7], ans[10][10], used[30];
int d[][2] = {0, 1, 1, 0};

void init() {
    int cnt = 0;
    for(int i = 0; i < 7; ++i)
        for(int j = i; j < 7; ++j)
            g[i][j] = g[j][i] = ++cnt;
}

void dfs(int x, int y) {
    if(y == 9) x++, y = 1; //next line
//    cout << x << ' ' << y << endl;
    if(x == 8) {
        ++cnt;
        for(int i = 1; i <= 7; ++i) {
            for(int j = 1; j <= 8; ++j)
                printf("%4d", ans[i][j]);
            printf("\n");
        }
        printf("\n");
        return;
    }

    if(ans[x][y]) dfs(x, y + 1); //have placed
    else {
        for(int i = 0; i < 2; ++i) {
            int nx = x + d[i][0], ny = y + d[i][1];
            if(nx > 7 || ny > 8 || ans[nx][ny]) continue;
            int l = a[x][y], r = a[nx][ny], cur = g[l][r];
            if(!cur || used[cur]) continue;
            used[cur] = ans[x][y] = ans[nx][ny] = cur;
            dfs(x, y + 1);
            used[cur] = ans[x][y] = ans[nx][ny] = 0;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    init();
    while(scanf("%d", &a[1][1]) == 1) {
        memset(ans, 0, sizeof ans);
        memset(used, false, sizeof used);
        for(int j = 2; j <= 8; ++j) scanf("%d", &a[1][j]);
        for(int i = 2; i <= 7; ++i)
            for(int j = 1; j <= 8; ++j)
                scanf("%d", &a[i][j]);


        if(kase) printf("\n\n\n");
        printf("Layout #%d:\n\n", ++kase);
        for(int i = 1; i <= 7; ++i) {
            for(int j = 1; j <= 8; ++j)
                printf("%4d", a[i][j]);
            printf("\n");
        }

        printf("\nMaps resulting from layout #%d are:\n\n", kase);
        cnt = 0;
        dfs(1, 1);
        printf("There are %d solution(s) for layout #%d.\n", cnt, kase);
    }
    return 0;
}
