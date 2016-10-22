//
//  Created by TaoSama on 2016-08-29
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;

vector<int> G[N];
int dfn[N], low[N], in[N], id[N], bcc, dfsNum;
int stk[N], top;
int sz[N];

void tarjan(int u) {
    dfn[u] = low[u] = ++dfsNum;
    stk[++top] = u;
    in[u] = true;
    for(int v : G[u]) {
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(in[v]) low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]) {
        ++bcc;
        while(true) {
            int v = stk[top--];
            in[v] = false;
            id[v] = bcc;
            if(v == u) break;
        }
    }
}

void init() {
    bcc = dfsNum = 0;
    memset(dfn, 0, sizeof dfn);
    for(int i = 1; i <= n; ++i) if(!dfn[i]) tarjan(i);
}

typedef long long LL;
LL two[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    two[0] = 1;
    for(int i = 1; i < N; ++i) two[i] = two[i - 1] * 2 % MOD;
    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= n; ++i) {
            int a; scanf("%d", &a);
            G[i].push_back(a);
        }
        init();
        memset(sz, 0, sizeof sz);
        for(int i = 1; i <= n; ++i) {
            ++sz[id[i]];
        }

        LL ans = 1;
        int sum = 0;
        for(int i = 1; i <= bcc; ++i) {
            if(sz[i] == 1) continue;
            sum += sz[i];
            ans *= two[sz[i]] - 2;
            ans %= MOD;
        }
//        pr(sum); prln(ans);
        ans = ans * two[n - sum] % MOD;
        ans = (ans + MOD) % MOD;
        printf("%I64d\n", ans);
    }

    return 0;
}
