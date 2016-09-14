//
//  Created by TaoSama on 2016-09-14
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
const int N = 3e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N], b[N];
typedef long long LL;
LL f[2][N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

	while(cin >> n){
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			a[i] -= i;
			b[i] = a[i];
		}
		sort(b + 1, b + 1 + n);
//		for(int i = 1; i <= n; ++i) b[i] -= i;
//		for(int i = 1; i <= n; ++i) cout << b[i] << ' '; cout << endl;
		int p = 0;
        memset(f[p], 0, sizeof f[p]);
        for(int i = 1; i <= n; ++i) {
            memset(f[!p], 0, sizeof f[!p]);
            for(int j = 1; j <= n; ++j)
                f[!p][j] = f[p][j] + abs(a[i] - b[j]);
            for(int j = 2; j <= n; ++j)
                f[!p][j] = min(f[!p][j], f[!p][j - 1]);
            p = !p;
        }
        cout << f[p][n] << endl;
	}

    return 0;
}
