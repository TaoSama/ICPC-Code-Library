//
//  Created by TaoSama on 2016-08-07
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
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 5e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k;
char s[N];
int f[N][26], dir[N][26];

inline bool getMin(int& x, int y) {
    if(x > y) {
        x = y;
        return true;
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%s", &n, &k, s + 1) == 3) {
        memset(f, 0x3f, sizeof f);
        for(int i = 0; i < 26; ++i) {f[0][i] = 0; dir[0][i] = -1;}
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < k; ++j) {
                for(int p = 0; p < k; ++p) {
                    if(j == p) continue;
                    if(getMin(f[i][j], f[i - 1][p] + (s[i] - 'A' != j)))
                        dir[i][j] = p;
                }
            }
        }

        int ans = INF;
        int u = -1;
        for(int i = 0; i < k; ++i) if(getMin(ans, f[n][i])) u = i;
        string str;
        while(n) {
            str += char(u + 'A');
            u = dir[n][u];
            --n;
        }
        reverse(str.begin(), str.end());
        printf("%d\n%s\n", ans, str.c_str());
    }

    return 0;
}
