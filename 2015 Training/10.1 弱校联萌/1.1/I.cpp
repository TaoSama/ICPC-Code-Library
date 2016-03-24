//
//  Created by TaoSama on 2015-10-01
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
const int M = 1e6 + 10;

int n, m, a, b, T;
bool des[N];

int head[N], pnt[M], nxt[M], cnt;
void add_edge(int u, int v) {
    pnt[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

int dp[N], con[N];
int bfs() {
    queue<int> q;
    memset(dp, 0x3f, sizeof dp);
    dp[1] = 0; q.push(1);
    while(q.size()) {
        int u = q.front(); q.pop();
        for(int i = head[u]; ~i; i = nxt[i]) {
            int v = pnt[i];
            if(dp[v] == INF) {
                dp[v] = dp[u] + 1;
                if(v == n) return dp[v];
                q.push(v);
            }
        }
    }
    return dp[n];
}

int cbfs() {
    queue<int> q;
    memset(dp, 0x3f, sizeof dp);
    memset(con, 0, sizeof con);
    set<int> s;
    for(int i = 2; i <= n; ++i) s.insert(i);
    dp[1] = 0; q.push(1);
    while(q.size()) {
        int u = q.front(); q.pop();
        for(int i = head[u]; ~i; i = nxt[i]) con[pnt[i]] = u;
        int v = -1;
        while(true) {
            set<int>::iterator iter = s.upper_bound(v);
            if(iter == s.end()) break;
            v = *iter;
            if(con[v] != u) {
                s.erase(iter);
                dp[v] = dp[u] + 1;
                if(v == n) return dp[v];
                q.push(v);
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

    while(scanf("%d%d%d%d", &n, &m, &a, &b) == 4) {
        bool ori = false;
        cnt = 0; memset(head, -1, sizeof head);
        memset(des, false, sizeof des);
        for(int i = 1; i <= m; ++i) {
            int u = read(), v = read();
            if(u > v) swap(u, v);
            add_edge(u, v);
            add_edge(v, u);
            if(v == n) des[u] = true;
            if(u == 1 && v == n) ori = true;
        }
        long long ans;
        if(a < b) {
            if(ori) ans = a;
            else {
                ans = min(0LL + b, 1LL * a * bfs());
            }
        } else {
            if(!ori) ans = b;
            else {
                ans = min(0LL + a, 1LL * b * cbfs());
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
