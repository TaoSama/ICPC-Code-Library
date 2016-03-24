//
//  Created by TaoSama on 2015-08-22
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

int n, m;
long long dp[1500][5];
int cnt[1500][5];
struct Edge {
    int to, cost, op;
};
vector<Edge> G[1500];

const char *word = "LOVE";

bool in[1500][5];
typedef pair<int, int> P;
void spfa() {
    queue<P> q; q.push(P(1, 4));
    memset(dp, 0x3f, sizeof dp);
    memset(cnt, 0, sizeof cnt);
    memset(in, false, sizeof in);
    dp[1][4] = 0; in[1][4] = true;
    while(q.size()) {
        int u = q.front().first, last = q.front().second; q.pop();
        in[u][last] = false;
        for(int i = 0; i < G[u].size(); ++i) {
            Edge &e = G[u][i];
            if(last == 4 && e.op != 0 || last != 4 && e.op != (last + 1) % 4) continue;
//          printf("u: %d v: %d last: %d cur: %d\n", u, e.to, last, e.op);
            if(dp[e.to][e.op] > dp[u][last] + e.cost) {
                dp[e.to][e.op] = dp[u][last] + e.cost;
                cnt[e.to][e.op] = cnt[u][last] + (e.op == 3);
                if(!in[e.to][e.op]) {
                    q.push(P(e.to, e.op));
                    in[e.to][e.op] = true;
                }
            } else if(dp[e.to][e.op] == dp[u][last] + e.cost) {
                if(cnt[e.to][e.op] <= cnt[u][last]) {
                    cnt[e.to][e.op] = cnt[u][last] + (e.op == 3);
                    if(!in[e.to][e.op]) {
                        q.push(P(e.to, e.op));
                        in[e.to][e.op] = true;
                    }
                }
            }
        }
    }
}

map<char, int> mp;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    for(int i = 0; i < 4; ++i) mp[word[i]] = i;
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= m; ++i) {
            int u, v, c; char op[2];
            scanf("%d%d%d%s", &u, &v, &c, op);
            G[u].push_back((Edge) {v, c, mp[op[0]]});
            G[v].push_back((Edge) {u, c, mp[op[0]]});
        }
        spfa();
        printf("Case %d: ", ++kase);
        if(dp[n][3] == INF || cnt[n][3] == 0)
            puts("Binbin you disappoint Sangsang again, damn it!");
        else {
            printf("Cute Sangsang, Binbin will come with a donkey after travelling ");
            printf("%I64d meters and finding %d LOVE strings at last.\n", dp[n][3],
                   cnt[n][3]);
        }
    }
    return 0;
}
