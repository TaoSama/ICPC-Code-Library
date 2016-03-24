//
//  Created by TaoSama on 2015-04-26
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
const int N = 2e6 + 10;

int n, m, k;
int T, pnt[N], cnt, head[N], nxt[N], tmp, pos;
bool vis[N];

struct P {
    int fee;
    bool used;
} p[N];

void addedge(int u, int v) {
    pnt[cnt] = v; nxt[cnt] = head[u]; head[u] = cnt++;
}

int bs, ds;
void bfs(int u) {
    queue<int> q;
    q.push(u);
    vis[u] = true;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        ds++;
        if(p[cur].fee < tmp) {
            tmp = p[cur].fee;
            pos = cur;
        }
        for(int i = head[cur]; i != -1; i = nxt[i]) {
            bs++;
            int v = pnt[i];
            if(!vis[v])  {
                q.push(v);
                vis[v] = true;
            }
        }
    }
}
bool cmp(const P &a, const P &b) {
    return a.fee < b.fee;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d%d%d", &n, &m, &k);
        memset(vis, false, sizeof vis);
        memset(p, false, sizeof p);
        memset(head, -1, sizeof head);

        for(int i = 1; i <= n; ++i) scanf("%d", &p[i].fee);
        for(int i = 1; i <= m; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            addedge(x, y);
            addedge(y, x);
        }

        long long ans = 0;
        for(int i = 1; i <= n; ++i)  if(!vis[i]) {
            pos = 0;
            bs = 0; ds = 0;
            tmp = INF;
            bfs(i);
            ans += tmp;
            p[pos].used = true;
            bs /= 2;
            k -= (bs - ds + 1);
        }
        sort(p + 1, p + 1 + n, cmp);
        int count = 0;
        if(k > 0)    for(int i = 1; i <= n; ++i) {
            if(count == k)   break;
            if(p[i].used == false) {
                ans += p[i].fee;
                count++;
            }
        }
        printf("Case #%d: %lld\n", ++kase, ans);
    }
    return 0;
}
