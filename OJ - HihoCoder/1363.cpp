//
//  Created by TaoSama on 2016-08-21
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
const int N = 60 * 60 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 5 * 5 + 10;

const double EPS = 1e-8;
int sgn(double x) {
    return x < -EPS ? -1 : x > EPS;
}

double a[N][M], ans[M];
bool isFreeX[M];

void getAns(int n, int m, int r) {
    memset(ans, 0, sizeof ans);
    for(int i = r - 1; ~i; --i) {
        for(int j = 0; j < m; ++j) {
            if(!sgn(a[i][j])) continue;
            ans[j] = a[i][m];
            for(int k = j + 1; k < m; ++k)
                ans[j] -= a[i][k] * ans[k];
            ans[j] = ans[j] / a[i][j];
            break;
        }
    }
}

int gauss(int n, int m) {
    for(int i = 0; i < m; ++i) isFreeX[i] = false;
    int r = 0, c = 0;
    for(; r < n && c < m; ++r, ++c) {
        int maxR = r;       //row transform
        for(int i = r + 1; i < n; ++i)
            if(abs(a[i][c]) > abs(a[maxR][c])) maxR = i;
        if(maxR != r) swap(a[maxR], a[r]);

        if(!sgn(a[r][c])) { --r; isFreeX[c] = true; continue;}

        //eliminate coefficient
        for(int i = r + 1; i < n; ++i) {
            if(sgn(a[i][c])) {
                double delta = a[i][c] / a[r][c];
                for(int j = c; j <= m; ++j)
                    a[i][j] -= delta * a[r][j];
            }
        }
    }
    for(int i = r; i < n; i++) if(sgn(a[i][m])) return -1;

    getAns(n, m, r);

    //at last, r is rank, m - r is the number of freeX
    return r;
}

int A[65][65], B[65][65];
int h, w, d;

int ID(int i, int j) {
    return i * (w - d + 1) + j;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d%d", &h, &w, &d);
    for(int i = 0; i < h; ++i)
        for(int j = 0; j < w; ++j)
            scanf("%d", A[i] + j);
    for(int i = 0; i < h - d + 1; ++i) {
        for(int j = 0; j < w - d + 1; ++j) {
            scanf("%d", B[i] + j);
            int lft = ID(i, j);
            for(int dx = 0; dx < d; ++dx) {
                for(int dy = 0; dy < d; ++dy) {
                    a[lft][dx * d + dy] = A[i + dx][j + dy];
                }
            }
            a[lft][d * d] = B[i][j];
        }
    }
    gauss((h - d + 1) * (w - d + 1), d * d);
    for(int i = 0; i < d * d; ++i) {
        if(i) printf("%c", " \n"[i % d == 0]);
        printf("%.0f", ans[i] + EPS);
    }
    puts("");

    return 0;
}
