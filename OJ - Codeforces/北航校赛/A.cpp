//
//  Created by TaoSama on 2016-12-18
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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

int n, m;
int a[N], f[505][105];

void bfs() {
    queue<pair<int, int> > q; q.push({0, 1});
    memset(f, 0, sizeof f);
    f[0][1] = true;
    while(q.size()) {
        auto u = q.front(); q.pop();
        if(u.second < n && u.first + a[u.second] <= m) {
            auto v = u;
            v.first += a[u.second];
            v.second++;
            if(!f[v.first][v.second]) {
                f[v.first][v.second] = true;
                q.push(v);
            }
        }
        if(u.second > 0 && u.first + a[u.second] <= m) {
            auto v = u;
            v.first += a[u.second - 1];
            v.second--;
            if(!f[v.first][v.second]) {
                f[v.first][v.second] = true;
                q.push(v);
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

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i < n; ++i) scanf("%d", a + i);
        bfs();
        bool first = true;
        for(int i = 1; i <= m; ++i) {
            if(f[i][n]) continue;
            first ? first = false : putchar(' ');
            printf("%d", i);
        }
        puts("");
    }

    return 0;
}
