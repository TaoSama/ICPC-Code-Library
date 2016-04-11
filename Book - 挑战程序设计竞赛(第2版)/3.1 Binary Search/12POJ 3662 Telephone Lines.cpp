//
//  Created by TaoSama on 2015-04-29
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

int n, p, k, d[1005];

int pnt[20005], nxt[20005], dis[20005], head[20005], cnt;
bool in[1005];

void add_edge(int u, int v, int d) {
    pnt[cnt] = v;
    dis[cnt] = d;
    nxt[cnt] = head[u];
    head[u] = cnt ++;
}

int spfa(int x) {
    queue<int> q; q.push(1);
    memset(d, 0x3f, sizeof d);
    memset(in, false, sizeof in);
    in[1] = true; d[1] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        in[u] = false;
        for(int i = head[u]; ~i; i = nxt[i]) {
            int &v = pnt[i];
            int t = d[u] + (dis[i] >= x ? 1 : 0);
            if(d[v] > t) {
                d[v] = t;
                if(!in[v]) {
                    q.push(v);
                    in[v] = true;
                }
            }
        }
    }
    return d[n];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d%d", &n, &p, &k);
    cnt = 0;
    memset(head, -1, sizeof head);
    for(int i = 1; i <= p; ++i) {
        int u, v, d; scanf("%d%d%d", &u, &v, &d);
        add_edge(u, v, d);
        add_edge(v, u, d);
    }

    int l = 0, r = 1e6 + 2;
    while(l + 1 < r) {
        int mid = l + r >> 1;
        if(spfa(mid) > k) l = mid;
        else r = mid;
    }

    int ans = l > 1e6 ? - 1 : l;
    printf("%d\n", ans);
    return 0;
}
