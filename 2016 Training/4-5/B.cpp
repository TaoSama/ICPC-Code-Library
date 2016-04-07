//
//  Created by TaoSama on 2016-04-05
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
typedef long long LL;
LL f[2][45][45];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &k);

        int p = 0;
        memset(f[p], 0, sizeof f[p]);
        f[p][1][0] = 1;
        for(int i = 1; i <= 2 * n; ++i) {
            memset(f[!p], 0, sizeof f[!p]);
            for(int j = 1; j <= 2 * n + 1; ++j) {
                for(int l = 0; l <= 2 * k - 1; ++l) { //0->right 1->left
                    if(l & 1) f[!p][j][l] = f[p][j + 1][l] + (l ? f[p][j + 1][l - 1] : 0);
                    else f[!p][j][l] = f[p][j - 1][l] + (l ? f[p][j - 1][l - 1] : 0);
                }
            }
            p = !p;
        }
        printf("%lld\n", f[p][1][2 * k - 1]);
    }
    return 0;
}
