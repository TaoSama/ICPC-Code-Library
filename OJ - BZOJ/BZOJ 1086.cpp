//
//  Created by TaoSama on 2016-08-08
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

int n, B;
vector<int> G[N];

int stk[N], top;
int blocks, id[N], rt[N];

void dfs(int u, int f) {
    int btm = top;
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(v == f) continue;
        dfs(v, u);
        if(top - btm >= B) {
            rt[++blocks] = u;
            while(top != btm) {
                int v = stk[top--];
                id[v] = blocks;
            }
        }
    }
    stk[++top] = u;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &B);
    for(int i = 1; i < n; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1, 0);
    while(top) id[stk[top--]] = blocks;

    printf("%d\n", blocks);
    for(int i = 1; i <= n; ++i) printf("%d%c", id[i], " \n"[i == n]);
    for(int i = 1; i <= blocks; ++i) printf("%d%c", rt[i], " \n"[i == blocks]);

    return 0;
}
