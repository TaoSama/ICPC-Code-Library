//
//  Created by TaoSama on 2016-05-06
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
char c;

void print(int l, int x) {
    for(int i = 1; i <= (l - x) / 2; ++i) putchar(' ');
    for(int i = 1; i <= x; ++i) putchar(c);
//    for(int i = 1; i <= (l - x) / 2; ++i) putchar(' ');
    puts("");
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d %c", &n, &c) == 2) {
        int l = 1, r = 1000;
        while(l <= r) {
            int m = l + r >> 1;
            if(2 * m * m - 1 <= n) l = m + 1;
            else r = m - 1;
        }
        --l;
        int lft = n - (2 * l * l - 1);

        l = 2 * l - 1;
        for(int i = l; i >= 1; i -= 2) print(l, i);
        for(int i = 3; i <= l; i += 2) print(l, i);
        printf("%d\n", lft);
    }
    return 0;
}

/*
*****
 ***
  *
 ***
*****
2
*/
