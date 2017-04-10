//
//  Created by TaoSama on 2017-04-04
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
char s[N];
int f[N][N], g[N][N];

void add(int& x, int y) {
    if((x += y) >= MOD) x -= MOD;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%s", s + 1);
    n = strlen(s + 1);

    queue<pair<int, int>> q;
    memset(f, -1, sizeof f);
    f[0][0] = 0, g[0][0] = 1;
    q.push({0, 0});
    while(q.size()) {
        int i, j; tie(i, j) = q.front(); q.pop();
        for(int k = -1; k <= 1; k += 2) {
            char c = k == 1 ? '(' : ')';
            int ni = min(n, i + (s[i + 1] == c));
            int nj = j + k;
            if(nj >= 0 && nj <= n) {
                if(f[ni][nj] == -1) {
                    f[ni][nj] = f[i][j] + 1;
                    g[ni][nj] = g[i][j];
                    q.push({ni, nj});
                } else if(f[ni][nj] == f[i][j] + 1) {
                    add(g[ni][nj], g[i][j]);
                }
            }
        }
    }
    printf("%d %d\n", f[n][0] - n, g[n][0]);

    return 0;
}
