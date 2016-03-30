//
//  Created by TaoSama on 2016-02-04
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
const int N = 3e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
int n, k, a[N];
LL f[5005][5005];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &k) == 2) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        sort(a + 1, a + 1 + n);
        int len = n / k, large = n % k, small = k - large;
        memset(f, 0x3f, sizeof f);
        f[0][0] = 0;
        for(int i = 0; i <= large; ++i) {
            for(int j = 0; j <= small; ++j) {
                int st = i * (len + 1) + j * len + 1;
                if(i < large) {
                    int largeCost = a[st + len] - a[st];
                    f[i + 1][j] = min(f[i + 1][j], f[i][j] + largeCost);
                }
                if(j < small) {
                    int smallCost = a[st + len - 1] - a[st];
                    f[i][j + 1] = min(f[i][j + 1], f[i][j] + smallCost);
                }
            }
        }
        printf("%I64d\n", f[large][small]);
    }
    return 0;
}
