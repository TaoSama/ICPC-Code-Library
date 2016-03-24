//
//  Created by TaoSama on 2015-11-23
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

int n, k;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &k) == 2) {
        if(n == 1) puts("1.000"); //1 0
        else if(n == 2) { //2 0~1
            if(k == 0) puts("0.000");
            else puts("1.000");
        } else if(n == 3) { //3 0~3
            if(k <= 1) puts("0.000");
            else puts("1.000");
        } else { //4 0~6
            if(k <= 2) puts("0.000");
            else if(k == 3) puts("0.800"); // (C(6,3)-4)/C(6,2) = 16/20
            else puts("1.000");
        }
    }
    return 0;
}
