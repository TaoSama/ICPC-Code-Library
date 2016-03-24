//
//  Created by TaoSama on 2016-01-27
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
const int N = 5e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
char s[N];
int lcp[N][N], f[N][N], prefix[N][N];

void add(int &x, int y) {
    if((x += y) >= MOD) x -= MOD;
}

//prefix[i][j] = sum(f[1...i][j])
void update(int i, int j) {
    add(prefix[i][j], prefix[i - 1][j] + f[i][j]);
}

int sum(int k, int i, int j) {
    int ret = prefix[j][k] - prefix[max(i - 1, 0)][k];
    if(ret < 0) ret += MOD;
    return ret;
}

bool smaller(int i, int j, int len) {
    if(lcp[i][j] >= len) return false;
    return s[i + lcp[i][j]] < s[j + lcp[i][j]];
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%s", &n, s + 1) == 2) {
        memset(lcp, 0, sizeof lcp);
        for(int i = n; i; --i)
            for(int j = n; j; --j)
                if(s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;

        memset(prefix, 0, sizeof prefix);
        for(int i = 1; i <= n; ++i) f[1][i] = 1, update(1, i);
        for(int i = 2; i <= n; ++i) {
            for(int j = i; j <= n; ++j) {
                if(s[i] == '0') f[i][j] = 0;
                else {
                    int len = j - i + 1;
                    int b = i - 1, a = b - len + 1;
                    f[i][j] = sum(b, a + 1, b);
                    if(a > 0 && smaller(a, i, len)) add(f[i][j], sum(b, a, a));
                }
                update(i, j);
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i) add(ans, f[i][n]);
        printf("%d\n", ans);
    }
    return 0;
}
