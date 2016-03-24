//
//  Created by TaoSama on 2015-07-24
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

int n, x[1005], y[1005], r[1005];
double lef, rig;
bool vis[1005];

double getDis(int i, int j) {
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

void update(int i) {
    if(x[i] <= r[i]) {
        double p = y[i] - sqrt(r[i] * r[i] - x[i] * x[i]);
        lef = min(lef, p);
    }
    if(1000 - x[i] <= r[i]) {
        double p = y[i] - sqrt(r[i] * r[i] - (1000 - x[i]) * (1000 - x[i]));
        rig = min(rig, p);
    }
}

bool bfs(int u) {
    queue<int> q;
    q.push(u); vis[u] = true;
    while(q.size()) {
        int u = q.front(); q.pop();
        if(y[u] <= r[u]) return false;
        for(int i = 1; i <= n; ++i) {
            if(!vis[i] && getDis(u, i) <= r[u] + r[i]) {
                q.push(i);
                vis[i] = true;
                update(i);
            }
        }
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        cout << fixed << setprecision(2);
        for(int i = 1; i <= n; ++i) cin >> x[i] >> y[i] >> r[i];

        lef = rig = 1000;
        bool can = true;
        memset(vis, false, sizeof vis);
        for(int i = 1; i <= n; ++i) {
            if(!vis[i] && 1000 - y[i] <= r[i]) {
                vis[i] = true;
                update(i);
                if(!bfs(i)) {
                    can = false;
                    break;
                }
            }
        }
        if(can) cout << 0.0 << ' ' << lef << ' ' << 1000.0 << ' ' << rig << '\n';
        else cout << "IMPOSSIBLE\n";
    }
    return 0;
}
