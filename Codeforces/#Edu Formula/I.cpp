//
//  Created by TaoSama on 2016-02-23
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
long long f[100][2];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    f[0][0] = 1;
    for(int i = 1; i <= 2 * n - 2; ++i) {
        if(i >= n) f[i][1] += (i == n ? 4 : 3) * f[i - n][0];
        for(int j = 1; j <= i && j <= n; ++j) {
            f[i][0] += (i == j ? 4 : 3) * f[i - j][0];
            f[i][1] += (i == j ? 4 : 3) * f[i - j][1];
        }
//        printf("f[%d][%d] = %I64d, f[%d][%d] = %I64d\n",
//               i, 0, f[i][0], i, 1, f[i][1]);
    }
    printf("%I64d\n", f[2 * n - 2][1]);
    return 0;
}
