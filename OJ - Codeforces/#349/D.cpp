//
//  Created by TaoSama on 2016-04-30
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
const int N = 3e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
vector<int> G[N];

typedef pair<int, int> P;
int d[N][N];
P o[N][N], r[N][N]; //original i->j, reversing i<-j

void bfs(int s, int* d) {
    queue<int> q; q.push(s);
    for(int i = 1; i <= n; ++i) d[i] = -1;
    d[s] = 0;
    while(q.size()) {
        int u = q.front(); q.pop();
        for(int v : G[u]) {
            if(d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &m);
    while(m--) {
        int u, v; scanf("%d%d", &u, &v);
        G[u].push_back(v);
    }

    for(int i = 1; i <= n; ++i) bfs(i, d[i]);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            o[i][j] = {d[i][j], j}, r[i][j] = {d[j][i], j};

    for(int i = 1; i <= n; ++i) sort(o[i] + 1, o[i] + 1 + n);
    for(int i = 1; i <= n; ++i) sort(r[i] + 1, r[i] + 1 + n);

    int sum = 0;
    vector<int> ans;  //不可达的是最小的
    for(int b = 1; b <= n; ++b) {
        for(int c = 1; c <= n; ++c) {
            if(b == c || d[b][c] == -1) continue;
            int x, y, i;

            //x first
            i = n;
            if(~r[b][i].second)
                while(r[b][i].second == b || r[b][i].second == c) --i;
            x = r[b][i].second;

            i = n;
            if(~o[c][i].second)
                while(o[c][i].second == b || o[c][i].second == c
                        || o[c][i].second == x) --i;
            y = o[c][i].second;

            if(~d[x][b] && ~d[c][y]) {
                int tmp = d[x][b] + d[b][c] + d[c][y];
                if(tmp > sum) sum = tmp, ans = {x, b, c, y};
            }

            //y first
            i = n;
            if(~o[c][i].second)
                while(o[c][i].second == b || o[c][i].second == c) --i;
            y = o[c][i].second;

            i = n;
            if(~r[b][i].second)
                while(r[b][i].second == b || r[b][i].second == c ||
                        r[b][i].second == y) --i;
            x = r[b][i].second;

            if(~d[x][b] && ~d[c][y]) {
                int tmp = d[x][b] + d[b][c] + d[c][y];
                if(tmp > sum) sum = tmp, ans = {x, b, c, y};
            }
        }
    }

    for(int x : ans) printf("%d ", x); puts("");
    return 0;
}
