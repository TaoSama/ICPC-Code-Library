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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q;
vector<int> G[N];

// Euler Sequence & RMQ(ST)
int getMin(int x, int y) {
    return dep[x] < dep[y] ? x : y;
}

struct SparseTable {
    int dp[20][N << 1];
    void init(int n) {
        for(int i = 1; i <= n; ++i) dp[0][i] = i;
        for(int i = 1; (1 << i) <= n; ++i)
            for(int j = 1; j + (1 << i) - 1 <= n; ++j)
                dp[i][j] = getMin(dp[i - 1][j], dp[i - 1][j + (1 << i - 1)]);
    }
    int RMQ(int l, int r) {
        int k = 31 - __builtin_clz(r - l + 1);
        return getMin(dp[k][l], dp[k][r - (1 << k) + 1]);
    }
} st;

vector<int> G[N];
int vs[N << 1], dep[N << 1], first[N], dfsNum;

const int LOG = 18;
int p[LOG][N];

void dfs(int u, int f, int d) {
    vs[++dfsNum] = u;
    dep[dfsNum] = d;
    first[u] = dfsNum;
    p[0][u] = f;
    for(int i = 1; i < LOG; ++i) p[i][u] = p[i - 1][p[i - 1][u]];
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(v == f) continue;
        dfs(v, u, d + 1);
        vs[++dfsNum] = u;
        dep[dfsNum] = d;
    }
}

int getDis(int u, int v){
	return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

void init() {
    dfsNum = 0;
    dfs(1, 0, 0);
    st.init(2 * n - 1);
}

struct Node{
	int u, v, dis;
	Node() {}
	Node(int u, int v) : u(u), v(v), dis(getDis(u, v)){}
	bool operator<(const Node& r) const{
		return dis < r.dis;
	}
};

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);



    return 0;
}
