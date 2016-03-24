//
//  Created by TaoSama on 2015-07-29
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

/*
          A     B
         00    01
         02    03
H  04 05 06 07 08 09 10  C
         11    12
G  13 14 15 16 17 18 19  D
         20    21
         22    23
          F     E
*/

int a[35], maxd;
char ans[1005];

const int shift[][7] = {
    {0, 2, 6, 11, 15, 20, 22}, // A
    {1, 3, 8, 12, 17, 21, 23}, // B
    {10, 9, 8, 7, 6, 5, 4},     // C
    {19, 18, 17, 16, 15, 14, 13}, // D
    {23, 21, 17, 12, 8, 3, 1},  //E
    {22, 20, 15, 11, 6, 2, 0},  //F
    {13, 14, 15, 16, 17, 18, 19}, //G
    {4, 5, 6, 7, 8, 9, 10}    //H
};
const int rev[] = {5, 4, 7, 6, 1, 0, 3, 2}; //reverse line of original line
const int center[] = {6, 7, 8, 11, 12, 15, 16, 17};

bool isFinal() {
    for(int i = 0; i < 8; ++i)
        if(a[center[i]] != a[center[0]]) return false;
    return true;
}

int diff(int x) {
    int ret = 0;
    for(int i = 0; i < 8; ++i)
        if(a[center[i]] != x) ++ret;
    return ret;
}

int h() {
    return min(diff(1), min(diff(2), diff(3)));
}

void go(int dir) {
    int tmp = a[shift[dir][0]];
    for(int i = 0; i < 6; ++i) a[shift[dir][i]] = a[shift[dir][i + 1]];
    a[shift[dir][6]] = tmp;
}

bool dfs(int dep) {
    if(dep == maxd) {
        if(isFinal()) {
            ans[dep] = 0;
            return true;
        }
        return false;
    }
    if(dep + h() > maxd) return false;
    for(int i = 0; i < 8; ++i) {
        go(i);
        ans[dep] = i + 'A';
        if(dfs(dep + 1)) return true;
        go(rev[i]);
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", a) == 1 && a[0]) {
        for(int i = 1; i < 24; ++i) scanf("%d", a + i);
        if(isFinal()) puts("No moves needed");
        else {
            for(maxd = 1; ; maxd++)
                if(dfs(0)) break;
            puts(ans);
        }
        printf("%d\n", a[center[0]]);
    }
    return 0;
}
