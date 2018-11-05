
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 10, INF = 0x3f3f3f3f, MOD = 19260817;

typedef unsigned long long LL;
int n, q;
LL seed;
struct Node {
    LL a[64], b[64];
    Node() {}
    Node(bool zero) {
        for(int i = 0; i < 64; ++i) {
            a[i] = b[i] = 0;
            if(!zero) {
                a[i] |= 1ull << i; b[i] |= 1ull << i;
            }
        }
    }
} M[N];
void input() {
    for(int i = 1; i <= n; ++i) {
       for(int p = 0; p < 64; ++p) {
           M[i].b[p] = 0;
           seed ^= seed * seed + 15;
           M[i].a[p] = seed;
           // if(p == 0) printf("%d: %llu\n", i, seed);
       } 
       for(int p = 0; p < 64; ++p) {
            for(int q = 0; q < 64; ++q) {
                M[i].b[p] |= (M[i].a[q] >> p & 1) << q;
            }
       }
    }
}
void add(LL& x, LL y) {
    if((x += y) >= MOD) x -= MOD;    
}
Node operator*(const Node& A, const Node& B) {
    Node ret(true);
    for(int i = 0; i < 64; ++i) {
        for(int j = 0; j < 64; ++j) {
            LL cur = __builtin_popcountll(A.a[i] & B.b[j]) & 1;
            ret.a[i] |= cur << j; ret.b[j] |= cur << i;
        }
    }
    return ret;
}

LL weight[64][64];

vector<int> v[N];
int fa[N][20];
Node mx[N][20];
Node rmx[N][20];
int depth[N];
int sons[N];
void dfs(int x, int p = -1)
{
	fa[x][0] = p;
    if(p != -1) rmx[x][0] = mx[x][0] = M[p];
    else rmx[x][0] = mx[x][0] = Node(false);
	depth[x] = 1;
	sons[x] = 1;
	if (p != -1) depth[x] += depth[p];
	for (auto &y : v[x])
	{
		if (y == p) continue;
		dfs(y, x);
		sons[x] += sons[y];
	}
}
void init()
{
    memset(fa,-1,sizeof(fa));
	dfs(1);
	for (int o = 0; o < 19; o++)
	{
		for (int i = 1; i <= n; i++)
		{
			int p = fa[i][o];
			if (p != -1) {
                fa[i][o + 1] = fa[p][o];
                mx[i][o + 1] = mx[i][o] * mx[p][o];
                rmx[i][o + 1] = rmx[p][o] * rmx[i][o];
            }
		}
	}
}
Node moveup(int x, int d)
{
    Node ret(false);
	for (int i = 0; i < 20; i++)
	{
		if (1 << i&d) {
            ret = ret * mx[x][i];
            x = fa[x][i];
        }
	}
	return ret;
}
Node rmoveup(int x, int d)
{
    Node ret(false);
	for (int i = 0; i < 20; i++)
	{
		if (1 << i&d) {
            ret = rmx[x][i] * ret;
            x = fa[x][i];
        }
	}
	return ret;
}
int getlca(int x, int y)
{
	if (depth[x] < depth[y]) swap(x, y);
    for(int i = 0; i < 20; ++i) {
        if((depth[x] - depth[y]) >> i & 1) x = fa[x][i];
    }
	if (x == y) return x;
	int lca = -1;
	for (int i = 19; i >= 0; i--)
	{
		if (fa[x][i] == fa[y][i]) lca = fa[x][i];
		else x = fa[x][i], y = fa[y][i];
	}
	return lca;
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
   
    weight[0][0] = 19 * 26;
    for(int i = 1; i < 64; ++i) weight[i][0] = weight[i - 1][0] * 19 % MOD;
    for(int i = 0; i < 64; ++i) {
        for(int j = 1; j < 64; ++j) {
            weight[i][j] = weight[i][j - 1] * 26 % MOD;
        }
    }
    while(scanf("%d%d", &n, &q) == 2) {
        for(int i = 1; i <= n; ++i) v[i].clear(); 
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            ::v[u].push_back(v);
            ::v[v].push_back(u);
        }
        
        scanf("%llu", &seed);
        input();

        auto get = [&](const Node& A) {
            LL ans = 0;   
            LL x = 1;
            for(int i = 0; i < 64; ++i) {
                x = x * 19 % MOD;
                LL y = 1;
                for(int j = 0; j < 64; ++j) {
                    y = y * 26 % MOD;
                    if(A.a[i] >> j & 1) add(ans, x * y % MOD);
                }
            }
            return ans;
        };
    
        init();
        while(q--) {
            int a, b; scanf("%d%d", &a, &b);
            int lca = getlca(a, b);
            Node m;
            if(a == lca) {
                int disr = depth[b] - depth[lca];
                m = rmoveup(b, disr);
                m = m * M[b];
            }
            else if(b == lca) {
                int disl = depth[a] - depth[lca];
                m = M[a];
                m = m * moveup(a, disl);
            }
            else{
                int disl = depth[a] - depth[lca] - 1;
                int disr = depth[b] - depth[lca];
                m = M[a];
                m = m * moveup(a, disl);
                m = m * rmoveup(b, disr);
                m = m * M[b];
            }
            LL ans = 0;
            for(int i = 0; i < 64; ++i) {
                for(int j = 0; j < 64; ++j) {
                    if(m.a[i] >> j & 1) add(ans, weight[i][j]);
                    // printf("%llu%c", m.a[i], " \n"[j+1==64]);
                }

            }
            printf("%llu\n", ans);
        }
    }
    return 0;
}
