//
//  Created by TaoSama on 2016-01-12
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
const int N = 3e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, K;
int lcp[N][N], f[N][N];
string s[N];

int getCost(int x, int y) {
    return s[x].size() + s[y].size() - 2 * lcp[x][y];
}

int main() {
    freopen("text_editor.txt", "r", stdin);
    freopen("text_editor_out.txt", "w", stdout);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &K);
        for(int i = 1; i <= n; ++i) cin >> s[i];
        sort(s + 1, s + 1 + n);

        for(int i = 2; i <= n; ++i) {
            int p = 0;
            for(int j = 0; j < s[i - 1].size() && j < s[i].size(); ++j) {
                if(s[i - 1][j] != s[i][j]) break;
                ++p;
            }
            lcp[i - 1][i] = p;
        }

        //lcp(i, j) = min{lcp(i, i+1), lcp(i+1, i+2), ... , lcp(j-1, j)}
        for(int i = 1; i <= n; ++i)
            for(int j = i + 2; j <= n; ++j)
                lcp[i][j] = min(lcp[i][j - 1], lcp[j - 1][j]);

        memset(f, 0x3f, sizeof f);
        for(int i = 1; i <= n; ++i) f[1][i] = s[i].size();

        for(int i = 2; i <= K; ++i)
            for(int j = 1; j <= n; ++j)
                for(int k = 1; k < j; ++k)
                    f[i][j] = min(f[i][j], f[i - 1][k] + getCost(k, j));

        int ans = INF;
        for(int i = 1; i <= n; ++i) ans = min(ans, f[K][i] + (int)s[i].size());

        static int kase = 0;
        printf("Case #%d: %d\n", ++kase, ans + K);
    }
    return 0;
}
