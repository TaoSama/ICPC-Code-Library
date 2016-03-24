//
//  Created by TaoSama on 2015-10-02
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

int fa[N], cur[N], head[N], nxt[N], pnt[N], cnt;
void add_edge(int u, int v) {
    pnt[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

int stk[N], top;

int n, val[N], sum[N], a[N];
LL ans;

void calc(int u) {
    int sz = 0;
    for(int i = head[u]; ~i; i = nxt[i]) {
        int v = pnt[i];
        a[sz++] = sum[v];
    }
    sort(a, a + sz, greater<int>());
    sum[u] = val[u];
    for(int i = 0; i < sz; ++i) {
        sum[u] += a[i];
        ans += 1LL * i * a[i];
    }
}

void dfs(int s) {
    top = 0;
    stk[++top] = s;
    while(top) {
        int u = stk[top];
        for(int& i = cur[u]; ~i; i = nxt[i]) {
            int v = pnt[i];
            stk[++top] = v;
            break;
        }
        if(cur[u] == -1){
            calc(u);
            --top;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        cnt = 0; memset(head, -1, sizeof head);
        for(int v = 0; v < n; ++v) {
            scanf("%d%d", val + v, fa + v);
            if(~fa[v]) add_edge(fa[v], v);
        }
        ans = 0;
        memcpy(cur, head, sizeof head);
        for(int i = 0; i < n; ++i) {
            if(fa[i] == -1) dfs(i);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
