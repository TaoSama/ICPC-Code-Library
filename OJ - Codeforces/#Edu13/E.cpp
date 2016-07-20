//
//  Created by TaoSama on 2016-06-14
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
const int N = 18, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
double p[N][N], f[N][1 << N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%lf", p[i] + j);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < 1 << n; ++j)
			if(j == (1 << i)) f[i][j] = 1;
			else f[i][j] = 0;

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < 1 << n; ++j){
			printf("f[%d][%d] = %.5f\n", i, j, f[i][j]);
			for(int k = 0; k < n; ++k){
				if(j >> k & 1) continue;
				f[i][j | 1 << k] += f[i][j] * p[i][k];
				f[k][j | 1 << k] += f[i][j] * p[k][i];
			}
		}
	}
	printf("%.12f\n", f[1][(1 << n) - 1]);

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
