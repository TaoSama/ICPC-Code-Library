//
//  Created by TaoSama on 2016-04-22
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

typedef long long LL;

int n, m, q;
int a[N][N];
int r[N], c[N];
int dr[N], dc[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &m, &q);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                scanf("%d", a[i] + j);
        for(int i = 1; i <= n; ++i) {
            r[i] = i;
            dr[i] = 0;
        }
        for(int i = 1; i <= m; ++i) {
            c[i] = i;
            dc[i] = 0;
        }
        while(q--) {
            int op, x, y; scanf("%d%d%d", &op, &x, &y);
            if(op == 1) swap(r[x], r[y]);
            else if(op == 2) swap(c[x], c[y]);
            else if(op == 3) dr[r[x]] += y;
            else dc[c[x]] += y;
        }
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                printf("%d%c", a[r[i]][c[j]] + dr[r[i]] + dc[c[j]], " \n"[j == m]);
    }
    return 0;
}
