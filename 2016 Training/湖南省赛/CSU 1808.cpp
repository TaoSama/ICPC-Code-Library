//
//  Created by TaoSama on 2016-09-05
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

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
struct Edge {
    int v, nxt, c, t;
} edge[N << 1];
int head[N], cnt;
void addEdge(int u, int v, int c, int t) {
    edge[cnt] = {v, head[u], c, t};
    head[u] = cnt++;
}

typedef long long LL;

bool done[N << 1];
LL f[N << 1]; //以i为入边的最短路
typedef pair<LL, int> Sta;
LL dijkstra() {
    priority_queue<Sta, vector<Sta>, greater<Sta> > q;
    memset(done, 0, sizeof done);
    memset(f, 0x3f, sizeof f);
    f[0] = 0; q.push({0, 0});
    while(q.size()) {
        int i = q.top().second; q.pop();
        if(done[i]) continue;
        done[i] = true;

        int u = edge[i].v, c = edge[i].c;
        for(int j = head[u]; ~j; j = edge[j].nxt) {
            int nc = edge[j].c, t = edge[j].t;
            LL newOne = f[i] + t + (c == -1 ? 0 : abs(c - nc));
            if(!done[j] && f[j] > newOne) {
                f[j] = newOne;
                q.push({f[j], j});
            }
        }
    }

    LL ans = 1e18;
    for(int i = 0; i < cnt; ++i)
        if(edge[i].v == n) ans = min(ans, f[i]);
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        cnt = 0; memset(head, -1, sizeof head);

        addEdge(0, 1, -1, 0); //0->1
        for(int i = 1; i <= m; ++i) {
            int u, v, c, t; scanf("%d%d%d%d", &u, &v, &c, &t);
            addEdge(u, v, c, t);
            addEdge(v, u, c, t);
        }

        printf("%lld\n", dijkstra());
    }

    return 0;
}
