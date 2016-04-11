//
//  Created by TaoSama on 2015-12-05
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

typedef long long LL;
const LL INFLL = 0x3f3f3f3f3f3f3f3fLL;

int n, A, B;
int r[155], s[155];
LL f[155][155];

void getMax(LL &x, LL y) {
    if(y > x) x = y;
}

void getMin(LL &x, LL y) {
    if(y < x) x = y;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &A, &B) == 3) {
        for(int i = 1; i <= n; ++i) scanf("%d%d", r + i, s + i);

        memset(f, 0x3f, sizeof f);
        f[n][s[n]] = -INFLL;
        int sum = s[n];
        for(int i = n - 1; i; --i) {
            sum += s[i];
            for(int j = sum; j >= s[i]; --j) {
                f[i][j] = -INFLL;
                for(int k = sum - j + 1; k <= sum; ++k)
                    getMax(f[i][j], -f[i + 1][k] - r[i] + 1);
                for(int k = j; k <= sum; ++k)
                    getMin(f[i][j], max(f[i + 1][k] + r[i] + 1, 1LL));
            }
        }

        for(int i = sum; ~i; --i) {
            if(f[1][i] <= A - B) {
                printf("%d %d\n", i, sum - i);
                break;
            }
        }
    }
    return 0;
}
