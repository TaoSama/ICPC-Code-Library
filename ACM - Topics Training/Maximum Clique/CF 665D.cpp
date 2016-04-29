//
//  Created by TaoSama on 2016-04-29
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
const int N = 2e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct MaxClique {
    static const int V = 1e3 + 10;
    bool g[V][V];
    int n, ans, max[V], adj[V][V];
    int path[V], clique[V]; //for record
    //max[i]:= [i, n]'s maximum clique
    //adj[dep][i]:= available vertices

    void init(int _n) { n = _n; }

    bool dfs(int cur, int dep) {
        if(cur == 0) {
            if(dep > ans) {
                ans = dep;
                swap(clique, path);
                return 1;
            }
            return 0;
        }
        for(int i = 0; i < cur; ++i) {
            if(dep + cur - i <= ans) return 0; //dep + left <= ans
            int u = adj[dep][i], nxt = 0;
            if(dep + max[u] <= ans) return 0; //same as above
            path[dep] = u;
            for(int j = i + 1; j < cur; ++j) {
                int v = adj[dep][j];
                if(g[u][v]) adj[dep + 1][nxt++] = v;
            }
            if(dfs(nxt, dep + 1)) return 1;
        }
        return 0;
    }
    int maxClique() {
        ans = 0;
        memset(max, 0, sizeof max);
        for(int i = n - 1; ~i; --i) {
            int cur = 0;
            for(int j = i + 1; j < n; ++j)
                if(g[i][j]) adj[1][cur++] = j;
            path[0] = i;
            dfs(cur, 1);
            max[i] = ans;
        }
        return ans;
    }
} solver;

int n;
bool notPrime[N];
void gao() {
    for(int i = 2; i * i < N; ++i) {
        if(notPrime[i]) continue;
        for(int j = i * i; j < N; j += i) notPrime[j] = true;
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    gao();
    while(scanf("%d", &n) == 1) {
        vector<int> a(n);
        for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
        solver.init(n);
        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j)
                solver.g[i][j] = solver.g[j][i] = !notPrime[a[i] + a[j]];
        int ans = solver.maxClique();
        printf("%d\n", ans);
        for(int i = 0; i < ans; ++i)
            printf("%d%c", a[solver.clique[i]], " \n"[i == ans - 1]);
    }
    return 0;
}
