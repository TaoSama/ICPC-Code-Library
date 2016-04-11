//
//  Created by TaoSama on 2015-09-25
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

int n;
int ans[805][805], A[805][805], B[805][805];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                scanf("%d", &A[i][j]), A[i][j] %= 3;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                scanf("%d", &B[i][j]), B[i][j] %= 3;

        memset(ans, 0, sizeof ans);
        for(int k = 1; k <= n; ++k) {
            for(int i = 1; i <= n; ++i) {
                if(A[i][k] == 0) continue;
                for(int j = 1; j <= n; ++j)
                    ans[i][j] += A[i][k] * B[k][j];
            }
        }
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                printf("%d%c", ans[i][j] % 3, " \n"[j == n]);
    }
    return 0;
}
