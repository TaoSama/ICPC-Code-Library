//
//  Created by TaoSama on 2016-08-20
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
#include <bitset>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

const int C = 1e3 + 10;
typedef bitset<C> Sta;

Sta b[N + C];
int root[N][C], ans[N];
int to[N];

int n, m, q;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1; i <= n; ++i) root[0][i] = i;
    Sta all;
    for(int i = 1; i <= m; ++i) all[i] = 1;

    int sz = n;
    int timStp = 0;
    for(int i = 1; i <= q; ++i) {
        int op; scanf("%d", &op);
        if(op == 1) {
            int x, y; scanf("%d%d", &x, &y);
            ++timStp;
            for(int j = 1; j <= n; ++j) root[timStp][j] = root[timStp - 1][j];
            ans[i] = ans[i - 1];
            Sta& before = b[root[timStp][x]];
            if(before[y] == 0) {
                Sta& newOne = b[++sz];
                newOne = before;
                root[timStp][x] = sz;
                newOne[y] = 1;
                ++ans[i];
            }
        } else if(op == 2) {
            int x, y; scanf("%d%d", &x, &y);
            ++timStp;
            for(int j = 1; j <= n; ++j) root[timStp][j] = root[timStp - 1][j];
            ans[i] = ans[i - 1];
            Sta& before = b[root[timStp][x]];
            if(before[y] == 1) {
                Sta& newOne = b[++sz];
                newOne = before;
                root[timStp][x] = sz;
                newOne[y] = 0;
                --ans[i];
            }
        } else if(op == 3) {
            int x; scanf("%d", &x);
            ++timStp;
            for(int j = 1; j <= n; ++j) root[timStp][j] = root[timStp - 1][j];
            ans[i] = ans[i - 1];
            Sta& before = b[root[timStp][x]];
            Sta& newOne = b[++sz];
            newOne = before;
            root[timStp][x] = sz;
            ans[i] -= newOne.count();
            newOne.flip();
            newOne &= all;
            ans[i] += newOne.count();
        } else {
            int x; scanf("%d", &x);
            ++timStp;
            for(int j = 1; j <= n; ++j) root[timStp][j] = root[x][j];
            ans[i] = ans[x];
        }
    }
    for(int i = 1; i <= q; ++i) printf("%d\n", ans[i]);
    return 0;
}
