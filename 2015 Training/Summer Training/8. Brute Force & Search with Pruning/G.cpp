//
//  Created by TaoSama on 2015-07-29
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
const int N = 6, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct Tree {
    double l, r; //dis from current root to the leftmost/rightmost point
    Tree(): l(0), r(0) {}
};

int n;
bool vis[1 << N]; //mark the subset
double R, w[N], sum[1 << N];
vector<Tree> tree[1 << N]; //record current tree's subtree's info

void dfs(int sub) {
    if(vis[sub]) return;
    vis[sub] = true;

    bool haveSon = false;
    //enumerate the subset of "sub" (current tree)
    //lef-> left subtree rig-> right subtree
    for(int lef = (sub - 1) & sub; lef; lef = (lef - 1) & sub) {
        haveSon = true;
        int rig = lef ^ sub; //get the sub - lef
        double d1 = sum[rig] / sum[sub];
        double d2 = sum[lef] / sum[sub];

        dfs(lef); dfs(rig);

        //backtrack to use left and right subtrees to update the current tree
        for(auto &i : tree[lef]) {
            for(auto &j : tree[rig]) {
                Tree t;
                t.l = max(i.l + d1, j.l - d2);
                t.r = max(j.r + d2, i.r - d1);
                if(t.l + t.r < R) tree[sub].push_back(t);
            }
        }
    }
    if(!haveSon) tree[sub].push_back(Tree());
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%lf%d", &R, &n);
        for(int i = 0; i < n; ++i) scanf("%lf", w + i);
        for(int i = 0; i < 1 << n; ++i) {
            sum[i] = 0;
            tree[i].clear();
            for(int j = 0; j < n; ++j)
                if(i >> j & 1) sum[i] += w[j];
        }

        int root = (1 << n) - 1;
        memset(vis, false, sizeof vis);
        dfs(root);

        double ans = -1;
        for(auto &subtree : tree[root]) ans = max(ans, subtree.l + subtree.r);
        printf("%.16f\n", ans);
    }
    return 0;
}
