//
//  Created by TaoSama on 2017-05-25
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int g[N][N], slack[N];
int lx[N], ly[N];
int match[N], n;
bool vx[N], vy[N];
bool dfs(int u) {
    vx[u] = 1;
    for(int i = 1; i <= n; i++) {
        if(!vy[i]) {
            int t = lx[u] + ly[i] - g[u][i];
            if(t == 0) {
                vy[i] = 1;
                if(match[i] == -1 || dfs(match[i])) {
                    match[i] = u;
                    return 1;
                }
            } else slack[i] = min(slack[i], t);
        }
    }
    return 0;
}

void KM() {
    memset(match, -1, sizeof(match));
    memset(ly, 0, sizeof(ly));
    for(int i = 1; i <= n; i++) {
        lx[i] = -INF;
        for(int j = 1; j <= n; j++)
            lx[i] = max(lx[i], g[i][j]);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) slack[j] = INF;
        while(1) {
            memset(vx, 0, sizeof(vx));
            memset(vy, 0, sizeof(vy));
            if(dfs(i)) break;
            int d = INF;
            for(int j = 1; j <= n; j++)
                if(!vy[j]) d = min(d, slack[j]);
            for(int j = 1; j <= n; j++)
                if(vx[j]) lx[j] -= d;
            for(int j = 1; j <= n; j++)
                if(vy[j]) ly[j] += d;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);



    return 0;
}
