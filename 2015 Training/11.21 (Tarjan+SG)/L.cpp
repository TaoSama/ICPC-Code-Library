//
//  Created by TaoSama on 2015-11-24
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

int n, k;
struct Edge {
    int v, nxt;
} edge[205];
int head[105], cnt;

void addEdge(int u, int v) {
    edge[cnt] = (Edge) {v, head[u]};
    head[u] = cnt++;
}

int dfs(int u, int f) {
    int ret = 0;
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(v == f) continue;
        ret ^= 1 + dfs(v, u);
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        int sg = 0, gOne = 0;
        for(int i = 1; i <= n; ++i) {
            int k; scanf("%d", &k);
            cnt = 0; memset(head, -1, sizeof head);
            for(int j = 1; j < k; ++j) {
                int u, v; scanf("%d%d", &u, &v);
                addEdge(u, v);
                addEdge(v, u);
            }
            int tmp = dfs(1, -1);
            sg ^= tmp; gOne += tmp > 1;
        }
        if(sg && gOne || !sg && !gOne) puts("PP");
        else puts("QQ");
    }
    return 0;
}
