//
//  Created by TaoSama on 2016-03-12
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
const int N = 2e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, f[N][26][5];

void add(int &x, int y) {
    if((x += y) >= MOD) x -= MOD;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);


    for(int i = 0; i < 26; ++i) f[1][i][1] = 1;
    for(int i = 1; i < 2000; ++i) {
        for(int j = 0; j < 26; ++j) {
            for(int k = 1; k <= 3; ++k) {
                for(int x = 0; x < 26; ++x) {
                    if(k == 3 && j == x) continue;
                    if(j == x) add(f[i + 1][x][k + 1], f[i][j][k]);
                    else  add(f[i + 1][x][1], f[i][j][k]);
                }
            }
        }
    }
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        int ans = 0;
        for(int i = 0; i < 26; ++i)
            for(int j = 1; j <= 3; ++j)
                add(ans, f[n][i][j]);
        printf("%d\n", ans);
    }
    return 0;
}
