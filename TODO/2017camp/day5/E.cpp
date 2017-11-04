//
//  Created by TaoSama on 2017-02-17
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
vector<int> G[N];
int w[N];

int l[N], r[N], dfsNum, vs[N];

void dfs(int u) {
    l[u] = ++dfsNum;
    vs[dfsNum] = u;
    for(int v : G[u]) dfs(v);
    r[u] = dfsNum;
}

struct SegmentTree {
    pair<int, int> minv[N << 2];
    void up(int rt) {
        minv[rt] = min(minv[rt << 1], minv[rt << 1 | 1]);
    }
    void build(int l, int r, int rt) {
        if(l == r) {
            minv[rt] = {w[vs[l]], vs[l]};
            return;
        }
        int m = l + r >> 1;
        build(l, m, rt << 1);
        build(m + 1, r, rt << 1 | 1);
        up(rt);
    }
    void update(int o, int l, int r, int rt) {
        if(l == r) {
            minv[rt] = {INF, INF};
            return;
        }
        int m = l + r >> 1;
        if(o <= m) update(o, l, m, rt << 1);
        else update(o, m + 1, r, rt << 1 | 1);
        up(rt);
    }
    pair<int, int> query(int L, int R, int l, int r, int rt) {
        if(L <= l && r <= R) {
            return minv[rt];
        }
        int m = l + r >> 1; pair<int, int> ret = {INF, INF};
        if(L <= m) ret = min(ret, query(L, R, l, m, rt << 1));
        if(R > m) ret = min(ret, query(L, R, m + 1, r, rt << 1 | 1));
        return ret;
    }
} T;

void dfs2(int u, vector<int>& ans){
	// prln(u);
	if(l[u] == r[u]){
		T.update(l[u], 1, n, 1);
		ans.push_back(u);
		return;
	}
    while(true){
        int v = T.query(l[u] + 1, r[u], 1, n, 1).second;
        if(v == INF) break;
        dfs2(v, ans);
    }
    ans.push_back(u);
    T.update(l[u], 1, n, 1);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    for(int i = 2; i <= n; ++i) {
        int fa; scanf("%d", &fa);
        G[fa].push_back(i);
    }
    for(int i = 1; i <= n; ++i) scanf("%d", w + i);
    prln(T.query(1,1,1,n,1).first);

    dfs(1);
    T.build(1, n, 1);

    vector<int> ans;
    dfs2(1, ans);
    for(int i = 0; i < ans.size(); ++i) printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);

    cerr << "bug" << endl;
    return 0;
}
