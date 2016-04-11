//
//  Created by TaoSama on 2015-08-05
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
const int N = 5e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int pnt[N << 1], nxt[N << 1], head[N << 1], cost[N << 1], cnt;

void add_edge(int u, int v, int c) {
    pnt[cnt] = v;
    cost[cnt] = c;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

long long ans;

int dfs(int u, int f) {
    int ret = 1;
    for(int i = head[u]; ~i; i = nxt[i]) {
        int v = pnt[i], c = cost[i];
        if(v == f) continue;
        int cur = dfs(v, u);
//      pr(v); prln(cur);
        ans += 1LL * c * abs(n - 2 * cur);
        ret += cur;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        cnt = 0;
        memset(head, -1, sizeof head);
        for(int i = 1; i < n; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            add_edge(u, v, c);
            add_edge(v, u, c);
        }

        ans = 0;
        dfs(1, -1);
        printf("%lld", ans);
        if(ans) puts("00000000");
        else puts("");
    }
    return 0;
}
