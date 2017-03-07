//
//  Created by TaoSama on 2017-01-29
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

typedef long long LL;

int n;
vector<int> G[N];
LL f[N][2][2];

inline void add(LL& x, LL y) {
    if((x += y) >= MOD) x -= MOD;
}
inline void mul(LL& x, LL y) {
    x = x * y % MOD;
}

void dfs(int u, int fa) {
    for(int i = 0; i < 2; ++i) f[u][i][0] = 1, f[u][i][1] = 1;

    for(int v : G[u]) {
        if(v == fa) continue;
        dfs(v, u);
        for(int i = 0; i < 2; ++i) {
            mul(f[u][i][0], f[v][i ^ 1][1]);
            mul(f[u][i][1], f[v][i][0] + f[v][i][1] + f[v][i ^ 1][1]); //choose all
        }
    }

    //- choose no = choose at least 1
    for(int i = 0; i < 2; ++i) add(f[u][i][1], MOD - f[u][i][0]);

//    for(int i = 0; i < 2; ++i) {
//        for(int j = 0; j < 2; ++j) {
//            printf("f[%d][%d][%d] = %I64d\n", u, i, j, f[u][i][j]);
//        }
//    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
//    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);


    int ans = (f[1][0][1] + f[1][1][1]) % MOD;
    cout << ans << endl;

    return 0;
}
