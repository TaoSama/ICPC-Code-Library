//
//  Created by TaoSama on 2017-04-09
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
int x[10];
char s[10][10];

const char original[10][10] = {
    "",
    "1001111",
    "0010010",
    "0000110",
    "1001100",
    "0100100",
    "0100000",
    "0001111",
    "0000000",
    "0000100"
};
int cnt[10];

bool vis[7];
int r[7];

bool dfs(int p, int fst) {
    if(p == 7) return true;
    for(int i = 0; i < 7; ++i) {
        if(vis[i]) continue;
        bool ok = true;
        for(int j = 1; j <= n && ok; ++j)
            ok &= original[x[j]][i] == s[j][p];
        if(!ok) continue;
        vis[i] = true;
        if(dfs(p + 1, fst)) return true;
        vis[i] = false;

    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    for(int i = 1; i <= 9; ++i) {
        for(int j = 0; j < 7; ++j)
            cnt[i] += original[i][j] == '1';
    }

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);

        bool ok = true;
        for(int i = 1; i <= n; ++i) {
            scanf("%d%s", x + i, s[i]);
            int one = 0;
            for(int j = 0; j < 7; ++j) one += s[i][j] == '1';
            ok &= cnt[x[i]] == one;
        }

        memset(vis, 0, sizeof vis);
        puts(ok && dfs(0, x[1]) ? "YES" : "NO");
    }

    return 0;
}
