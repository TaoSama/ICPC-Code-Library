//
//  Created by TaoSama on 2016-02-22
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
const int N = 3e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
char s[N][N];
int b[N << 1][N];
int l[N][N], r[N][N], ld[N][N];
vector<pair<int, int> > leftPoints[N];

void add(int *b, int i, int v) {
    for(; i <= m; i += i & -i) b[i] += v;
}

int sum(int *b, int i) {
    int ret = 0;
    for(; i; i -= i & -i) ret += b[i];
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j)
            l[i][j] = s[i][j] == 'z' ? l[i][j - 1] + 1 : 0;
        for(int j = m; j; --j)
            r[i][j] = s[i][j] == 'z' ? r[i][j + 1] + 1 : 0;
    }
    for(int i = n; i; --i)
        for(int j = 1; j <= m; ++j)
            ld[i][j] = s[i][j] == 'z' ? ld[i + 1][j - 1] + 1 : 0;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            leftPoints[j + r[i][j] - 1].push_back({i, j});

    long long ans = 0;
    for(int j = m; j; --j) {
        for(auto &p : leftPoints[j]) {
            int x = p.first, y = p.second;
            add(b[x + y], y, 1);
        }
        for(int i = 1; i <= n; ++i) {
            int z = min(l[i][j], ld[i][j]);
            if(!z) continue;
            ans += sum(b[i + j], j) - sum(b[i + j], j - z);
        }
    }
    printf("%I64d\n", ans);
    return 0;
}
