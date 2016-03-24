//
//  Created by TaoSama on 2015-08-16
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
#include <sstream>
#include <vector>
#include <cassert>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, T, speed[6];
bool ele[6][100];
vector<int> G[6];

int dp[100];
bool done[100];
typedef pair<int, int> Sta;
int dijkstra() {
    priority_queue<Sta, vector<Sta>, greater<Sta> > q;
    memset(dp, 0x3f, sizeof dp);
    memset(done, false, sizeof done);
    dp[0] = 0; q.push(Sta(0, 0));
    while(q.size()) {
        int u = q.top().second; q.pop();
        done[u] = true;
//      cout << "->" << u;
        for(int i = 1; i <= n; ++i) {
            if(!ele[i][u]) continue; //non-stop at u
            for(int j = 0; j < G[i].size(); ++j) {
                int &v = G[i][j];
                int cost = abs(u - v) * speed[i] + (u ? 60 : 0);
                if(!done[v] && dp[v] > dp[u] + cost) {
//                  cout << u << ' ' << v << ' ' << cost << endl;
                    assert(v != 0);
                    dp[v] = dp[u] + cost;
                    q.push(Sta(dp[v], v));
                }
            }
        }
    }
    return dp[T];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> T) {
        for(int i = 1; i <= n; ++i) cin >> speed[i];

        cin.get();
        memset(ele, false, sizeof ele);
        for(int i = 1; i <= n; ++i) {
            G[i].clear();
            int x; string buf; getline(cin, buf);
            stringstream ss(buf);
            while(ss >> x) {
                ele[i][x] = true;
                G[i].push_back(x);
            }
        }
        int ans = dijkstra();
        if(ans == INF) cout << "IMPOSSIBLE\n";
        else cout << ans << '\n';
//      return 0;
    }
    return 0;
}
