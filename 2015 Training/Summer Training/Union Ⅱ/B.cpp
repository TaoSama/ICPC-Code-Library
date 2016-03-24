//
//  Created by TaoSama on 2015-08-24
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 1e5 + 10;

int n, m;

int pnt[M], nxt[M], cost[M], head[N], cnt;
void add_edge(int u, int v, int c) {
    pnt[cnt] = v;
    cost[cnt] = c;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

bool in[N], destroy[M];
int dp[N], pre[N];
int spfa(bool get) {
    queue<int> q; q.push(1);
    memset(dp, 0x3f, sizeof dp);
    memset(in, false, sizeof in);
    dp[1] = 0; in[1] = true;
    while(q.size()) {
        int u = q.front(); q.pop();
        in[u] = false;
        for(int i = head[u]; ~i; i = nxt[i]) {
            if(destroy[i]) continue;
            int v = pnt[i];
            if(dp[v] > dp[u] + cost[i]) {
                if(get) pre[v] = i;
                dp[v] = dp[u] + cost[i];
                if(!in[v]) q.push(v), in[v] = true;
            }
        }
    }
    return dp[n];
}

inline int read() {
    char c = getchar();
    while(!isdigit(c)) c = getchar();

    int x = 0;
    while(isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; t = read();
    while(t--) {
        n = read(); m = read();
        cnt = 0;
        memset(head, -1, sizeof head);
        memset(destroy, false, sizeof destroy);
        for(int i = 1; i <= m; ++i) {
            int u = read(), v = read(), c = read();
            add_edge(u, v, c);
            add_edge(v, u, c);
        }
        int ans = spfa(true);
        if(ans == INF) {puts("-1"); continue;}

        ans = -INF;
        for(int u = n, i; u != 1; u = pnt[i ^ 1]) {
            i = pre[u];
            destroy[i] = destroy[i ^ 1] = true;
            int cur = spfa(false);
            destroy[i] = destroy[i ^ 1] = false;
//          printf("u: %d\n", u);
            if(cur == INF) {
                ans = -1;
                break;
            }
            ans = max(ans, cur);
        }
        printf("%d\n", ans);
    }
    return 0;
}
