//
//  Created by TaoSama on 2015-08-15
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

double f[N];

//P = C(2n-2, n-1) * 1/2^(2n-2)
void gao() {
    f[1] = 1; //get different burger
    for(int i = 1; i < 5e4; ++i)
        f[i + 1] = f[i] * (2 * i - 1) / (2 * i);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    gao();
    while(t--) {
        int n; scanf("%d", &n);
        printf("%.4f\n", 1 - f[n >> 1]);
    }
    return 0;
}
