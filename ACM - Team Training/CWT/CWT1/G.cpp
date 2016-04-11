//
//  Created by TaoSama on 2016-01-19
//  Copyright (c) 2015 TaoSama. All rights reserved.
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

char s[N][N];
int n, m, q, cc, id[N][N], cnt[N * N];

typedef pair<int, int> P;
int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};

void bfs(int i, int j) {
    queue<P> q; q.push(P(i, j));
    id[i][j] = cc;
    while(q.size()) {
        P cur = q.front(); q.pop();
        for(int i = 0; i < 4; ++i) {
            P nxt = cur;
            nxt.first += d[i][0], nxt.second += d[i][1];
            if(s[nxt.first][nxt.second] == '*') ++cnt[cc];
            else if(!id[nxt.first][nxt.second]) {
                id[nxt.first][nxt.second] = cc;
                q.push(nxt);
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
        for(int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
        cc = 0;
        memset(id, 0, sizeof id);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                if(s[i][j] == '.' && !id[i][j])
                    cnt[++cc] = 0, bfs(i, j);

        while(q--) {
            int x, y; scanf("%d%d", &x, &y);
            printf("%d\n", cnt[id[x][y]]);
        }
    }
    return 0;
}
