//
//  Created by TaoSama on 2016-10-03
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
const int N = 1e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, k;
int a[N][N];

int mark[N * N];
void bfs(int i, int j, int id) {
    queue<pair<int, int> > q;
    q.push({i, j}); a[i][j] = id;
    while(q.size()) {
        int x, y; tie(x, y) = q.front(); q.pop();
        static int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};
        for(int i = 0; i < 4; ++i) {
            int nx = x + d[i][0], ny = y + d[i][1];
            if(a[nx][ny] == 0) {
                mark[id] = 1; //ocean;
                continue;
            }
            if(a[nx][ny] == -1) {
                a[nx][ny] = id;
                q.push({nx, ny});
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

//	n = m = k = 50;
//	printf("%d %d %d\n", n, m, k);
//	for(int i = 1; i <= n; ++i){
//		for(int j = 1; j <= m; ++j)
//			putchar("*."[rand() % 2]);
//		puts("");
//	}

    while(scanf("%d%d%d", &n, &m, &k) == 3) {
        memset(a, 0, sizeof a);
        for(int i = 1; i <= n; ++i) {
            char buf[100]; scanf("%s", buf + 1);
            for(int j = 1; j <= m; ++j) a[i][j] = buf[j] == '.' ? -1 : -2;
        }
        memset(mark, 0, sizeof mark);

//      for(int i = 1; i <= n; ++i){
//          for(int j = 1; j <= m; ++j){
//              printf("%c", a[i][j]);
//          }
//          puts("");
//      }

        int cnt = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                if(a[i][j] == -1) bfs(i, j, ++cnt);

        map<int, int> sz;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                if(a[i][j] != -2 && !mark[a[i][j]])
					++sz[a[i][j]];

        int tot = sz.size();
        int more = tot - k;

        vector<pair<int, int> > v(sz.begin(), sz.end());
        for(auto& p : v) swap(p.first, p.second);

        sort(v.begin(), v.end());

        int ans = 0;
        for(auto& p : v) {
//			pr(p.first); prln(p.second);
            if(more) {
                mark[p.second] = 2;
                ans += p.first;
                --more;
            }
        }

        printf("%d\n", ans);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(a[i][j] == -2 || mark[a[i][j]] == 2) putchar('*');
                else putchar('.');
            }
            puts("");
        }
    }

    return 0;
}
