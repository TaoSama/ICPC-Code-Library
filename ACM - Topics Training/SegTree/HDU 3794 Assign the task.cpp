//
//  Created by TaoSama on 2015-09-17
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
const int N = 5e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q;
bool used[N];
vector<int> G[N];

/*
从树的根节点向下递归并对每个节点i按序编号为level[i].l，在遍历完所有i的子节点后记录i的编号最多子节点的编号为level[i].r
此时level[i].l到level[i].r区间就是点i的覆盖区域（自身加所有子节点），给i分配任务就相当于对[level[i].l，level[i].r]操作 这就可以用线段树处理了
*/

int st[N], ed[N], dfn;
void dfs(int u) {
    st[u] = ++dfn;
    for(int i = 0; i < G[u].size(); ++i)
        dfs(G[u][i]);
    ed[u] = dfn;
}

int col[N << 2];

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

void push_down(int rt) {
    if(col[rt] != -INF) {
        col[rt << 1] = col[rt << 1 | 1] = col[rt];
        col[rt] = -INF;
    }
}

void update(int L, int R, int c, int l, int r, int rt) {
    if(L <= l && r <= R) {
        col[rt] = c;
        return;
    }
    int m = l + r >> 1;
    push_down(rt);
    if(L <= m) update(L, R, c, lson);
    if(R > m) update(L, R, c, rson);
}

int query(int o, int l, int r, int rt) {
    if(l == r) return col[rt];
    int m = l + r >> 1;
    push_down(rt);
    if(o <= m) return query(o, lson);
    else return query(o, rson);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) G[i].clear();
        memset(used, false, sizeof used);
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &v, &u);
            G[u].push_back(v);
            used[v] = true;
        }

        dfn = 0;
        for(int i = 1; i <= n; ++i) {
            if(!used[i]) {
                dfs(i);
                break;
            }
        }
        col[1] = -1;
        printf("Case #%d:\n", ++kase);
        scanf("%d", &q);
        while(q--) {
            char op[2]; int x, y;
            scanf("%s%d", op, &x);
            if(*op == 'T') {
                scanf("%d", &y);
                update(st[x], ed[x], y, 1, dfn, 1);
            } else printf("%d\n", query(st[x], 1, dfn, 1));
        }
    }
    return 0;
}
