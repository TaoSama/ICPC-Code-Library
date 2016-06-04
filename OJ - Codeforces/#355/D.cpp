//
//  Created by TaoSama on 2016-06-02
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
const int N = 300 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, p;
int s[N][N];
typedef pair<int, int> P;

vector<P> G[N * N];
int f[N][N];

void getMin(int& x, int y) {
    if(x > y) x = y;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    scanf("%d%d%d", &n, &m, &p);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            scanf("%d", s[i] + j);
            G[s[i][j]].push_back({i, j});
            f[i][j] = s[i][j] == 1 ? i + j - 2 : INF;
        }
    }

    for(int i = 1; i < p; ++i) {
        vector<P>& cur = G[i], &nxt = G[i + 1];
        int delta = cur.size() * nxt.size();
        if(delta <= n * m) {
            for(P& u : cur) {
                for(P& v : nxt) {
                    int d = abs(u.first - v.first) + abs(u.second - v.second);
                    getMin(f[v.first][v.second], f[u.first][u.second] + d);
                }
            }
        } else {
            static vector<P> q; q.clear();
            static int d[N][N], in[N][N];
            memset(d, 0x3f, sizeof d);
            memset(in, false, sizeof in);

            for(P& u : cur) {
                q.push_back(u);
                in[u.first][u.second] = true;
                d[u.first][u.second] = f[u.first][u.second];

            }

            static int dir[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};
            for(int j = 0; j < q.size(); ++j) {
                P u = q[j];
                in[u.first][u.second] = false;
                for(int k = 0; k < 4; ++k) {
                    P v = u;
                    v.first += dir[k][0];
                    v.second += dir[k][1];
                    if(!s[v.first][v.second]) continue;
                    if(d[v.first][v.second] > d[u.first][u.second] + 1) {
                        d[v.first][v.second] = d[u.first][u.second] + 1;
                        if(!in[v.first][v.second]) {
                            in[v.first][v.second] = true;
                            q.push_back(v);
                        }
                    }
                }
            }
            for(P& v : nxt) f[v.first][v.second] = d[v.first][v.second];
        }
    }
    int x = G[p][0].first, y = G[p][0].second;
    printf("%d\n", f[x][y]);

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
