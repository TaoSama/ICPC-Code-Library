//
//  Created by TaoSama on 2015-07-17
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

int r, x, y;

void setbit(int& x, int p) {
    x |= 1 << p;
}

void clrbit(int& x, int p) {
    x &= ~(1 << p);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%x,%d,%d", &r, &x, &y) == 3) {
        clrbit(r, x);
        setbit(r, y);
        setbit(r, y - 1);
        clrbit(r, y - 2);
        printf("%x\n", r);
    }
    return 0;
}
