//
//  Created by TaoSama on 2016-03-16
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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

int n, a, b;
int col[105][105];
int odd, even;
int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};

void dfs(int x, int y, int c) {
    if(c > 0) odd += 2, col[x][y] = odd;
    else even += 2, col[x][y] = even;
    for(int i = 0; i < 4; ++i) {
        int nx = x + d[i][0], ny = y + d[i][1];
        if(nx < 1 || nx > a || ny < 1 || ny > b) continue;
        if(!col[nx][ny])  dfs(nx, ny, -c);
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &a, &b) == 3) {
        memset(col, 0, sizeof col);
        int x = n & 1 ? n : n - 1;
        int y = n & 1 ? n - 1 : n;
        odd = -1; even = 0;
        dfs(1, 1, 1);
        if(odd >= x && even >= y) {
            for(int i = 1; i <= a; ++i)
                for(int j = 1; j <= b; ++j)
                    printf("%d%c", col[i][j] > n ? 0 : col[i][j], " \n"[j == b]);
            continue;
        }
        memset(col, 0, sizeof col);
        odd = -1; even = 0;
        dfs(1, 1, -1);
        if(odd >= x && even >= y) {
            for(int i = 1; i <= a; ++i)
                for(int j = 1; j <= b; ++j)
                    printf("%d%c", col[i][j] > n ? 0 : col[i][j], " \n"[j == b]);
            continue;
        }
        puts("-1");
    }
    return 0;
}
