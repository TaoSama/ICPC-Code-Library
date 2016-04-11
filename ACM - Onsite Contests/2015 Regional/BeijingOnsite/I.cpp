//
//  Created by TaoSama on 2015-11-15
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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

int n;
vector<pair<int, int> > G[505];

void printOdd(int x, int y, int l, int delta) {
//  pr(x); pr(y); pr(l); prln(delta);
    if(l == 1) {
        puts("1 1");
        return;
    }
    for(; x <= l; ++x) {
        if(x == l) {
            printf(" %d %d", x, y);
        } else if(x == 1) {
            printf("%d %d", x, y);
            printf(" %d %d", x, y += delta);
        } else {
            printf(" %d %d", x, y);
            printf(" %d %d", x, y += delta);
        }
        delta = -delta;
    }
    puts("");
}

void printEven(int x, int y, int l) {
    for(int i = 0; i < l; ++i) {
        if(i == 0) printf("%d %d", x, y + i);
        else printf(" %d %d", x, y + i);
    }
    puts("");
}

void printN(int x, int y, int l) {
    for(int i = 0; i < l; ++i) {
        if(i == 0) printf("%d %d", x + i, y);
        else printf(" %d %d", x + i, y);
    }
    x += l - 1;
    for(int i = 0; i < l; ++i) {
        if(i == 0) printf(" %d %d", x - i, y + 1);
        else printf(" %d %d", x - i, y + 1);
    }
    puts("");
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        if(n & 1) {
            printf("%d %d\n", n + 1 >> 1, n);
            int j = 1;
            for(int i = 1; i <= n; ++i) {
                if(i & 1) {
                    if(j & 1) printOdd(1, 2 * j - 1, i + 1 >> 1, -1);
                    else printOdd(1, 2 * (j - 1), i + 1 >> 1, 1);
                    ++j;
                } else printEven(j, 1, i);
            }
        } else {
            printf("%d %d\n", n + 1 >> 1, n + 1);
            int j = 1;
            for(int i = 1; i < n; ++i) {
                if(i & 1) {
                    if(j & 1) printOdd(1, 2 * j - 1, i + 1 >> 1, -1);
                    else printOdd(1, 2 * (j - 1), i + 1 >> 1, 1);
                    ++j;
                } else printEven(j, 1, i);
            }
            printN(1, n, n + 1 >> 1);
        }
        puts("");
    }
    return 0;
}
