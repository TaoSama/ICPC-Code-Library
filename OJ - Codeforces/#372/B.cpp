//
//  Created by TaoSama on 2016-09-17
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 1e4 + 10;

typedef long long LL;
const LL LLINF = 0x3f3f3f3f3f3f3f3fLL;
LL f[N][N];
bool done[N][N];
pair<int, int> pre[N][N];

int n, m, L, s, t;
struct Edge {
    int u, v, nxt, c;
} edges[M << 1];
int head[N], cnt;
void addEdge(int u, int v, int c) {
    edges[cnt] = {u, v, head[u], c};
    head[u] = cnt++;
}

void dijkstra() {
    typedef pair<LL, pair<int, int> > Sta;
    priority_queue<Sta, vector<Sta>, greater<Sta> > q;
    q.push({0, {s, 0}});
    memset(f, 0x3f, sizeof f);
    memset(done, 0, sizeof done);
    f[s][0] = 0; pre[s][0] = { -1, -1};
    while(q.size()) {
        Sta p = q.top(); q.pop();
        int u, x; tie(u, x) = p.second;
        if(done[u][x]) continue;
        done[u][x] = true;

        for(int i = head[u]; ~i; i = edges[i].nxt) {
            int v = edges[i].v, c = edges[i].c;
            int y = x + (c == 0);
            if(y < n && !done[v][y] && f[v][y] > f[u][x] + c) {
                f[v][y] = f[u][x] + c;
                pre[v][y] = {i, x};
                q.push({f[v][y], {v, y}});
            }
        }
    }
}

vector<int> getPath(int t, int x) {
    vector<int> ret;
    while(pre[t][x].first != -1) {
        tie(t, x) = pre[t][x];
        ret.push_back(t);
        t = edges[t].u;
    }
    return ret;
}


int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d%d%d", &n, &m, &L, &s, &t) == 5) {
        cnt = 0; memset(head, -1, sizeof head);
        for(int i = 1; i <= m; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            addEdge(u, v, c);
            addEdge(v, u, c);
        }
        dijkstra();

        if(f[t][0] < L) {puts("NO"); continue;}
        bool ok = false;
        if(f[t][0] == L) ok = true;

        for(int i = 1; i < n && !ok; ++i) {
            if(f[t][i] < L) {
                LL delta = L - f[t][i];
                if(delta >= i) {
                    bool first = true;
                    vector<int> path = getPath(t, i);
                    for(int x : path) {
                        x = x / 2 * 2;
                        if(!edges[x].c) {
                            edges[x].c = 1;
                            if(first) {
                                edges[x].c += delta - i;
                                first = false;
                            }
                        }
                    }
                    ok = true;
                }
            }
        }
        if(ok) {
            puts("YES");
            for(int i = 0; i < cnt; i += 2) {
                if(!edges[i].c) edges[i].c = INF;
                printf("%d %d %d\n", edges[i].u, edges[i].v, edges[i].c);
            }
        } else puts("NO");

    }

    return 0;
}
