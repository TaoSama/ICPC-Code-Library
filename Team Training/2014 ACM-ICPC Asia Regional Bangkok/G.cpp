//
//  Created by TaoSama on 2015-12-12
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, a[N][N];
bool ans[N][N];

void setMine(int i, int j) {
    ans[i][j] = true;
    a[i][j] -= 3;
}

void delLastColumn(int i, int j) {
    a[i][j] -= ans[i][j - 1];
    if(i < n) a[i][j] -= ans[i + 1][j - 1];
}

void see(int i, int j) {
    printf("a[%d][%d] = %d ans: %d\n", i, j, a[i][j], ans[i][j]);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        memset(a, 0, sizeof a);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                scanf("%d", &a[i][j]);

        memset(ans, false, sizeof ans);
        for(int i = 1; i <= n; i += 2) {
            for(int j = 1; j <= m; ++j) //delete last line
                a[i][j] -= ans[i - 1][j - 1] + ans[i - 1][j] + ans[i - 1][j + 1];

            //is mine
            if(a[i][1] > 3) setMine(i, 1);
            //only 2 left
            if(a[i + 1][1] - a[i][1] > 2) setMine(i + 1, 1);

            for(int j = 2; j <= m; ++j) {
//              see(i, j);
                delLastColumn(i, j);
//              see(i, j);
                if(a[i][j] > 3) setMine(i, j);
                ans[i + 1][j] = a[i][j - 1] - ans[i][j - 1] - ans[i + 1][j - 1] - ans[i][j];
            }
        }

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j)
                putchar("-L"[ans[i][j]]);
            puts("");
        }
    }
    return 0;
}
