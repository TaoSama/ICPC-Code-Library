//
//  Created by TaoSama on 2015-05-06
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

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, Max, sum;
int head[N], pnt[N], nxt[N], cost[N], cnt;

void add_edge(int u, int v, int c) {
    pnt[cnt] = v;
    cost[cnt] = c;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

void dfs(int u, int sum) {
    if(~head[u]) {
        for(int i = head[u]; ~i; i = nxt[i]) {
            int v = pnt[i];
            dfs(v, sum + cost[i]);
        }
    }
    else Max = max(Max, sum);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        cnt = sum = Max = 0;
        memset(head, -1, sizeof head);
        for(int i = 1; i < n; ++i) {
            int x, y, c; scanf("%d%d%d", &x, &y, &c);
            sum += c;
            add_edge(x, y, c);
        }
        dfs(1, 0);
        printf("%d\n", sum - Max);
    }
    return 0;
}
