//
//  Created by TaoSama on 2016-08-01
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

bool inMaze(int x, int y) {
    return x >= 1 && y >= 1;
}

int king[N][N];
int getKing(int x, int y) {
    if(x == 1 && y == 1) return 0;
    int& ret = king[x][y];
    if(~ret) return ret;
    bool mark[10]; memset(mark, 0, sizeof mark);
    if(inMaze(x - 1, y)) mark[getKing(x - 1, y)] = 1;
    if(inMaze(x, y - 1)) mark[getKing(x, y - 1)] = 1;
    if(inMaze(x - 1, y - 1)) mark[getKing(x - 1, y - 1)] = 1;
    for(int i = 0; ; ++i) if(!mark[i]) return ret = i;
    return -1;
}

int knight[N][N];
int getKnight(int x, int y) {
    if(x == 1 && y == 1) return 0;
    int& ret = knight[x][y];
    if(~ret) return ret;

    int a = -1, b = -1;
    if(inMaze(x - 1, y - 2)) a = getKnight(x - 1, y - 2);
    if(inMaze(x - 2, y - 1)) b = getKnight(x - 2, y - 1);
    if(a == 0 || b == 0) return ret = 1; //win
    else if(a == -1 && b == -1 || a == 2 || b == 2) return ret = 2; //draw
    else return ret = 0; //lose
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);


    memset(king, -1, sizeof king);
    memset(knight, -1, sizeof knight);
    for(int i = 2; i <= 1000; ++i) {
        for(int j = 2; j <= 1000; ++j) {
            getKing(i, j);
            getKnight(i, j);
        }
    }

    int t; scanf("%d", &t);
    while(t--) {
        int type, n, m; scanf("%d%d%d", &type, &n, &m);
        if(type == 1) puts(king[n][m] ? "B" : "G");
        else if(type == 2) puts(n - 1 ^ m - 1 ? "B" : "G");
        else if(type == 3) {
            if(knight[n][m] == 1) puts("B");
            else if(knight[n][m] == 0) puts("G");
            else puts("D");
        } else {
            --n; --m;
            if(n < m) swap(n, m);
            int k = n - m;
            int t = k * (1 + sqrt(5)) / 2;
            puts(m == t ? "G" : "B");
        }
    }

    return 0;
}
