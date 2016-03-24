//
//  Created by TaoSama on 2015-12-10
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

int a, b, c, x, y, z;
int p, q;

void gao(int x, int a) {
    if(x > a) p += x - a >> 1;
    else q += a - x;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &a, &b, &c) == 3) {
        scanf("%d%d%d", &x, &y, &z);
        p = q = 0;
        gao(a, x); gao(b, y); gao(c, z);
        if(p - q >= 0) puts("Yes");
        else puts("No");
    }
    return 0;
}
