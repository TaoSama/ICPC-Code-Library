//
//  Created by TaoSama on 2016-11-19
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

int n, m, s;
vector<pair<int, int> > G[N], rG[N];
int f[N], rf[N];
bool in[N];

void spfa(int* f, vector<pair<int, int> >* G) {
    memset(f, 0x3f, sizeof(int) * (n + 5));
    memset(in, 0, sizeof(bool) * (n + 5));
    f[s] = 0;  in[s] = 1;
    queue<int> q; q.push(s);
    while(q.size()) {
        int u = q.front(); q.pop();
        in[u] = false;
        for(int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i].first, c = G[u][i].second;
            if(f[v] > f[u] + c) {
                f[v] = f[u] + c;
                if(!in[v]) in[v] = true, q.push(v);
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

    while(scanf("%d%d%d", &n, &m, &s) == 3) {
        for(int i = 1; i <= n; ++i) G[i].clear(), rG[i].clear();
        for(int i = 1; i <= m; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            G[u].push_back(make_pair(v, c));
            swap(u, v);
            rG[u].push_back(make_pair(v, c));
        }
        spfa(f, G);
        spfa(rf, rG);
        int ans = -INF;
        for(int i = 1; i <= n; ++i) {
//          printf("%d: %d %d\n", i, f[i], rf[i]);
            ans = max(ans, f[i] + rf[i]);
        }
        printf("%d\n", ans);
    }

    return 0;
}
