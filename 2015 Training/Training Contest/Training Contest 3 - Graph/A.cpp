//
//
//
//  Created by TaoSama on 2015-03-26
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
#define CLR(x,y) memset(x, y, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, m, s;
double v, dp[1005];

struct Edge {
    int to;
    double r, c;
};
vector<Edge> G[1005];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> s >> v;
    for(int i = 1; i <= m; ++i) {
        int x, y; double r1, c1, r2, c2;
        cin >> x >> y >> r1 >> c1 >> r2 >> c2;
        G[x].push_back((Edge) {y, r1, c1});
        G[y].push_back((Edge) {x, r2, c2});
    }

    memset(dp, 0, sizeof dp);
    queue<int> q; dp[s] = v; q.push(s);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int i = 0; i < G[cur].size(); ++i) {
            Edge &e = G[cur][i];
            if(dp[e.to] < (dp[cur] - e.c)*e.r) {
                dp[e.to] = (dp[cur] - e.c) * e.r;
                q.push(e.to);
            }
        }
    }
    if(dp[s] > v) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
