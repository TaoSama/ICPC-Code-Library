//
//  Created by TaoSama on 2016-01-23
//  Copyright (c) 2015 TaoSama. All rights reserved.
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

int n, a[105];
long long dp[105];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

	while(scanf("%d", &n) == 1){
		for(int i = 1; i <= n; ++i){
			int x; scanf("%d", &x);
			a[i] = a[i - 1] + x;
		}
		memset(dp, 0, sizeof dp);
		dp[0] = 1;
		for(int i = 1; i <= n; ++i){
			for(int j = 0; j < i; ++j){
				if(a[i] - a[j] == 1) dp[i] += dp[j];
			}
		}
		printf("%I64d\n", dp[n]);
	}
    return 0;
}
