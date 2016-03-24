//
//  Created by TaoSama on 2016-03-06
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int squre[][3] = {4, 9, 2, 3, 5, 7, 8, 1, 6};
int dir[][2] = {0, 0, 0, 1, 0, 2, 1, 2, 2, 2, 2, 1, 2, 0, 1, 0};

int a[3][3];

void rotate() {
    int t = squre[dir[0][0]][dir[0][1]];
    for(int i = 0; i + 1 < 8; ++i)
        squre[dir[i][0]][dir[i][1]] = squre[dir[i + 1][0]][dir[i + 1][1]];
    squre[dir[7][0]][dir[7][1]] = t;
}

void flip() {
    for(int i = 0; i < 3; ++i)
        swap(squre[i][0], squre[i][2]);
}

bool check() {
    for(int j = 0; j < 3; ++j) {
        for(int k = 0; k < 3; ++k) {
            if(a[j][k] == 0) continue;
            if(a[j][k] != squre[j][k]) return false;
        }
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            scanf("%d", a[i] + j);

    int cnt = 0, ans[3][3];
    for(int i = 0; i < 8; ++i) {
        rotate();
        if(check()) {
            memcpy(ans, squre, sizeof squre);
            ++cnt;
        }
        flip();
        if(check()) {
            memcpy(ans, squre, sizeof squre);
            ++cnt;
        }
        flip();
    }
    if(cnt > 1) puts("Too Many");
    else {
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j)
                printf("%d%c", ans[i][j], " \n"[j == 2]);
    }
    return 0;
}
