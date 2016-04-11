//
//  Created by TaoSama on 2015-09-24
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

int x[5], y[5];

bool isParallelogram() {
    if((y[0] - y[1]) * (x[2] - x[3]) != (y[2] - y[3]) * (x[0] - x[1]))
        return false;
    if((y[0] - y[3]) * (x[1] - x[2]) != (y[1] - y[2]) * (x[0] - x[3]))
        return false;
    return true;
}

bool isRect() {
    for(int i = 0; i < 3; ++i) {
        if((x[i] - x[(i + 1) % 4]) * (x[(i + 1) % 4] - x[(i + 2) % 4])
                != -((y[i] - y[(i + 1) % 4]) * (y[(i + 1) % 4] - y[(i + 2) % 4])))
            return false;
    }
    return true;
}

bool isDiamond() {
    return (x[0] - x[2]) * (x[1] - x[3]) == -((y[0] - y[2]) * (y[1] - y[3]));
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        for(int i = 0; i < 4; ++i) scanf("%d%d", x + i, y + i);
        printf("Case #%d: ", ++kase);
        if(isParallelogram()) {
            if(isRect() && isDiamond()) puts("Square");
            else if(isRect()) puts("Rectangle");
            else if(isDiamond()) puts("Diamond");
            else puts("Parallelogram");
        } else puts("Others");
    }
    return 0;
}
