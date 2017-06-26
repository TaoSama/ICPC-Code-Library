//
//  Created by TaoSama on 2017-06-17
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
struct Edge {
    int v, id, c, nxt;
} edges[N];
int head[N], cnt;
void addEdge(int u, int v, int id, int c) {
    edges[cnt] = {v, id, c, head[u]};
    head[u] = cnt++;
}
char ans[N];

void dfs(int u) {
    for(int& i = head[u]; ~i; i = edges[i].nxt) {
        Edge& e = edges[i];
        int v = e.v, id = e.id, c = e.c;
        if(id == -2) continue;
        edges[i].id = edges[i ^ 1].id = -2;
        if(id > 0) ans[id] = char('0' + c);
        dfs(v);
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &m);
    vector<int> deg(n + 1, 0);
    cnt = 0;
    for(int i = 1; i <= n; ++i) head[i] = -1;
    for(int i = 1; i <= m; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        ++deg[v]; ++deg[u];
        addEdge(u, v, i, 0);
        addEdge(v, u, i, 1);
    }
    int c = 0;
    vector<int> odd;
    for(int i = 1; i <= n; ++i) {
        if(deg[i] & 1) odd.push_back(i);
        else {
            ++c;
        }
    }
    for(int i = 0; i < odd.size(); i += 2) {
        int u = odd[i], v = odd[i + 1];
        addEdge(u, v, -1, -1);
        addEdge(v, u, -1, -1);
    }
    for(int i = 1; i <= n; ++i) dfs(i);
    ans[m + 1] = 0;
    printf("%d\n%s\n", c, ans + 1);

    return 0;
}
