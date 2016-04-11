//
//  Created by TaoSama on 2015-06-04
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, cnt, d[105][105];
bool dp[105][105];
pair<int, int> E[105];

void bfs(int s) {
    d[s][s] = 0;
    memset(d[s], 0x3f, sizeof d[s]);
    queue<int> q; q.push(s);
    while(q.size()) {
        int u = q.front(); q.pop();
        for(int i = 1; i <= cnt; ++i) {
            if(dp[u][i] && d[s][i] == INF) {
                d[s][i] = d[s][u] + 1;
                q.push(i);
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        cnt = 0;
        memset(dp, false, sizeof dp);
        for(int i = 1; i <= n; ++i) {
            int op, x, y; cin >> op >> x >> y;
            if(op == 1) {
                E[++cnt].first = x; E[cnt].second = y;
                if(cnt > 1) {
                    for(int j = 1; j < cnt; ++j) {
                        if(E[cnt].first > E[j].first && E[cnt].first < E[j].second
                                || E[cnt].second > E[j].first && E[cnt].second < E[j].second)
                            dp[cnt][j] = true;
                        if(E[j].first > E[cnt].first && E[j].first < E[cnt].second
                                || E[j].second > E[cnt].first && E[j].second < E[cnt].second)
                            dp[j][cnt] = true;
                    }
                }
            } else {
                bfs(x);
                puts(d[x][y] != INF ? "YES" : "NO");
            }
        }
    }

    return 0;
}
