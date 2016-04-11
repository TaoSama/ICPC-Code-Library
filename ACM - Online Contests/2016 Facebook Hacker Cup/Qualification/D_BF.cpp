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
int cost[N][N], f[N][N];
string s[N];

int main() {
    freopen("text_editor.txt", "r", stdin);
    freopen("text_editor_out.txt", "w", stdout);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &K);
        for(int i = 1; i <= n; ++i) cin >> s[i];
        sort(s + 1, s + 1 + n);

        for(int i = 1; i <= n; ++i) {
            for(int j = i + 1; j <= n; ++j) {
                int lcp = 0;
                for(int k = 0; k < s[i].size() && k < s[j].size(); ++k) {
                    if(s[i][k] != s[j][k]) break;
                    ++lcp;
                }
                cost[i][j] = cost[j][i] = s[i].size() + s[j].size() - 2 * lcp;
            }
        }

        memset(f, 0x3f, sizeof f);
        for(int i = 1; i <= n; ++i) f[1][i] = s[i].size();

        for(int i = 2; i <= K; ++i)
            for(int j = 1; j <= n; ++j)
                for(int k = 1; k < j; ++k)
                    f[i][j] = min(f[i][j], f[i - 1][k] + cost[k][j]);

        int ans = INF;
        for(int i = 1; i <= n; ++i) ans = min(ans, f[K][i] + (int)s[i].size());

        static int kase = 0;
        printf("Case #%d: %d\n", ++kase, ans + K);
    }
    return 0;
}
