//
//  Created by TaoSama on 2017-03-31
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
const int N = 1e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, k;
int par[N], son[N];
int d[N][N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> k;
    vector<vector<int>> lv;
    for(int i = 1; i <= m; ++i) {
        int x; cin >> x;
        lv.push_back(vector<int>(x));
    }
    for(auto& v : lv)
        for(auto& x : v) cin >> x;

    vector<int> leaf(k), isLeaf(n + 1, 0), vis(n + 1, 0);
    for(auto& x : leaf) cin >> x, isLeaf[x] = 1;

    /*------------------------------------------------------------*/

    for(int i = 0; i < k; ++i)
        for(int j = 0; j < k; ++j)
            cin >> d[leaf[i]][leaf[j]];

    reverse(lv.begin(), lv.end());
    for(int i = 0; i + 1 < lv.size(); ++i) {
        auto& cur = lv[i], &nxt = lv[i + 1];
        int j = -1;
        for(int curx : cur) {
            if(vis[curx]) continue;
            for(++j; j < nxt.size() && isLeaf[nxt[j]]; ++j);
            if(j >= nxt.size()) continue;
            int fa = nxt[j];
            vector<int> subtree(1, curx);
            for(int same : cur)
                if(d[curx][same] == 2) subtree.push_back(same);
            for(int one : subtree)
                par[one] = fa, son[fa] = one, vis[one] = 1;
        }
        vector<int> toUpdate = nxt;
        for(int s = 1; s <= n; ++s)
            if(isLeaf[s]) toUpdate.push_back(s);
        for(int nxtv : toUpdate) {
            for(int same : toUpdate) {
                if(!isLeaf[nxtv] && !isLeaf[same])
                    d[nxtv][same] = d[son[nxtv]][son[same]] - 2;
                else if(isLeaf[nxtv] && !isLeaf[same]) {
                    d[nxtv][same] = d[nxtv][son[same]] - 1;
                } else if(!isLeaf[nxtv] && isLeaf[same])
                    d[nxtv][same] = d[son[nxtv]][same] - 1;
            }
        }
        for(int nxtv : nxt) isLeaf[nxtv] = 1;
    }
    for(int i = 1; i <= n; ++i)
        cout << par[i] << " \n"[i == n];

    return 0;
}
