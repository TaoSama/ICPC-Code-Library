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
const int N = 300 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, w[N][N];
int match[N], lx[N], ly[N], slack[N];
bool S[N], T[N];

bool dfs(int i) {
    S[i] = true;
    for(int j = 1; j <= n; ++j) {
        if(T[j]) continue;
        if(lx[i] + ly[j] == w[i][j]) {
            T[j] = true;
            if(!match[j] || dfs(match[j])) {
                match[j] = i;
                return true;
            }
        } else slack[j] = min(slack[j], lx[i] + ly[j] - w[i][j]);
    }
    return false;
}

void update() {
    int a = INF;
    for(int j = 1; j <= n; ++j)
        if(!T[j]) a = min(a, slack[j]);
    for(int i = 1; i <= n; ++i) {
        if(S[i]) lx[i] -= a;
        if(T[i]) ly[i] += a;
        else slack[i] -= a;
    }
}

int km() {
    for(int i = 1; i <= n; ++i) {
        match[i] = lx[i] = ly[i] = 0;
        for(int j = 1; j <= n; ++j)
            lx[i] = max(lx[i], w[i][j]);
    }
    for(int i = 1; i <= n; ++i) {
        memset(slack, 0x3f, sizeof slack);
        while(true) {
            memset(S, false, sizeof S);
            memset(T, false, sizeof T);
            if(dfs(i)) break;
            else update();
        }
    }
    int ret = 0;
    for(int i = 1; i <= n; ++i) if(match[i]) ret += w[match[i]][i];
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                scanf("%d", &w[i][j]);
        printf("%d\n", km());
    }
    return 0;
}
