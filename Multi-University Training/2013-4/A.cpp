//
//  Created by TaoSama on 2016-03-24
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
char s[N];
int f[N][N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        memset(f, 0, sizeof f);
        scanf("%s", s + 1);
        n = strlen(s + 1);
        for(int i = 1; i <= n; ++i) f[i][i] = 1;
        for(int l = 2; l <= n; ++l) {
            for(int i = 1; i + l - 1 <= n; ++i) {
                int j = i + l - 1;
                f[i][j] += f[i][j - 1] + f[i + 1][j] - f[i + 1][j - 1];
                if(s[i] == s[j]) f[i][j] += f[i + 1][j - 1] + 1;
                f[i][j] %= 10007;
            }
        }
        int ans = (f[1][n] + 10007) % 10007;
        static int kase = 0;
        printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}
