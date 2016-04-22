//
//  Created by TaoSama on 2015-11-03
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
const int N = 4e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, l, r, p[N];
char c[2], a[N], s[N];

/*
 1  2  3  4  5  6  7  8  9
 #  a  #  z  #  a  #  c  #
 1  2  1  4  1  2  1  2  1

 1  2  3  4  5  6  7  8  9
 #  a  #  b  #  c  #  d  #
 1  2  1  2  1  2  1  2  1

 1  2  3  4  5  6  7  8  9
 #  a  #  a  #  b  #  b  #
 1  2  3  2  1  2  3  2  1
*/

void manacher() {
    s[0] = '@'; s[1] = '#'; n = 2;
    for(int i = 0; a[i]; ++i)
        s[n++] = a[i], s[n++] = '#';
    s[n] = 0;

    int mx = 0, id, ret = 0;
    for(int i = 1; i < n; ++i) {
        if(mx > i) p[i] = min(mx - i, p[2 * id - i]);
        else p[i] = 1;
        while(s[i - p[i]] == s[i + p[i]]) ++p[i];
        if(mx < i + p[i]) mx = i + p[i], id = i;
        ret = max(ret, p[i]);
    }

    l = r = -1;
    if(ret - 1 < 2) return;
    for(int i = 1; i < n; ++i) {
        if(p[i] == ret) {
            l = i - ret + 2 >> 1;
            r = i + ret - 2 >> 1;
            break;
        }
    }
//  for(int i = 1; i < n; ++i) printf("%2d ", i); puts("");
//  for(int i = 1; i < n; ++i) printf("%2c ", s[i]); puts("");
//  for(int i = 1; i < n; ++i) printf("%2d ", p[i]); puts(""); puts("");
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s%s", c, a) == 2) {
        int off = ('a' - *c + 26) % 26;
        for(int i = 0; a[i]; ++i) a[i] = (a[i] - 'a' + off) % 26 + 'a';
        manacher();
        if(~l) {
            printf("%d %d\n", l - 1, r - 1);
            for(int i = l - 1; i <= r - 1; ++i) putchar(a[i]);
            puts("");
        } else puts("No solution!");
    }
    return 0;
}
