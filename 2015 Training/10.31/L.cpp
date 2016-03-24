//
//  Created by TaoSama on 2015-10-31
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, k;
int lef[N], rig[N];
bool S[N], T[N];
vector<int> G[N];

bool dfs(int u) {
    S[u] = true;
    for(auto v : G[u]) {
        if(T[v]) continue;
        T[v] = true;
        if(lef[v] == -1 || dfs(lef[v])) {
            lef[v] = u;
            rig[u] = v;
            return true;
        }
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &m, &k) == 3 && (n || m || k)) {
        for(int i = 1; i <= n; ++i) G[i].clear();
        while(k--) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
        }
        memset(lef, -1, sizeof lef);
        memset(rig, -1, sizeof rig);
        memset(S, false, sizeof S);
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            memset(T, false, sizeof T);
            ans += dfs(i);
        }

        memset(S, false, sizeof S);
        memset(T, false, sizeof T);
        for(int i = 1; i <= n; ++i)
            if(rig[i] == -1) dfs(i);

        printf("%d", ans);
        for(int i = 1; i <= n; ++i)
            if(!S[i]) printf(" r%d", i);
        for(int i = 1; i <= n; ++i)
            if(T[i]) printf(" c%d", i);
        puts("");
    }
    return 0;
}
