//
//  Created by TaoSama on 2015-11-07
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

int d, n, m, w[55], v[55];
double dp[22][105][55][55]; //k m today yesterday

#define rep(i, a, b) for(int i = a; i <= b; ++i)

void getMax(double& x, double y) {
    x = max(x, y);
}

const double EPS = 1e-8;

int sgn(double x) {
    return x < -EPS ? -1 : x < EPS ? 0 : 1;
}

void print(int day, int cost, int today, int yesterday) {
    if(day == 2) {
        printf("%d %d ", yesterday, today);
        return;
    }
    double cur = dp[day][cost][today][yesterday];
    for(int i = 1; i <= n; ++i) {
        double nxt = dp[day - 1][cost - w[today]][yesterday][i];
        if(sgn(nxt) == 0) continue;
        if(today == yesterday) {
            if(yesterday != i) {
                if(sgn(cur - (nxt + v[today] * 0.5)) == 0) {
                    print(day - 1, cost - w[today], yesterday, i);
                    printf("%d ", today);
                    return;
                }
            } else if(sgn(cur - nxt) == 0) {
                print(day - 1, cost - w[today], yesterday, i);
                printf("%d ", today);
                return;
            }
        } else if(sgn(cur - (nxt + v[today])) == 0) {
            print(day - 1, cost - w[today], yesterday, i);
            printf("%d ", today);
            return;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d%d%d", &d, &n, &m) == 3 && (d || n || m)) {
        w[0] = INF;
        for(int i = 1; i <= n; ++i) scanf("%d%d", w + i, v + i);
        if(kase++) puts("");
        if(d == 1) {
            int maxv = 0, ans = 0;
            for(int i = 1; i <= n; ++i) if(w[i] <= m) maxv = max(maxv, v[i]);
            for(int i = 1; i <= n; ++i)
                if(v[i] == maxv && w[i] <= m && w[i] < w[ans]) ans = i;
            if(maxv == 0) puts("0.0");
            else printf("%.1f\n%d\n", 1.0 * maxv, ans);
            continue;
        }

        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                int weight = w[i] + w[j];
                dp[2][weight][i][j] = i == j ? 1.5 * v[i] : v[i] + v[j];
            }
        }
        rep(i, 3, d) rep(j, 1, n) rep(k, w[j], m) {
            rep(x, 1, n) {
                rep(y, 1, n) {
                    double cur = dp[i - 1][k - w[j]][x][y];
                    if(sgn(cur) == 0) continue;
                    if(j == x) {
                        if(y != x) cur += v[j] * 0.5;
                    } else cur += v[j];
                    getMax(dp[i][k][j][x], cur);
                }
            }
        }

        double maxv = 0;
        rep(i, 0, m) rep(x, 1, n) rep(y, 1, n) getMax(maxv, dp[d][i][x][y]);
        int cost = INF, today, yesterday;
        rep(i, 0, m) {
            rep(x, 1, n) rep(y, 1, n) {
                if(sgn(dp[d][i][x][y] - maxv) == 0) {
                    cost = i;
                    today = x;
                    yesterday = y;
                }
            }
            if(cost != INF) break;
        }

        if(cost == 0) {puts("0.0"); continue;}
        printf("%.1f\n", maxv);
        print(d, cost, today, yesterday);
        puts("");
    }
    return 0;
}
