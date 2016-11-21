//
//  Created by TaoSama on 2016-11-19
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

//n条直线分割平面数: 1+(n+1)*n/2
//n条折线分割平面数: 2*n^2-n+1
//n条闭合曲线分割平面数: fn(n)=n^2-n+2
//n个平面分割空间数: (n^3+5n)/6+1
//http://www.cnblogs.com/ACShiryu/archive/2011/09/01/DivideFormula.html

int f1(int n) {
    return 2 * n * n - n + 1;
}
int f2(int n) {
    return n * n - n + 2;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        int n, m; scanf("%d%d", &n, &m);
        printf("%d %d\n", f1(n), f2(m));
    }

    return 0;
}
