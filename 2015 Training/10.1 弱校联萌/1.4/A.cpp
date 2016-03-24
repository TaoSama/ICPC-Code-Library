//
//  Created by TaoSama on 2015-10-05
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
const int N = 105, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const double EPS = 1e-8;

struct Node {
    int x, y;
    void read() {
        scanf("%d%d", &x, &y);
    }
} x[N], y[N];

double getdis(int i, int j) {
    return sqrt((x[i].x - y[j].x) * (x[i].x - y[j].x) +
                (x[i].y - y[j].y) * (x[i].y - y[j].y));
}

double s[N][N], slack[N];
double lx[N], ly[N];
int match[N], n;
bool vx[N], vy[N];
bool dfs(int u) {
    vx[u] = 1;
    for(int i = 1; i <= n; i++) {
        if(!vy[i]) {
            double t = lx[u] + ly[i] - s[u][i];
            if(abs(t) < EPS) {
                vy[i] = 1;
                if(match[i] == -1 || dfs(match[i])) {
                    match[i] = u;
                    return 1;
                }
            } else slack[i] = min(slack[i], t);
        }
    }
    return 0;
}
void KM() {
    memset(match, -1, sizeof(match));
    memset(ly, 0, sizeof(ly));
    for(int i = 1; i <= n; i++) {
        lx[i] = -INF;
        for(int j = 1; j <= n; j++)
            lx[i] = max(lx[i], s[i][j]);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) slack[j] = INF;
        while(1) {
            memset(vx, 0, sizeof(vx));
            memset(vy, 0, sizeof(vy));
            if(dfs(i)) break;
            double d = INF;
            for(int j = 1; j <= n; j++)
                if(!vy[j]) d = min(d, slack[j]);
            for(int j = 1; j <= n; j++)
                if(vx[j]) lx[j] -= d;
            for(int j = 1; j <= n; j++)
                if(vy[j]) ly[j] += d;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) y[i].read();
        for(int i = 1; i <= n; ++i) x[i].read();
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                s[i][j] = -getdis(i, j);

        KM();
        for(int i = 1; i <= n; ++i) printf("%d\n", match[i]);
    }
    return 0;
}
