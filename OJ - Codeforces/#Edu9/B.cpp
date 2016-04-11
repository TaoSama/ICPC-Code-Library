//
//  Created by TaoSama on 2016-03-01
//  Copyright (c) 2016 TaoSama. All rights reserved.
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
const int N = 5e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, p[N];
char s[N];
long long pre[2][N], suf[2][N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", p + i);
        scanf("%s", s + 1);
        for(int i = 0; i < 2; ++i) pre[i][0] = suf[i][n + 1] = 0;
        for(int i = 1; i <= n; ++i) {
            pre[0][i] = pre[0][i - 1];
            pre[1][i] = pre[1][i - 1];
            if(s[i] == 'A') pre[1][i] += p[i];
            else pre[0][i] += p[i];
        }
        for(int i = n; i; --i) {
            suf[0][i] = suf[0][i + 1];
            suf[1][i] = suf[1][i + 1];
            if(s[i] == 'A') suf[1][i] += p[i];
            else suf[0][i] += p[i];
        }
        long long ans = 0;
        for(int i = 0; i <= n; ++i) {
            ans = max(ans, pre[0][i] + suf[1][i + 1]);
            ans = max(ans, pre[1][i] + suf[0][i + 1]);
            ans = max(ans, pre[0][i] + suf[0][i + 1]);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
