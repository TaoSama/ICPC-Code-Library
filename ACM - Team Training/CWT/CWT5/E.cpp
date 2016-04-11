//
//  Created by TaoSama on 2016-01-26
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, q;

struct MyVec {
    int a[10], sz;
    MyVec() {sz = 0;}
    void push_back(const int& x) {if(sz < 10) a[sz++] = x;}
    int size() {return sz;}
    int& operator[](const int& i) {return a[i];}
};

vector<int> G[N];
MyVec c[N], have[17][N];
int dep[N], p[17][N];

MyVec operator+(MyVec A, MyVec B) {
    MyVec ret; int i, j, k;
    for(i = j = k = 0; i < A.size() && j < B.size() && ret.size() < 10;) {
        if(A[i] < B[j]) ret.push_back(A[i++]);
        else ret.push_back(B[j++]);
    }
    while(ret.size() < 10 && i < A.size()) ret.push_back(A[i++]);
    while(ret.size() < 10 && j < B.size()) ret.push_back(B[j++]);
    return ret;
}

void see(int i, int u) {
    printf("have[%d][%d] = ", i, u);
//    for(auto x : have[i][u]) printf("%d ", x); puts("");
}

void dfs(int u, int f) {
    p[0][u] = f;
    have[0][u] = c[f];
    for(int i = 1; (1 << i) <= dep[u]; ++i) {
        p[i][u] = p[i - 1][p[i - 1][u]];
        have[i][u] = have[i - 1][u] + have[i - 1][p[i - 1][u]];
    }
    for(int v : G[u]) {
        if(v == f) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if(dep[u] > dep[v]) swap(u, v);
    for(int i = 0; i < 17; ++i)
        if(dep[v] - dep[u] >> i & 1) v = p[i][v];
    if(u == v) return u;
    for(int i = 16; ~i; --i)
        if(p[i][v] != p[i][u])
            v = p[i][v], u = p[i][u];
    return p[0][u];
}

MyVec go(int u, int lca) {
    MyVec ret = c[u];
    for(int i = 0; i < 17; ++i)
        if(dep[u] - dep[lca] - 1 > 0 && dep[u] - dep[lca] - 1 >> i & 1)
            ret = ret + have[i][u], u = p[i][u];
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1; i < n; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for(int i = 1; i <= m; ++i) {
        int x; scanf("%d", &x);
        if(c[x].size() < 10) c[x].push_back(i);
    }
    dfs(1, 0);
    while(q--) {
        int u, v, a; scanf("%d%d%d", &u, &v, &a);
        int _lca = lca(u, v);
        MyVec ret;
        if(u != _lca && v != _lca) ret = c[_lca];
        ret = ret + go(u, _lca);
        if(v != u) ret = ret + go(v, _lca);
        int k = min(ret.size(), a);
        printf("%d", k);
        for(int i = 0; i < k; ++i) printf(" %d", ret[i]); puts("");
    }
    return 0;
}
