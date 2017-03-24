//
//  Created by TaoSama on 2017-03-23
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
vector<int> g[2];
int d[2][N], deg[2][N];

int dfs(int k, int i, int v) {
    int& ret = d[k][i];
    if(~ret) return ret;

    ret = v;
    if(v == 0) {
        for(int x : g[k ^ 1]) {
            int j = (i + n - x) % n;
            if(j == 0) continue;
            dfs(k ^ 1, j, 1);
        }
    } else {
        for(int x : g[k ^ 1]) {
            int j = (i + n - x) % n;
            if(j == 0) continue;
            if(--deg[k ^ 1][j] == 0) dfs(k ^ 1, j, 0);
        }
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        for(int k = 0; k < 2; ++k) {
            int cnt; cin >> cnt;
            g[k].clear();
            g[k].reserve(cnt);
            while(cnt--) {
                int x; cin >> x;
                g[k].push_back(x);
            }
            for(int i = 1; i < n; ++i) deg[k][i] = g[k].size();
        }

        memset(d, -1, sizeof d);
        dfs(0, 0, 0);
        dfs(1, 0, 0);

        string s[3] = {"Loop", "Lose", "Win"};
        for(int k = 0; k < 2; ++k)
            for(int i = 1; i < n; ++i)
                cout << s[d[k][i] + 1] << (i + 1 == n ? '\n' : ' ');
    }

    return 0;
}
