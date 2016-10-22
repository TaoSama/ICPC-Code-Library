//
//  Created by TaoSama on 2016-09-10
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
#include <list>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 4e4 + 10;

int n, m;
struct Edge {
    int v, nxt;
} edges[M];
int head[N], cnt;
void addEdge(int u, int v) {
    edges[cnt] = {v, head[u]};
    head[u] = cnt++;
}

int dp[N], con[N];
void cbfs(int src) {
    vector<int> q;
    memset(dp, -1, sizeof dp);
    memset(con, 0, sizeof con);
    list<int> s;
    for(int i = 1; i <= n; ++i) if(i != src) s.insert(s.end(), i);
    dp[src] = 0; q.push_back(src);
    for(int i = 0; i < q.size(); ++i) {
        int u = q[i];
        for(int i = head[u]; ~i; i = edges[i].nxt) {
            int v = edges[i].v;
            con[v] = u;
        }
        for(auto iter = s.begin(); iter != s.end();) {
            int v = *iter;
            if(con[v] != u) {
                dp[v] = dp[u] + 1;
                q.push_back(v);
                iter = s.erase(iter);
            } else ++iter;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        cnt = 0; memset(head, -1, sizeof head);
        for(int i = 1; i <= m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }

        int s; scanf("%d", &s);
        cbfs(s);

        bool first = true;
        for(int i = 1; i <= n; ++i) {
            if(i == s) continue;
            if(first) first = false;
            else putchar(' ');
            printf("%d", dp[i]);
        }
        puts("");
    }

    return 0;
}
