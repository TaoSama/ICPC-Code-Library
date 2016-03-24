//
//  Created by TaoSama on 2015-11-14
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

int n, m, q;
char a[1005][1005];
int id[1005][1005], cnt[N * 10], cc;
typedef pair<int, int> P;

int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};

void bfs(int i, int j) {
    queue<P> q;
    q.push(P(i, j));
    id[i][j] = cc;
    while(q.size()) {
        int x = q.front().first, y = q.front().second; q.pop();
        for(int i = 0; i < 4; ++i) {
            int nx = x + d[i][0], ny = y + d[i][1];
            if(a[nx][ny] == '*') ++cnt[cc];
            else if(!id[nx][ny]) {
                id[nx][ny] = cc;
                q.push(P(nx, ny));
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &m, &q) == 3) {
        for(int i = 1; i <= n; ++i) scanf("%s", a[i] + 1);
        cc = 0;
        memset(id, 0, sizeof id);
        memset(cnt, 0, sizeof cnt);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(a[i][j] == '.' && !id[i][j]) {
                    ++cc;
                    bfs(i, j);
                }
            }
        }
        while(q--) {
            int x, y; scanf("%d%d", &x, &y);
            printf("%d\n", cnt[id[x][y]]);
        }
    }
    return 0;
}
