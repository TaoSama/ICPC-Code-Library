//
//  Created by TaoSama on 2015-08-21
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

int n, m, k;
int in[105], g[105][105];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &m, &k) == 3) {
        memset(g, 0, sizeof g);
        memset(in, 0, sizeof in);
        for(int i = 1; i <= m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            if(!g[u][v]) {
                g[u][v] = true;
                ++in[v];
            }
        }

        vector<int> ans;
        priority_queue<int, vector<int>, greater<int> > q;
        for(int i = 0; i < n; ++i)
            if(!in[i]) q.push(i);
        while(q.size() && ans.size() < k) {
            int u = q.top(); q.pop();
            ans.push_back(u);
            for(int i = 0; i < n; ++i) {
                if(g[u][i] && --in[i] == 0)
                    q.push(i);
            }
        }
        if(ans.size() < k) puts("-1");
        else {
            for(int i = 0; i < k; ++i)
                printf("%d%c", ans[i], " \n"[i == k - 1]);
        }
    }
    return 0;
}
