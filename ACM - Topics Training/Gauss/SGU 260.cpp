//
//  Created by TaoSama on 2016-07-28
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
const int N = 200 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int a[N][N], b[N][N], ans[N];

int xorGauss() {
    int r = 0, c = 0;
    for(; r < n && c < n; ++r, ++c) {
        int p = r;
        for(; p < n; ++p) if(a[p][c]) break;
        if(p == n) {--r; continue;}
        swap(a[p], a[r]);

        for(int i = 0; i < n; ++i) {
            if(i != r && a[i][c]) {
                for(int j = c; j <= n; ++j)
                    a[i][j] ^= a[r][j];
            }
        }
    }
    for(int i = r; i < n; ++i) if(a[i][n]) return -1;

    //memset(ans, 0, sizeof ans);  //not necessary
    for(int i = r - 1; ~i; --i)
        for(int j = 0; j < n; ++j)
            if(a[i][j]) {ans[j] = a[i][n]; break;}
    return r;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int k; scanf("%d", &k);
        while(k--) {
            int x; scanf("%d", &x);
            --x;
            b[x][i] = a[x][i] = 1;
        }
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", a[i] + n);
        b[i][n] = a[i][n] ^ 1;
    }

    vector<int> v;
    int r = xorGauss();
    if(~r) {
        for(int i = 0; i < n; ++i) if(ans[i]) v.push_back(i + 1);
        printf("%d\n", v.size());
        for(int i = 0; i < v.size(); ++i)
            printf("%d%c", v[i], " \n"[i == v.size() - 1]);
    } else {
        memcpy(a, b, sizeof b);
        int r = xorGauss();
        if(~r) {
            for(int i = 0; i < n; ++i) if(ans[i]) v.push_back(i + 1);
            printf("%d\n", v.size());
            for(int i = 0; i < v.size(); ++i)
                printf("%d%c", v[i], " \n"[i == v.size() - 1]);
        } else puts("-1");
    }


#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
