//
//  Created by TaoSama on 2016-10-06
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
const int N = 200 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

int R, C, bR, bC;
int n, g[3 * N][3 * N];
int ox[N], oy[N];
int nox[N], noy[N];

vector<int> xs, ys;
int compress(int* x, vector<int>& xs, int R) {
    xs.clear();
    xs.push_back(1);
    xs.push_back(R);
    for(int i = 1; i <= n; ++i) {
        for(int d = -1; d <= 1; ++d) {
            int tx = x[i] + d;
            if(tx >= 1 && tx <= R) xs.push_back(tx);
        }
    }
    sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());

    for(int i = 1; i <= n; ++i) {
        x[i] = lower_bound(xs.begin(), xs.end(), x[i]) - xs.begin() + 1;
    }
    return xs.size();
}

inline int get(int x, int y, int nx, int ny) {
    return abs(xs[nx - 1] - xs[x - 1]) + abs(ys[ny - 1] - ys[y - 1]);
}

LL bfs(int i, int j, int id) {
    queue<pair<int, int> > q;
    q.push({i, j});
    g[i][j] = id;
    LL ret = 1;
    while(q.size()) {
        int x, y; tie(x, y) = q.front(); q.pop();
        static int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};
        for(int i = 0; i < 4; ++i) {
            int nx = x + d[i][0], ny = y + d[i][1];
            if(nx < 1 || nx > R || ny < 1 || ny > C) continue;
            if(g[nx][ny]) continue;

            int dis = get(x, y, nx, ny);
//            printf("%d  (%d, %d) -> (%d, %d) = %d\n", id, x, y, nx, ny, dis);
            ret += dis;
            g[nx][ny] = id;
            q.push({nx, ny});
        }
    }

    return ret;
}

int bfs2(int i, int j) {
    map<pair<int, int>, int> f;
    set<pair<int, int> > ob;
    for(int i = 1; i <= n; ++i) ob.insert({ox[i], oy[i]});
    f[ {i, j}] = 0;
    queue<pair<int, int> > q; q.push({i, j});

    int ret = 1;
    while(q.size()) {
        int x, y; tie(x, y) = q.front(); q.pop();
        int last = f[ {x, y}];
        if(last > 200) return INF;

        static int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};
        for(int i = 0; i < 4; ++i) {
            int nx = x + d[i][0], ny = y + d[i][1];
            if(nx < 1 || nx > bR || ny < 1 || ny > bC) continue;
            if(ob.count({nx, ny})) continue;
            if(f.count({nx, ny})) continue;

            f[ {nx, ny}] = last + 1;
            ++ret;
            q.push({nx, ny});
        }
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &R, &C);
        bR = R; bC = C;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d", ox + i, oy + i);
        }
        memcpy(nox, ox, sizeof ox);
        memcpy(noy, oy, sizeof oy);

        if(R <= 200) {
            xs.clear();
            for(int i = 1; i <= R; ++i) xs.push_back(i);
        }
        if(C <= 200) {
            ys.clear();
            for(int i = 1; i <= C; ++i) ys.push_back(i);
        }

        vector<LL> ans;
        if(R <= 200) {
            if(C <= 200) {
                memset(g, 0, sizeof g);
                for(int i = 1; i <= n; ++i) g[nox[i]][noy[i]] = -1;

                int cnt = 0;
                for(int i = 1; i <= R; ++i) {
                    for(int j = 1; j <= C; ++j) {
                        if(g[i][j]) continue;
                        LL ret = bfs(i, j, ++cnt);
                        ans.push_back(ret);
                    }
                }
            } else {
                C = compress(noy, ys, C);
                memset(g, 0, sizeof g);
                for(int i = 1; i <= n; ++i) g[nox[i]][noy[i]] = -1;

                int cnt = 0;
                for(int i = 1; i <= R; ++i) {
                    for(int j = 1; j <= C; ++j) {
                        if(g[i][j]) continue;
                        LL ret = bfs(i, j, ++cnt);
                        ans.push_back(ret);
                    }
                }
            }
        } else {
            if(C <= 200) {
                R = compress(nox, xs, R);
                memset(g, 0, sizeof g);
                for(int i = 1; i <= n; ++i) g[nox[i]][noy[i]] = -1;

                int cnt = 0;
                for(int i = 1; i <= R; ++i) {
                    for(int j = 1; j <= C; ++j) {
                        if(g[i][j]) continue;
                        LL ret = bfs(i, j, ++cnt);
                        ans.push_back(ret);
                    }
                }
            } else {
                R = compress(nox, xs, R);
                C = compress(noy, ys, C);
                memset(g, 0, sizeof g);
//                pr(R); prln(C);
                for(int i = 1; i <= n; ++i) {
                    g[nox[i]][noy[i]] = -1;
                }

                int cnt = 0;
                vector<pair<int, int> > cc;
                for(int i = 1; i <= R; ++i) {
                    for(int j = 1; j <= C; ++j) {
                        if(g[i][j]) continue;
                        bfs(i, j, ++cnt);
                        cc.push_back({i, j});
                    }
                }

                LL lft = 1LL * bR * bC - n;
                for(auto& p : cc) {
                    int x, y; tie(x, y) = p;
                    int ret = bfs2(xs[x - 1], ys[y - 1]);
//                    pr(x); pr(y); prln(ret);
                    if(ret == INF) continue;
                    ans.push_back(ret);
                    lft -= ret;
                }
                ans.push_back(lft);
            }
        }

        static int kase = 0;
        printf("Case #%d:\n", ++kase);
        printf("%d\n", ans.size());
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); ++i) {
            printf("%I64d%c", ans[i], " \n"[i + 1 == ans.size()]);
        }
    }
    return 0;
}
