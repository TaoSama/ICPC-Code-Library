//
//  Created by TaoSama on 2016-09-30
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
const int N = 5e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, t;
typedef long long LL;
int f[N][N];
bool done[N][N];
int pre[N][N];
vector<pair<int, int> > G[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &m, &t) == 3) {
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= m; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            G[u].push_back({v, c});
        }

        typedef pair<LL, pair<int, int> > Sta;
        priority_queue<Sta, vector<Sta>, greater<Sta> > q;
        q.push({0, {1, 1}});
        pre[1][1] = -1;
        memset(f, 0x3f, sizeof f);
        memset(done, 0, sizeof done);
        f[1][1] = 0;
        while(q.size()) {
            Sta p = q.top(); q.pop();
            int u, x; tie(u, x) = p.second;
            if(done[u][x]) continue;
            done[u][x] = true;
            for(auto& e : G[u]) {
                int v, c; tie(v, c) = e;
                int newOne = f[u][x] + c;
                if(newOne > t) continue;
                if(!done[v][x + 1] && f[v][x + 1] > newOne) {
                    f[v][x + 1] = f[u][x] + c;
                    pre[v][x + 1] = u;
                    q.push({f[v][x + 1], {v, x + 1}});
                }
            }
        }
//        puts("....1");

        int x = -1;
        for(int i = n; i; --i) {
            if(f[n][i] <= t) {
                x = i;
                break;
            }
        }

        vector<int> path;
        int u = n;
        while(true) {
            path.push_back(u);
            u = pre[u][x];
            --x;
            if(!x) break;
        }
        reverse(path.begin(), path.end());
        printf("%d\n", path.size());
        for(int i = 0; i < path.size(); ++i)
            printf("%d%c", path[i], " \n"[i + 1 == path.size()]);
    }

    return 0;
}
