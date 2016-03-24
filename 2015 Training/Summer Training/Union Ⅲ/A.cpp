//
//  Created by TaoSama on 2015-08-26
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
const int N = 50 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
double minCost[N];
bool done[N];
int x[N], y[N];
double dis[N][N];
typedef pair<double, int> Sta;

double getdis(int u, int v) {
    return sqrt((x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]));
}

double prim(int x) {
    double ret = 0;
    priority_queue<Sta, vector<Sta>, greater<Sta> > q;
    for(int i = 1; i <= n; ++i) minCost[i] = 1e20;
    memset(done, false, sizeof done);
    for(int i = 1; i <= n; ++i) {
        if(i != x) {
            minCost[i] = 0;
            q.push(Sta(0, i));
            break;
        }
    }
    while(q.size()) {
        int u = q.top().second; q.pop();
        if(done[u]) continue;
        done[u] = true; ret += minCost[u];
        for(int v = 1; v <= n; ++v) {
            if(v == x) continue;
            if(minCost[v] > dis[u][v]) {
                minCost[v] = dis[u][v];
                q.push(Sta(minCost[v], v));
            }
        }
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d%d", x + i, y + i);
        for(int i = 1; i <= n; ++i)
            for(int j = i + 1; j <= n; ++j)
                dis[i][j] = dis[j][i] = getdis(i, j);
        double ans = 1e20;
        for(int i = 1; i <= n; ++i)
            ans = min(ans, prim(i));
        printf("%.2f\n", ans);
    }
    return 0;
}
