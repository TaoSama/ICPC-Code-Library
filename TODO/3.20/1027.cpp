//
//  Created by TaoSama on 2017-04-02
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e8 + 7;

int n;
vector<pair<int, int>> G[N];

typedef long long LL;
inline void add(LL& x, LL y) {
    (x += y) %= MOD;
}

int L[N], R[N], vs[N], w[N], dfsNum;

LL ans[N], sum[N], cnt[N], sz[N];
void dfs(int u, int fa, int c) {
    L[u] = ++dfsNum;
    vs[dfsNum] = u;
    w[dfsNum] = c;

    sz[u] = 1;
    ans[u] = sum[u] = cnt[u] = 0;
    for(auto& e : G[u]) {
        int v, c; tie(v, c) = e;
        if(v == fa) continue;
        dfs(v, u, c);
        sum[u] += sum[v] + c;
        sz[u] += sz[v];
    }
    for(auto& e : G[u]) {
        int v, c; tie(v, c) = e;
        if(v == fa) continue;
        int lft = sz[u] - sz[v];
        add(ans[u], ans[v]);
        add(ans[u], 1LL * sum[v] * lft % MOD);   //sons' subtree
        add(ans[u], 1LL * c * sz[v] * lft % MOD);
        add(cnt[u], cnt[v]);
        add(cnt[u], 1LL * cnt[v] * lft % MOD);
        add(cnt[u], 1LL * sz[v] * lft % MOD);
    }
    R[u] = dfsNum;
}

struct Node {
    int l, r, len;
    LL cnt, sum, ans, addv;
    Node(int l = -1, int r = -1) : l(l), r(r) {
        len = r - l + 1;
        cnt = sum = ans = addv = 0;
    }
    void add(LL v) {
        addv += v;
        ::add(sum, (len - 1) * v);
        ::add(ans, cnt * v);
    }
    void see(){
		pr(l); pr(r);pr(len);pr(cnt); pr(sum); prln(ans);
    }
} dat[N << 2];


void build(int l, int r, int rt) {
    if(l == r) {
		dat[rt] = Node(l, r);
        dat[rt].sum = dat[rt].ans = w[l];
        dat[rt].cnt = 1;
        return;
    }
    int m = l + r >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    dat[rt] = dat[rt << 1] + dat[rt << 1 | 1];
}

void down(int rt) {
    LL& lazy = dat[rt].addv;
    if(!lazy) return;
    dat[rt << 1].add(lazy);
    dat[rt << 1 | 1].add(lazy);
    lazy = 0;
}

Node query(int L, int R, int rt) {
    if(L <= dat[rt].l && dat[rt].r <= R) {
		return dat[rt];
    }
    down(rt);

    int m = (dat[rt].l + dat[rt].r) >> 1;
    Node ret;
    if(L <= m) ret = ret + query(L, R, rt << 1);
    if(R > m) ret = ret + query(L, R, rt << 1 | 1);
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) G[i].clear();

        vector<vector<int>> f(n+1,vector<int>(n+1,INF));
        for(int i = 1; i < n; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            G[u].push_back({v, c});
            G[v].push_back({u, c});
            f[u][v] = f[v][u] = c;
            f[u][u] = f[v][v] = 0;
        }
        for(int k = 1; k <= n; ++k)
			for(int i = 1; i <= n; ++i)
				for(int j = 1; j <= n; ++j)
					f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
		int tot = 0;
		for(int i = 1; i <= n; ++i)
			for(int j = i; j <= n; ++j)
				tot += f[i][j];
		printf("%d\n", tot);

        dfsNum = 0;
        dfs(1, 0, 0);
        build(1, n, 1);


//        dat[10].see();
//        dat[11].see();
//        (dat[10] +dat[11]).see();
//        (dat[5]).see();

		query(2,2,1).see();
		query(3,4,1).see();
		query(2,4,1).see();
		query(6,7,1).see();
		query(5,7,1).see();
		query(2,7,1).see();

        int q; scanf("%d", &q);
        while(q--) {
            int op, u; scanf("%d%d", &op, &u);
            if(op == 1) {
                int x; scanf("%d", &x);
            } else {
                LL to = query(L[u]+1,R[u],1).ans;
                printf("%lld %lld\n", ans[u], to);
            }
        }
    }

    return 0;
}
