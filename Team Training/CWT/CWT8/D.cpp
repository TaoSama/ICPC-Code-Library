//
//  Created by TaoSama on 2016-02-02
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int x[4], y[4];
int r, c;
char s[305][305];

#define rep(i, a, b) for(int i = a; i <= b; ++i)

void change(int a, int b, int c) {
    if(a) swap(x[1], y[1]);
    if(b) swap(x[2], y[2]);
    if(c) swap(x[3], y[3]);
}

bool check() {
    r = 1, c = 0;
    while(s[r][c + 1]) ++c;
    while(s[r + 1][1]) {
        ++r;
        int cur = 0;
        while(s[r][cur + 1]) ++cur;
        if(cur != c) return false;
    }
    return r == c;
}

bool construct1(int a, int b, int c) {
    change(a, b, c);
    memset(s, 0, sizeof s);
    for(int i = 1; i <= x[1]; ++i)
        for(int j = 1, k = 1; k <= y[1]; ++j, ++k)
            s[i][j] = 'A';
    for(int i = 1; i <= x[1]; ++i)
        for(int j = y[1] + 1, k = 1; k <= y[2]; ++j, ++k)
            s[i][j] = 'B';
    for(int i = 1; i <= x[1]; ++i)
        for(int j = y[1] + y[2] + 1, k = 1; k <= y[3]; ++j, ++k)
            s[i][j] = 'C';
    change(a, b, c);
    return check();
}

bool construct2(int a, int b, int c) {
    if(!(a != b && b != c && a != c)) return false;
//  printf("%d %d %d\n", a, b, c);
    rep(l, 0, 1) rep(m, 0, 1) rep(n, 0, 1) {
        change(l, m, n);
        if(y[a] != y[b]) {change(l, m, n); continue;}
//        if(a == 1 && b == 3 && c == 2) {
//            for(int i = 1; i <= 3; ++i) printf("%d %d\n", x[i], y[i]);
//        }
        memset(s, 0, sizeof s);
        for(int i = 1; i <= x[a]; ++i)
            for(int j = 1; j <= y[a]; ++j)
                s[i][j] = 'A' + a - 1;
        for(int i = x[a] + 1, k = 1; k <= x[b]; ++i, ++k)
            for(int j = 1; j <= y[b]; ++j)
                s[i][j] = 'A' + b - 1;
        for(int i = 1; i <= x[c]; ++i)
            for(int j = y[a] + 1, k = 1; k <= y[c]; ++j, ++k)
                s[i][j] = 'A' + c - 1;
//        for(int i = 1; i <= x[a] + x[b]; ++i) puts(s[i] + 1);
        change(l, m, n);
        if(check()) return true;
    }
    return false;
}

void print() {
    printf("%d\n", r);
    for(int i = 1; i <= r; ++i) {
        for(int j = 1; j <= c; ++j)
            putchar(s[i][j]);
        puts("");
    }
}

void solve() {
    rep(i, 0, 1) rep(j, 0, 1) rep(k, 0, 1)
    if(construct1(i, j, k)) {print(); return;}
    rep(i, 1, 3) rep(j, 1, 3) rep(k, 1, 3)
    if(construct2(i, j, k)) {print(); return;}
    puts("-1");
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    for(int i = 1; i <= 3; ++i) scanf("%d%d", x + i, y + i);
    solve();
    return 0;
}
