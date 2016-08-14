//
//  Created by TaoSama on 2016-08-11
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
int n;
LL f[N][N]; //f[i][j]:= 1~i
const LL invTwo = 500000004;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);

        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for(int i = 1; i <= n; ++i) {
            int d; scanf("%d", &d);
            if(i == 1) d = 1;
            if(i == n) d = 0;



        }

        static int kase = 0;
        printf("Case #%d: %I64d\n", ++kase, ans);
    }

    return 0;
}
